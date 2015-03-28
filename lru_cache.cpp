
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

int lru_cache::cache_isFull(int data_size)
{
	if(size + data_size > MAX_SIZE)
		return 1;

	return 0;
}

int lru_cache::cache_find(string url)
{
	//Check if url is a key in the map
	if(dictionary.count(url) == 0)
		return 0;
	return 1;
}

int lru_cache::cache_fetch(string url, wd_in *value)
{
	if(cache_get(url, value))
	{
		lru_queue.send_to_end(queue_ptrs[url]);
		return 1;
	}
	return 0;
}

int lru_cache::cache_insert(string url, wd_in value)
{
	if(value.size > MAX_SIZE)
		return 0;
	while(cache_isFull(value.size))
	{
		cache_remove(cache_decideReplace());
	}
	char *data;
	strcpy(data, value.data);
	value.data = data;
	dictionary[url] = value;
	size = size + value.size;
	queue_element *ptr = new queue_element();
	ptr->url = url;
	lru_queue.push(ptr);
	queue_ptrs[url] = ptr;
	return 1;
}

int lru_cache::cache_get(string url, wd_in *value)
{
	if(cache_find(url))
	{
		wd_in val = dictionary[url];
		value->size = val.size;
		value->len = val.len;
		value->data = val.data;
		return 1;
	}
	return 0;
}

int lru_cache::cache_remove(string url)
{
	wd_in temp;
	if(cache_get(url, &temp) == 0)
		return 0;
	size = size - temp.size;
	dictionary.erase(url);
	int i;
	lru_queue.pop();
	return 1;
}

string lru_cache::cache_decideReplace()
{
	return lru_queue.front();
}

int main(int argc, char const *argv[])
{
	// lru_cache r(100);
	// string url1 = "url1";
	// string url2 = "url2";
	// string url3 = "url3";
	// struct wd_in elem1;
	// struct wd_in elem2;
	// struct wd_in elem3;
	// elem1.size = 30;
	// elem2.size = 30;
	// elem3.size = 50;
	// elem1.data = "string1";
	// elem2.data = "string2";
	// elem3.data = "string3";
	// elem1.len = 1;
	// elem2.len = 5;
	// elem3.len = 45;
	// struct wd_in return_elem;
	// cout<<"Cache find (initial):"<<r.cache_find(url1)<<endl;
	// if(r.cache_insert(url1, elem1))
	// 	cout<<"Cache find (1):"<<r.cache_find(url1)<<endl;
	// cout<<"Cache front and back: "<<r.lru_queue.front()<<"\t"<<r.lru_queue.tail->url<<endl;
	// if(r.cache_insert(url2, elem2))
	// 	cout<<"Cache find (2):"<<r.cache_find(url2)<<endl;
	// cout<<"Cache front and back: "<<r.lru_queue.front()<<"\t"<<r.lru_queue.tail->url<<endl;
	// r.cache_fetch(url1, &return_elem);
	// if(r.cache_insert(url3, elem3))
	// {
	// 	cout<<"Inserted url3"<<endl;
	// 	cout<<"Is url1 present: "<<r.cache_find(url1)<<endl;
	// 	cout<<"Is url2 present: "<<r.cache_find(url2)<<endl;
	// 	cout<<"Is url3 present: "<<r.cache_find(url3)<<endl;
	// }
	
	// if(r.cache_fetch(url1, &return_elem))
	//  	cout<<"Success";
	// cout<<endl<<return_elem.size<<"\t"<<return_elem.len<<"\t"<<return_elem.data<<endl;
	// cout<<r.lru_queue.front()<<endl;
	// if(r.cache_fetch(url3, &return_elem))
	// 	cout<<"Success";
	// cout<<endl<<return_elem.size<<"\t"<<return_elem.len<<"\t"<<return_elem.data<<endl;
	// cout<<"Cache front and back: "<<r.lru_queue.front()<<"\t"<<r.lru_queue.tail->url<<endl;
	// // if(r.cache_insert(url2, elem2))
	// // 	cout<<"Cache find (3):"<<r.cache_find(url2)<<endl;
	// string remove_url = r.cache_decideReplace();
	// cout<<remove_url<<endl;
	// r.cache_remove(remove_url);
	// cout<<"Removed url is present? "<<r.cache_find(remove_url)<<endl;
	// cout<<"Cache front and back: "<<r.lru_queue.front()<<"\t"<<r.lru_queue.tail->url<<endl;
	// remove_url = r.cache_decideReplace();
	// cout<<remove_url<<endl;
	// r.cache_remove(remove_url);
	// cout<<"Removed url is present? "<<r.cache_find(remove_url)<<endl;
	// cout<<"Cache front and back: "<<r.lru_queue.front()<<"\t"<<r.lru_queue.tail->url<<endl;
	// remove_url = r.cache_decideReplace();
	// cout<<remove_url<<endl;
	// r.cache_remove(remove_url);
	// cout<<"Removed url is present? "<<r.cache_find(remove_url)<<endl;
	// cout<<"Cache front and back: "<<r.lru_queue.front();//<<"\t"<<r.lru_queue.tail->url<<endl;
	return 0;
}