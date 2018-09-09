#pragma once
#include "stdafx.h"
#include "Node.h"



class Queue
{
public:
	//Queue();
	Queue(int max_size);
	~Queue();
	bool Enqueue(int val);
	int Dequeue();
	bool Erase(Node* node);
	Node* First();
	Node* Last();
	bool IsFull();
	void Print();

private:
	Node* front;
	Node* rear;
	int curr_size;
	int max_size;

};

