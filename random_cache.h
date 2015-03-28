#ifndef random_cache_H
#define random_cache_H

#include <string>
#include <map>
#include "wd_in.h"

using namespace std;

class random_cache
{ 
	// Later change to private for vars
	int num_entries;
	int MAX_SIZE;
	int size;
	std::map<string, wd_in> dictionary;
	std::map<int, string> urls;

	public:
	random_cache();
	random_cache(int max);

	int cache_fetch(string url, wd_in *value);		// Returns 1 if found and sets value accordingly, 0 if not present.
	int cache_insert(string url, wd_in value);		// Returns 1 if successful, 0 if not

	private:
	int cache_isFull(int data_size);						// Returns 1 if full, 0 if not
	int cache_find(string url);                         	// Returns 1 if found, 0 if not	
	int cache_remove(int index);							// Returns 1 if successful. 0 if not
	int cache_decideReplace();								// Decides which cache entry to replace
};

#endif