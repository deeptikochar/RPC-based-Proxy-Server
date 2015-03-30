
#include <iostream>
#include "fifo_cache.h"

fifo_cache::fifo_cache()
{
	MAX_SIZE = CACHE_MAX_SIZE;
	size = 0;
}

fifo_cache::fifo_cache(int max)
{
	MAX_SIZE = max;
	size = 0;
}

void fifo_cache::cache_set_max(int max)
{
	MAX_SIZE = max;
}

int fifo_cache::cache_isFull(int data_size)
{
	if(size + data_size > MAX_SIZE)
		return 1;

	return 0;
}

int fifo_cache::cache_find(string url)
{
	//Check if url is a key in the map
	if(dictionary.count(url) == 0)
		return 0;
	return 1;
}

int fifo_cache::cache_fetch(string url, string &value)
{
	if(cache_find(url))
	{
		value = dictionary[url];
		return 1;
	}
	return 0;
}

int fifo_cache::cache_insert(string url, string value)
{
	int data_size = value.length();
	if(data_size > MAX_SIZE)
		return 0;
	while(cache_isFull(data_size))
	{
		cache_remove(cache_decideReplace());
	}

	dictionary[url] = value;
	size = size + data_size;
	fifo_queue.push(url);
	return 1;
}

int fifo_cache::cache_remove(string url)
{
	string temp;
	if(cache_fetch(url, temp) == 0)
		return 0;
	size = size - temp.length();
	dictionary.erase(url);
	fifo_queue.pop();
	return 1;
}

string fifo_cache::cache_decideReplace()
{
	return fifo_queue.front();
}
