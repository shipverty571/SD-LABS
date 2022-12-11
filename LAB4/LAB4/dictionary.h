#pragma once
#include "HashTable.h"

struct Dictionary
{
	HashTable* Table;
};
Dictionary* CreateDictionary();
bool InsertElement(Dictionary* dictionary, Element* element, std::string key);
bool RemoveElement(Dictionary* dictionary, std::string key);
bool FindElement(Dictionary* dictionary, std::string key, std::string& data);
void DeleteDictionary(Dictionary* dictionary);