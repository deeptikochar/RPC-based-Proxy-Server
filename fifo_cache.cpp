
#include <iostream>
#include "fifo_cache.h"

fifo_cache::fifo_cache()
{
	MAX_SIZE = 1024;
	size = 0;
}

fifo_cache::fifo_cache(int max)
{
	MAX_SIZE = max;
	size = 0;
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

int fifo_cache::cache_fetch(string url, wd_in *value)
{
	if(cache_find(url))
	{
		wd_in val = dictionary.find(url)->second;
		value->size = val.size;
		value->len = val.len;
		value->data = val.data;
		return 1;
	}
	return 0;
}

int fifo_cache::cache_insert(string url, wd_in value)
{
	if(value.size > MAX_SIZE)
		return 0;
	while(cache_isFull(value.size))
	{
		cache_remove(cache_decideReplace());
	}

	dictionary[url] = value;
	size = size + value.size;
	fifo_queue.push(url);
	return 1;
}

int fifo_cache::cache_remove(string url)
{
	wd_in temp;
	if(cache_fetch(url, &temp) == 0)
		return 0;
	size = size - temp.size;
	dictionary.erase(url);
	int i;
	fifo_queue.pop();
	return 1;
}

string fifo_cache::cache_decideReplace()
{
	return fifo_queue.front();
}

int main(int argc, char const *argv[])
{
	// fifo_cache r(100);
	// const string url1 = "url1";
	// const string url2 = "url2";
	// const string url3 = "url3";
	// struct wd_in elem1;
	// struct wd_in elem2;
	// struct wd_in elem3;
	// elem1.size = 30;
	// elem2.size = 3;
	// elem3.size = 83;
	// elem1.data = "data1";
	// elem2.data = "data2";
	// elem3.data = "data3";
	// elem1.len = 30;
	// elem2.len = 30;
	// elem3.len = 80;
	// struct wd_in return_elem;
	// cout<<"Cache find (initial):"<<r.cache_find(url1)<<endl;
	// if(r.cache_insert(url1, elem1))
	// 	cout<<"Cache find (1):"<<r.cache_find(url1)<<endl;
	// cout<<"Cache find (2):"<<r.cache_find(url2)<<endl;
	// if(r.cache_fetch(url1, &return_elem))
	// 	cout<<"Success";
	// cout<<endl<<return_elem.size<<"\t"<<return_elem.len<<"\t"<<return_elem.data<<endl;
	// if(r.cache_insert(url2, elem2))
	// 	cout<<"Cache find (3):"<<r.cache_find(url2)<<endl;
	// if(r.cache_insert(url3, elem3))
	// {
	// 	cout<<"Inserted url3"<<endl;
	// 	cout<<"Is url1 present: "<<r.cache_find(url1)<<endl;
	// 	cout<<"Is url2 present: "<<r.cache_find(url2)<<endl;
	// 	cout<<"Is url3 present: "<<r.cache_find(url3)<<endl;
	// }
	// // string remove_url = r.cache_decideReplace();
	// // cout<<remove_url<<endl;
	// // r.cache_remove(remove_url);
	// // cout<<"Removed url is present? "<<r.cache_find(remove_url)<<endl;

	return 0;
}