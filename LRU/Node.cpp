#pragma once
#include "stdafx.h"
#include "Node.h"

Node::Node()
{
	this->val = 0;
	this->backward = NULL;
	this->forward = NULL;

}

Node::Node(int val)
{
	this->val = val;
	this->backward = NULL;
	this->forward = NULL;

}


Node::Node(const Node& node)
{
	this->val = node.val;
	this->backward = node.backward;
	this->forward = node.forward;

}

Node* Node::GetBackward()
{
	return this->backward;

}

void Node::SetBackward(Node* backward)
{
	this->backward = backward;

}

Node* Node::GetFront()
{
	return this->forward;

}

void Node::SetFront(Node* front)
{
	this->forward = front;

}

int Node::GetValue()
{
	return this->val;
}


Node::~Node()
{
	this->backward = NULL;
	this->forward = NULL;
}

