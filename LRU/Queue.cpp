#pragma once
#include "stdafx.h"
#include "Node.h"
#include "Queue.h"
#include <iostream>
using namespace std;


#define DEQUEUE_ERROR (-1)



Queue::Queue(int max_size)
{
	this->curr_size = 0;
	this->max_size = max_size;
	this->front = NULL;
	this->rear = NULL;
}

Queue::~Queue()
{
	Node *runner, *temp;
	runner = front;

	while (runner != NULL)
	{
		temp = runner;
		runner = runner->GetFront();
		delete temp;
	}
}
bool Queue::Enqueue(int val)
{
	Node* node = new Node(val);
	// Queue Empty
	if (curr_size == 0)
	{
		front = node;
		rear = node;
	}
	else
	{
		// Queue Full - first Dequeue
		if (curr_size == max_size)
		{
			Dequeue();
		}

		// update front
		Node* temp = front;
		front = node;
		node->SetFront(temp);

		// update previous front backawrd
		temp->SetBackward(node);
	}

	curr_size++;

	return true;
}

int Queue::Dequeue()
{
	if (curr_size == 0)
	{
		// mark as error
		return DEQUEUE_ERROR;
	}

	int dequeVal = rear->GetValue();

	Node* temp;
	temp = rear;
	rear = rear->GetBackward();
	rear->SetFront(NULL);
	delete temp;

	curr_size--;
	return dequeVal;

}
Node* Queue::First()
{
	return front;
}
Node* Queue::Last()
{
	return rear;
}


bool Queue::IsFull()
{
	return curr_size == max_size;
}

void Queue::Print()
{
	Node* runner;
	runner = front;

	while (runner != NULL)
	{
		cout << runner->GetValue() << " , ";
		runner = runner->GetFront();
	}

	cout << endl;
}


bool Queue::Erase(Node* node)
{
	if (node == NULL)
	{
		return false;
	}
	Node* temp;

	// if first
	if (node == this->front)
	{
		temp = this->front;
		this->front = this->front->GetFront();
		this->front->SetBackward(NULL);
		// delete old front
		delete temp;
	}
	// if last
	else if (node == this->front)
	{
		temp = this->rear;
		this->rear = this->front->GetBackward();
		this->front->SetFront(NULL);
		// delete old rear
		delete temp;
	}
	else // middle
	{
		Node* tempBackard = node->GetBackward();
		temp = node->GetFront();
		temp->SetBackward(tempBackard);
		tempBackard->SetFront(temp);
		// delete rear
		delete node;
		 
	}

	curr_size--;

	return true;
}





