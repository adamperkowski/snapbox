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

getResponse get(const std::string& url, jule::Slice<jule::Str> headers, jule::Int headersLen) {
    CURL* curl;
    CURLcode res;
    std::string readBuffer;

    getResponse response;
    struct curl_slist* headersList = sliceToSlist(headers, headersLen);

    curl = curl_easy_init();
    if (curl) {
        curl_easy_setopt(curl, CURLOPT_URL, url.c_str());
        curl_easy_setopt(curl, CURLOPT_HTTPHEADER, headersList);
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, WriteCallback);
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, &readBuffer);

        res = curl_easy_perform(curl);
        curl_easy_getinfo(curl, CURLINFO_RESPONSE_CODE, &response.status);
        curl_easy_cleanup(curl);

        response.body = readBuffer;
    } else {
        response.status = 418;
    }

    return response;
}

#endif // CURLWRAPPER_HPP
