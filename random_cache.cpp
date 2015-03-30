#include <stdlib.h>
#include <time.h>
#include <iostream>
#include "random_cache.h"

random_cache::random_cache()
{
	num_entries = 0;
	size = 0;
	MAX_SIZE = CACHE_MAX_SIZE;
	MAX_NUM_ENTRIES = CACHE_MAX_SIZE/MIN_FILE_SIZE;
	urls = new string[MAX_NUM_ENTRIES];
	srand(time(NULL));
}

random_cache::random_cache(size_t max)
{
	num_entries = 0;
	size = 0;
	MAX_SIZE = max;
	MAX_NUM_ENTRIES = max/MIN_FILE_SIZE;
	urls = new string[MAX_NUM_ENTRIES];
	srand(time(NULL));
}

void random_cache::cache_set_max(int max)
{
	MAX_SIZE = max;
	MAX_NUM_ENTRIES = max/MIN_FILE_SIZE;
	delete [] urls;
	urls = new string[MAX_NUM_ENTRIES];
}

int random_cache::cache_isFull(size_t data_size)
{
	if(size + data_size > MAX_SIZE)
		return 1;

	return 0;
}

int random_cache::cache_find(string url)
{
	//Check if url is a key in the map. Returns 0 or 1
	if(dictionary.count(url) == 0)
		return 0;
	return 1;
}

int random_cache::cache_fetch(string url, string &value)
{
	if(cache_find(url))
	{
		value = dictionary[url];
		return 1;
	}
	return 0;
}

int random_cache::cache_insert(string url, string value)
{
	size_t data_size = value.length();
	if(data_size > MAX_SIZE || num_entries == MAX_NUM_ENTRIES)
		return 0;
	while(cache_isFull(data_size))
	{
		cache_remove(cache_decideReplace());
	}
	dictionary[url] = value;
	size = size + data_size;
	urls[num_entries] = url;
	num_entries++;
	return 1;

}

int random_cache::cache_remove(int index)
{
	string url = urls[index];
	string temp;
	if(cache_fetch(url, temp) == 0)
		return 0;
	size = size - temp.length();
	
	dictionary.erase(url);
	urls[index] = urls[num_entries-1];
	num_entries--;
	return 1;
}

int random_cache::cache_decideReplace()
{
	int index = rand() % num_entries;
	return index;
}
