#ifndef fifo_cache_H
#define fifo_cache_H

#ifndef CACHE_MAX_SIZE
#define CACHE_MAX_SIZE 1048576
#endif

#include <string>
#include <map>
#include <queue>

using namespace std;

class fifo_cache
{ 
	int MAX_SIZE;
	int size;
	std::map<string, string> dictionary;
	std::queue<string> fifo_queue;

	public:
	fifo_cache();
	fifo_cache(int max);

	void cache_set_max(int max);					// Sets maximum cache size
	int cache_fetch(string url, string &value);		// Returns 1 if found and sets value accordingly, 0 if not present.
	int cache_insert(string url, string value);		// Returns 1 if successful, 0 if not

	private:
	int cache_isFull(int data_size);
	int cache_find(string url);                         	// Returns 1 if found, 0 if not
	int cache_remove(string url);							// Returns 1 if successful. 0 if not
	string cache_decideReplace();
};

#endif