#include <iostream>
#include <thread>

#include <curl/curl.h>

static size_t WriteCallback(void* contents, size_t size, size_t nmemb, void* userp)
{
    ((std::string*)userp)->append((char*)contents, size * nmemb);
    return size * nmemb;
}

void func() {
	CURL* curl = curl_easy_init();

	if (curl) {
		std::string readBuffer;

		curl_easy_setopt(curl, CURLOPT_URL, "http://www.google.com");
		curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, WriteCallback);
		curl_easy_setopt(curl, CURLOPT_WRITEDATA, &readBuffer);
		CURLcode res = curl_easy_perform(curl);
		
		if(res != CURLE_OK) {
			std::cerr << "curl_easy_perform() failed: " << curl_easy_strerror(res) << std::endl;
		} else {
			std::cout << readBuffer << std::endl;
		}

		curl_easy_cleanup(curl);
	}
}

int main() {
	//curl_global_init(CURL_GLOBAL_DEFAULT);
	
	std::cout << "Hello, world!" << std::endl;

	std::thread t(func);
	t.join();

	return 0;
}
