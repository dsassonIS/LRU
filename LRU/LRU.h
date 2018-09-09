#pragma once
#include "stdafx.h"
#include "Queue.h"
#include <unordered_map>
using namespace std;

#define MAX_CACHE_SIZE (3)

class LRU
{
public:

	LRU();
	LRU(int max_size);
	~LRU();
	void Display();	
	void Refer(int val);

private:
	Queue* queue;
	unordered_map<int, Node*> map;

};
