#include<bits/stdc++.h>
using namespace std;

class Queue {
	int front, rear;
	vector<int> arr;

public:
	Queue()
	{
		front = 0;
		rear = 0;
		arr.resize(100001);
	}

	// Enqueue (add) element 'e' at the end of the queue.
	void enqueue(int e)
	{
        arr[rear] = e;
        rear++;
	}

	// Dequeue (retrieve) the element from the front of the queue.
	int dequeue()
	{
        if (front == rear)
            return -1;
        int x = arr[front]; 
        front++;
        return x;
	}
};