// snapbox
// HTTP Client Library for Jule
// https://github.com/adamperkowski/snapbox
// Copyright (c) 2025, Adam Perkowski
// BSD 3-Clause License

#ifndef CURLWRAPPER_HPP
#define CURLWRAPPER_HPP

#include <string>
#include <curl/curl.h>

size_t WriteCallback(void* contents, size_t size, size_t nmemb, std::string* userp) {
    userp->append((char*)contents, size * nmemb);
    return size * nmemb;
}

size_t WriteFileCallback(void* ptr, size_t size, size_t nmemb, FILE* stream) {
    return fwrite(ptr, size, nmemb, stream);
}

struct curl_slist* sliceToSlist(const jule::Slice<jule::Str> headersSlice, jule::Int headersLen) {
    struct curl_slist* headers = NULL;
    for (size_t i = 0; i < headersLen; i += 2) {
        if (i + 1 < headersLen) {
            std::string header = headersSlice[i] + ": " + headersSlice[i + 1];
            headers = curl_slist_append(headers, header.c_str());
        }
    }
    return headers;
}

struct getResponse {
    std::string body;
    int status;
};

getResponse get(const std::string& url, jule::Slice<jule::Str> headers, jule::Int headersLen, bool isHead) {
    CURL* curl;
    CURLcode res;
    std::string readBuffer;

    getResponse response;
    struct curl_slist* headersList = sliceToSlist(headers, headersLen);

    curl = curl_easy_init();
    if (!curl) {
        response.status = 418;
        return response;
    }

    curl_easy_setopt(curl, CURLOPT_URL, url.c_str());
    curl_easy_setopt(curl, CURLOPT_HTTPHEADER, headersList);

    if (isHead) {
        curl_easy_setopt(curl, CURLOPT_NOBODY, 1L);
    } else {
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, WriteCallback);
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, &readBuffer);
    }

    res = curl_easy_perform(curl);
    curl_easy_getinfo(curl, CURLINFO_RESPONSE_CODE, &response.status);
    curl_easy_cleanup(curl);

    if (!isHead) {
        response.body = readBuffer;
    }

    return response;
}

getResponse post(const std::string& url, const std::string& data, jule::Slice<jule::Str> headers, jule::Int headersLen, bool isPut) {
    CURL* curl;
    CURLcode res;
    std::string readBuffer;

    getResponse response;
    struct curl_slist* headersList = sliceToSlist(headers, headersLen);

    curl = curl_easy_init();
    if (!curl) {
        response.status = 418;
        return response;
    }

    curl_easy_setopt(curl, CURLOPT_URL, url.c_str());
    curl_easy_setopt(curl, CURLOPT_HTTPHEADER, headersList);

    if (isPut) {
        curl_easy_setopt(curl, CURLOPT_CUSTOMREQUEST, "PUT");
    } else {
        curl_easy_setopt(curl, CURLOPT_POST, 1L);
    }

    curl_easy_setopt(curl, CURLOPT_POSTFIELDS, data.c_str());
    curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, WriteCallback);
    curl_easy_setopt(curl, CURLOPT_WRITEDATA, &readBuffer);

    res = curl_easy_perform(curl);
    curl_easy_getinfo(curl, CURLINFO_RESPONSE_CODE, &response.status);
    curl_easy_cleanup(curl);

    response.body = readBuffer;

    return response;
}

bool download(const std::string& url, const std::string& filename) {
    CURL* curl = curl_easy_init();
    if (!curl) {
        return false;
    }

    FILE* file = fopen(filename.c_str(), "wb");
    if (!file) {
        return false;
    }

    curl_easy_setopt(curl, CURLOPT_URL, url.c_str());
    curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, WriteFileCallback);
    curl_easy_setopt(curl, CURLOPT_WRITEDATA, file);

    curl_easy_setopt(curl, CURLOPT_FOLLOWLOCATION, 1L);

    curl_easy_perform(curl);

    fclose(file);
    curl_easy_cleanup(curl);

    return true;
}

#endif // CURLWRAPPER_HPP
