#ifndef lru_queue_H
#define lru_queue_H

#include <string>

using namespace std;

struct queue_element
{
	string url;
	string data;
	queue_element *prev;
	queue_element *next;
	queue_element()
	{
		prev = NULL;
		next = NULL;
	};
};

class queue
{
	queue_element *head;
	queue_element *tail;

	public:
	queue();
	int front_size();
	string front_url();
	void push(queue_element *node);
	void pop();
	int send_to_end(queue_element *node);
};

#endif