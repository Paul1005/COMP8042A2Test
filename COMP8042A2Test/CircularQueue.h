#include <iostream>
#include <vector>

using namespace std;

template <typename Object>
class queue
{
public:
	queue(int s) {
		c = s;
		front = -1;
		rear = -1;
		for (int i = 0; i < s; i++) {
			data.push_back(NULL);
		}
	}

	queue() {
		c = 10;
	}

	~queue() {

	}

	//taken from https://www.geeksforgeeks.org/circular-queue-set-1-introduction-array-implementation/
	void enque(Object obj)
	{
		if (full())
		{
			// do nothing
		}
		else if (front == -1)
		{
			front = 0;
			rear = 0;
			data[rear] = obj;
		}
		else if (rear == c - 1 && front != 0)
		{
			rear = 0;
			data[rear] = obj;
		}
		else
		{
			rear++;
			data[rear] = obj;
		}
	}

	Object deque()
	{
		if (empty())
		{
			return NULL;
		}
		else {
			Object object = data[front];
			data[front] = NULL;
			if (front == rear)
			{
				front = -1;
				rear = -1;
			}
			else if (front == c - 1) {
				front = 0;
			}
			else {
				front++;
			}
			return object;
		}
	}

	bool empty() {
		if (front == -1) {
			return true;
		}
		else {
			return false;
		}
	}

	bool full() {
		if ((front == 0 && rear == c - 1) || (rear == (front - 1) % (c - 1)))
		{
			return true;
		}
		else {
			return false;
		}
	}

	void print() {
		if (front == -1)
		{
			cout << "";
		}
		else if (rear >= front)
		{
			for (int i = front; i <= rear; i++) {
				cout << data[i];
			}
		}
		else
		{
			for (int i = front; i < c; i++) {
				cout << data[i];
			}

			for (int i = 0; i <= rear; i++) {
				cout << data[i];
			}
		}
	}

private:
	vector<Object> data;
	int c;
	int front;
	int rear;
};

