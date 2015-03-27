#include <iostream>
#include "lru_queue.h"

using namespace std;
queue::queue()
{
	head = NULL;
	tail = NULL;
}

string queue::front()
{
	if(head == NULL)
		return "";
	return head->url;
}

void queue::push(queue_element *node)
{
	cout<<node<<endl;
	if(head == NULL)
	{
		head = node;
		tail = node;
		node->prev = NULL;
		node->next = NULL;
		cout<<"Push: Head is "<<head<<endl;
		cout<<"Push: Tail is "<<tail<<endl;
	}
	else
	{
		tail->next = node;
		node->prev = tail;
		node->next = NULL;
		tail = node;
		cout<<"Push: Head is "<<head->url<<endl;
		cout<<"Push: Tail is "<<tail->url<<endl;	
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
		cout<<"Head is now: "<<head->url<<endl;
		cout<<"Tail is now: "<<tail->url<<endl;	
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
/*
int main(int argc, char const *argv[])
{
	queue Q;
	queue_element *e1 = new queue_element();
	e1->url = "url1";
	queue_element *e2 = new queue_element();
	e2->url = "url2";
	queue_element *e3 = new queue_element();
	e3->url = "url3";
	Q.push(e1);
	cout<<Q.head->url<<"\t"<<Q.tail->url<<endl;
	Q.push(e2);
	cout<<Q.head->url<<"\t"<<Q.tail->url<<endl;
	Q.push(e3);
	cout<<Q.head->url<<"\t"<<Q.tail->url<<endl;
	// Q.pop();
	// cout<<Q.head->url<<"\t"<<Q.tail->url<<endl;
	// Q.pop();
	// cout<<Q.head->url<<"\t"<<Q.tail->url<<endl;
	// Q.pop();
	// cout<<Q.head<<endl;
	Q.send_to_end(e1);
	cout<<Q.head->url<<"\t"<<Q.tail->url<<endl;
	Q.send_to_end(e3);
	cout<<Q.head->url<<"\t"<<Q.tail->url<<endl;
	Q.send_to_end(e3);
	cout<<Q.head->url<<"\t"<<Q.tail->url<<endl;
	return 0;
}
*/