#include <string>
using namespace std;
struct queue_element
{
	string url;
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
	string front();
	void push(queue_element *node);
	void pop();
	int send_to_end(queue_element *node);
};