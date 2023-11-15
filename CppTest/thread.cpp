#include <string>
#include <iostream>
#include <format>

#include <curl/curl.h>

#include "thread.hpp"
#include "base64.hpp"

static size_t append_to_string(void* contents, size_t size, size_t nmemb, void* userp) {
    ((std::string*)userp)->append((char*)contents, size * nmemb);
    return size * nmemb;
}

std::string url_encode(const std::string& value) {
    const auto encoded_value = curl_easy_escape(nullptr, value.c_str(), static_cast<int>(value.length()));
    std::string result(encoded_value);
    curl_free(encoded_value);
    return result;
}

void thread_pool_func(thread_args_t* args) {
    CURL* curl = curl_easy_init();

    if (!curl) {
        std::cerr << "Failed to initialize cURL" << std::endl;
        return;
    }

    std::string response_buffer;

    struct curl_slist* headers = NULL;
    headers = curl_slist_append(headers, "Accept: application/json");
    headers = curl_slist_append(headers, "Content-Type: application/x-www-form-urlencoded");

    curl_easy_setopt(curl, CURLOPT_HTTPHEADER, headers);
    curl_easy_setopt(curl, CURLOPT_URL, args->url.c_str());
    curl_easy_setopt(curl, CURLOPT_SSL_VERIFYPEER, 0L);
    curl_easy_setopt(curl, CURLOPT_SSL_VERIFYHOST, 0L);
    curl_easy_setopt(curl, CURLOPT_SSL_VERIFYSTATUS, 0L);
    curl_easy_setopt(curl, CURLOPT_POST, 1L);    
    curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, append_to_string);
    curl_easy_setopt(curl, CURLOPT_WRITEDATA, &response_buffer);

    for (int user_id = args->start_index; user_id < args->end_index; user_id += args->increment) {
        std::string query = std::format(R"(
            <html>
                <body>
                    <span>Hello, {}!</span>
                </body>
            </html>
        )", args->url, user_id);

        std::string post_data = std::format("Hello={}&Url={}", url_encode(base64::to_base64(query)), url_encode(base64::to_base64(args->url)));

        curl_easy_setopt(curl, CURLOPT_POSTFIELDS, post_data.c_str());
        curl_easy_setopt(curl, CURLOPT_POSTFIELDSIZE, -1L);

        response_buffer.clear();
        CURLcode res = curl_easy_perform(curl);

        if (res != CURLE_OK) {
            std::cerr << "curl_easy_perform() failed: " << curl_easy_strerror(res) << std::endl;
        } else {
            // TODO: Use response_buffer
        }
    }

    curl_slist_free_all(headers);
    curl_easy_cleanup(curl);

    std::cout << "Thread #" << args->start_index << " done." << std::endl;
}
