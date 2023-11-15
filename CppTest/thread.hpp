#include <string>

struct thread_args_t {
	int start_index = 0;
	int increment = 0;
	int end_index = 0;
	std::string url = "";
};

void thread_pool_func(thread_args_t* args);