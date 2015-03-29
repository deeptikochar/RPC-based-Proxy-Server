#ifndef lru_cache_H
#define lru_cache_H

#ifndef CACHE_MAX_SIZE
#define CACHE_MAX_SIZE 1048576
#endif

#include <string>
#include <map>
#include "lru_queue.h"

class lru_cache
{ 
	int MAX_SIZE;
	int size;
	std::map<string, string> dictionary;
	queue lru_queue;
	std::map<string, queue_element*> queue_ptrs;

	public:
	lru_cache();
	lru_cache(int max);

	void cache_set_max(int max);						// Sets size of cache
	int cache_fetch(string url, string &value);			// Returns 1 if found, sets value accordingly and moves to end of queue. Returns 0 if not present.
	int cache_insert(string url, string value);			// Returns 1 if successful, 0 if not

	private:
	int cache_isFull(int data_size);
	int cache_find(string url);                        	// Returns 1 if found, 0 if not
	int cache_get(string url, string &value);			// Returns 1 if found and sets value accordingly, 0 if not present.
	int cache_remove(string url);						// Returns 1 if successful. 0 if not
	string cache_decideReplace();
};

#endif