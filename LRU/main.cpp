// LRU.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "LRU.h"

int main()
{
	LRU* lru = new LRU(3);

	lru->Refer(1);

	lru->Refer(2);

	lru->Refer(3);

	lru->Display();

	lru->Refer(4);

	lru->Display();

	lru->Refer(5);

	lru->Display();

	lru->Refer(4);

	lru->Display();

	lru->Refer(4);

	lru->Display();

	lru->Refer(4);

	lru->Refer(4);

	lru->Display();

	delete lru;
	
	return 0;
}

