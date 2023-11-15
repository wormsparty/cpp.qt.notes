#include <iostream>
#include <thread>

#include <curl/curl.h>

#include "thread.hpp"

int main() {
	clock_t tStart = clock();
	curl_global_init(CURL_GLOBAL_DEFAULT);

	auto url = "http://localhost:8080";
	auto thread_pool_size = 1;
	int min_id = 1;
	int max_id = 10;

	auto threads = new std::thread[thread_pool_size];
	auto thread_args = new thread_args_t[thread_pool_size];

	for (int i = 0; i < thread_pool_size; i++) {
		thread_args[i].url = url;
		thread_args[i].start_index = i;
		thread_args[i].increment = thread_pool_size;
		thread_args[i].end_index = max_id;

		threads[i] = std::thread(thread_pool_func, &thread_args[i]);
	}

	for (int i = 0; i < thread_pool_size; i++) {
		threads[i].join();
	}

	delete[] thread_args;
	delete[] threads;

	curl_global_cleanup();
	std::cout << "Run time: " << (double)(clock() - tStart) / CLOCKS_PER_SEC << std::endl;

	return 0;
}
