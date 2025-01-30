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

std::string strToString(jule::Str str) {
    std::string result = "";
    for (jule::U8& c : str) {
        result += c;
    }
    return result;
}

struct curl_slist* sliceToSlist(const jule::Slice<jule::Str> headersSlice) {
    struct curl_slist* headers = NULL;
    const int headersLen = headersSlice.len();
    for (size_t i = 0; i < headersLen; i += 2) {
        if (i + 1 < headersLen) {
            std::string header = strToString(headersSlice[i]) + ": " + strToString(headersSlice[i + 1]);
            headers = curl_slist_append(headers, header.c_str());
        }
    }
    return headers;
}

struct Response {
    jule::Str body;
    jule::Int status;
};

Response request(const char *url, const jule::Slice<jule::Str> headers, const jule::Int method) {
    CURL* curl;
    CURLcode res;
    std::string readBuffer;

    Response response;
    struct curl_slist* headersList = sliceToSlist(headers);

    curl = curl_easy_init();
    if (!curl) {
        response.status = 418;
        return response;
    }

    curl_easy_setopt(curl, CURLOPT_URL, url);
    curl_easy_setopt(curl, CURLOPT_HTTPHEADER, headersList);

    if (method == 0) { // GET
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, WriteCallback);
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, &readBuffer);
    } else if (method == 1) { // HEAD
        curl_easy_setopt(curl, CURLOPT_NOBODY, 1L);
    }

    res = curl_easy_perform(curl);
    curl_easy_getinfo(curl, CURLINFO_RESPONSE_CODE, &response.status);
    curl_easy_cleanup(curl);

    if (method == 0) { // GET
        response.body = readBuffer;
    }

    return response;
}

Response post(const char *url, const char *data, const jule::Slice<jule::Str> headers, const jule::Int method) {
    CURL* curl;
    CURLcode res;
    std::string readBuffer;

    Response response;
    struct curl_slist* headersList = sliceToSlist(headers);

    curl = curl_easy_init();
    if (!curl) {
        response.status = 418;
        return response;
    }

    curl_easy_setopt(curl, CURLOPT_URL, url);
    curl_easy_setopt(curl, CURLOPT_HTTPHEADER, headersList);

    if (method == 0) { // POST
        curl_easy_setopt(curl, CURLOPT_POST, 1L);
    } else if (method == 1) { // PUT
        curl_easy_setopt(curl, CURLOPT_CUSTOMREQUEST, "PUT");
    } else if (method == 2) { // DELETE
        curl_easy_setopt(curl, CURLOPT_CUSTOMREQUEST, "DELETE");
    }

    if (data) {
        curl_easy_setopt(curl, CURLOPT_POSTFIELDS, data);
    }
    curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, WriteCallback);
    curl_easy_setopt(curl, CURLOPT_WRITEDATA, &readBuffer);

    res = curl_easy_perform(curl);
    curl_easy_getinfo(curl, CURLINFO_RESPONSE_CODE, &response.status);
    curl_easy_cleanup(curl);

    response.body = readBuffer;

    return response;
}

bool download(jule::Str url, jule::Str filename) {
    CURL* curl = curl_easy_init();
    if (!curl) {
        return false;
    }

    FILE* file = fopen(strToString(filename).c_str(), "wb");
    if (!file) {
        return false;
    }

    curl_easy_setopt(curl, CURLOPT_URL, strToString(url).c_str());
    curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, WriteFileCallback);
    curl_easy_setopt(curl, CURLOPT_WRITEDATA, file);

    curl_easy_setopt(curl, CURLOPT_FOLLOWLOCATION, 1L);

    curl_easy_perform(curl);

    fclose(file);
    curl_easy_cleanup(curl);

    return true;
}

#endif // CURLWRAPPER_HPP
