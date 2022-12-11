#pragma once
#include "Chain.h"

struct HashTable
{
	const int GrowthFactor = 2;
	int CountFilledElements;
	int Size;
	Chain** Array;

	HashTable()
	{
		CountFilledElements = 0;
		Size = 4;
		Array = new Chain * [Size];
	}
};

HashTable* CreateTable(int size);
Element* CreateElement(std::string key, std::string value);
bool InsertElement(HashTable* table, Element* element, int index);
int HashFunc(std::string key, int tableSize);
void ResolveCollisions(Element* first, Element* element);
bool RemoveElement(HashTable* table, std::string key);
HashTable* Rehashing(HashTable* table);
bool FindElement(HashTable* table, std::string key, std::string& data);
void DeleteTable(HashTable* table);

