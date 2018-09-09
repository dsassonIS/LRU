#pragma once
#include "stdafx.h"


class Node
{
public:
	Node();
	Node(int val);
	Node(const Node& node);
	~Node();
	Node* GetBackward();
	void SetBackward(Node* backward);
	Node* GetFront();
	void SetFront(Node* front);
	int GetValue();


private:
	int val;
	Node* forward;
	Node* backward;
};
