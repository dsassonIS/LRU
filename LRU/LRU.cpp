#include "stdafx.h"
#include "LRU.h"
#include <iostream>

using namespace std;


LRU::LRU()
{
	this->queue = new Queue(MAX_CACHE_SIZE);
}

LRU::LRU(int max_size)
{
	this->queue = new Queue(max_size);
}


LRU::~LRU()
{
	delete queue;
}


void LRU::Refer(int val)
{
	cout << "Refering " << val << endl;

	// if not exist in cache
	if (map.find(val) == map.end())
	{
		cout << "Val " << val << " Not In Cache. Inserting it now" << endl;

		if (queue->IsFull())
		{
			int lruElementVal = queue->Dequeue();
			cout << "Cache is full removing LRU " << lruElementVal << endl;
			//erase least recently used element			
			map.erase(lruElementVal);
		}
	}
	else // exist in cache
	{
		cout << val << " Is in Cache - Moving Forward" << endl;
		queue->Erase(map[val]);
	}

	// update reference
	queue->Enqueue(val);
	map[val] = queue->First();

}

void LRU::Display()
{
	cout << "Printing Cache: " << endl;
	queue->Print();
}