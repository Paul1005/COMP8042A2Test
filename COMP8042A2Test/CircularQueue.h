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
		for (int i = 0; i < s; i++) { // set all values to NULL
			data.push_back(NULL);
		}
	}

	queue() {
		c = 10;
	}

	~queue() {

	}

	//based on https://www.geeksforgeeks.org/circular-queue-set-1-introduction-array-implementation/
	void enque(Object obj)
	{
		if (!full()) // if the queue is not full
		{
			if (front == -1) // if the queue is empty 
			{
				front = 0;
				rear = 0;
				data[rear] = obj;
			}
			else if (rear == c - 1 && front != 0) // if the queue is almost full
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
	}

	//based on https://www.geeksforgeeks.org/circular-queue-set-1-introduction-array-implementation/
	Object deque()
	{
		if (empty()) // if empty return nothing
		{
			return NULL;
		}
		else {
			Object object = data[front];
			data[front] = NULL;
			if (front == rear) // if queue is almost empty
			{
				front = -1;
				rear = -1;
			}
			else if (front == c - 1)  // if queue is full
			{
				front = 0;
			}
			else {
				front++;
			}
			return object;
		}
	}

	bool empty() { // return true if empty, false if not
		if (front == -1) {
			return true;
		}
		else {
			return false;
		}
	}

	bool full() { // return true if full, false if not
		if ((front == 0 && rear == c - 1) || (rear == (front - 1) % (c - 1)))
		{
			return true;
		}
		else {
			return false;
		}
	}

	//based on https://www.geeksforgeeks.org/circular-queue-set-1-introduction-array-implementation/
	void print() {
		if (front == -1) // queue is empty, print nothing
		{
			cout << "";
		}
		else if (rear >= front) // if front is ahead of the rear
		{
			for (int i = front; i <= rear; i++) {
				cout << data[i];
			}
		}
		else // if rear is ahead of the front
		{
			for (int i = front; i < c; i++) { // print from front
				cout << data[i];
			}

			for (int i = 0; i <= rear; i++) { // print to rear
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

