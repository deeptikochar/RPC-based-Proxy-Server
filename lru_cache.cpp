
#include <iostream>
#include "lru_cache.h"

using namespace std;

lru_cache::lru_cache()
{
	MAX_SIZE = CACHE_MAX_SIZE;
	size = 0;
}

lru_cache::lru_cache(int max)
{
	MAX_SIZE = max;
	size = 0;
}

void lru_cache::cache_set_max(int max)
{
	MAX_SIZE = max;
}

int lru_cache::cache_isFull(int data_size)
{
	if(size + data_size > MAX_SIZE)
		return 1;

	return 0;
}

int lru_cache::cache_find(string url)
{
	//Check if url is a key in the map
	if(queue_ptrs.count(url) == 0)
		return 0;
	return 1;
}

int lru_cache::cache_fetch(string url, string &value)
{
	if(cache_find(url))
	{
		queue_element *ptr = queue_ptrs[url];
		value = ptr->data;
		lru_queue.send_to_end(ptr);
		return 1;
	}
	return 0;
}

int lru_cache::cache_insert(string url, string value)
{
	int data_size = value.length();
	if(data_size > MAX_SIZE)
		return 0;
	while(cache_isFull(data_size))
	{
		cache_remove();
	}

	size = size + data_size;
	queue_element *ptr = new queue_element();
	ptr->url = url;
	ptr->data = value;
	lru_queue.push(ptr);
	queue_ptrs[url] = ptr;
	return 1;
}


int lru_cache::cache_remove()
{
	int data_size = lru_queue.front_size();
	string url = lru_queue.front_url();
	size = size - data_size;
	lru_queue.pop();
	queue_ptrs.erase(url);
	return 1;
}