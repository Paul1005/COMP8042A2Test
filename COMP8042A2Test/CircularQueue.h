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
	}
	
	queue() {
		c = 10;
	}
	
	~queue() { 
	
	}

	void enque(Object obj)
	{
		if (front == -1) {
			front++;
		}

		if ((rear == c -1 && front == 0)|| (rear == front - 1)) {
			data.push_back(obj);
			rear++;
		}

	}

	Object deque()
	{
		Object frontOfData = data.front();
		data.erase(data.begin());
		if (front != -1) {
			front--;		
			return frontOfData;
		}
		else {
			return (Object)0;
		}

	}

	bool empty() {
		return true; 
	}

	bool full() { 
		return false; 
	}

	void print() {
		count << data;
	}

private:
	vector<Object> data;
	int c;
	int front;
	int rear;
};

