#ifndef random_cache_H
#define random_cache_H

#ifndef CACHE_MAX_SIZE
#define CACHE_MAX_SIZE 1048576
#endif

#define MIN_FILE_SIZE 10000

#include <string>
#include <map>
// #include "wd_in.h"

using namespace std;

class random_cache
{ 
	int num_entries;
	int MAX_NUM_ENTRIES;
	size_t MAX_SIZE;
	size_t size;
	std::map<string, string> dictionary;
	string *urls;

	public:
	random_cache();
	random_cache(size_t max);

	void cache_set_max(int max);							// Sets size of cache
	int cache_fetch(string url, string &value);				// Returns 1 if found and sets value accordingly, 0 if not present.
	int cache_insert(string url, string value);				// Returns 1 if successful, 0 if not

	private:
	int cache_isFull(size_t data_size);						// Returns 1 if full, 0 if not
	int cache_find(string url);                         	// Returns 1 if found, 0 if not	
	int cache_remove(int index);							// Returns 1 if successful. 0 if not
	int cache_decideReplace();								// Decides which cache entry to replace
};

#endif