#include <iostream>
#include <thread>
#include <chrono>

#include <curl/curl.h>

#include "thread.hpp"

int main() {
	auto t_start = std::chrono::high_resolution_clock::now();
	curl_global_init(CURL_GLOBAL_DEFAULT);

	auto url = "http://localhost:5000";
	auto thread_pool_size = 100;
	int min_id = 1;
	int max_id = 1000;

	auto threads = new std::thread[thread_pool_size];
	auto thread_args = new thread_args_t[thread_pool_size];

	for (int i = 0; i < thread_pool_size; i++) {
		thread_args[i].url = url;
		thread_args[i].start_index = min_id + i;
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

	auto t_end = std::chrono::high_resolution_clock::now();
	double elapsed_time_ms = std::chrono::duration<double, std::milli>(t_end - t_start).count();

	std::cout << "Run time: " << elapsed_time_ms / 1000 << " sec." << std::endl;

	return 0;
}
