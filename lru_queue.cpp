#include <iostream>
#include "lru_queue.h"

using namespace std;
queue::queue()
{
	head = NULL;
	tail = NULL;
}

int queue::front_size()
{
	if(head == NULL)
		return 0;
	return head->data.length();
}

string queue::front_url()
{
	if(head == NULL)
		return "";
	return head->url;
}

void queue::push(queue_element *node)
{
	if(head == NULL)
	{
		head = node;
		tail = node;
		node->prev = NULL;
		node->next = NULL;
	}
	else
	{
		tail->next = node;
		node->prev = tail;
		node->next = NULL;
		tail = node;	
	}
}
void queue::pop()
{
	queue_element *to_be_popped = head;
	if(head == NULL)
		return;
	if(head == tail)
	{
		head = NULL;
		tail = NULL;
	}
	else
	{
		head->next->prev = NULL;
		head = head->next;		
	}
	delete to_be_popped;
}
int queue::send_to_end(queue_element *node)
{
	if(node == NULL || head == NULL || tail == NULL)
		return 0;
	if(node == head)
	{
		if(head == tail)			//This is the only element in the queue. Do nothing.
			return 1;
		head->next->prev = NULL;
		head = head->next;
		tail->next = node;
		node->prev = tail;
		node->next = NULL;
		tail = node;		
		return 1;
	}
	else if(node == tail)			// The element is already at the end of the queue. Do nothing
		return 1;
	else
	{
		node->prev->next = node->next;
		node->next->prev = node->prev;
		tail->next = node;
		node->prev = tail;
		node->next = NULL;
		tail = node;
	}
	return 1;
}
