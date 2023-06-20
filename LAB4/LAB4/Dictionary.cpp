#include "Dictionary.h"

Dictionary* CreateDictionary()
{
	Dictionary* dictionary = new Dictionary;
	dictionary->Table = CreateTable(4);
	return dictionary;
}

bool InsertElement(Dictionary* dictionary, Element* element, std::string key)
{
	int newIndex = HashFunc(key, dictionary->Table->Size);
	Element* current = dictionary->Table->Array[newIndex]->Head;
	while (current != nullptr)
	{
		if (current->Key == element->Key)
		{
			return false;
		}
		current = current->Next;
	}
	InsertElement(dictionary->Table, element, newIndex);
	return true;
}

bool RemoveElement(Dictionary* dictionary, std::string key)
{
	return RemoveElement(dictionary->Table, key);
}

bool FindElement(Dictionary* dictionary, std::string key, std::string& data)
{
	return FindElement(dictionary->Table, key, data);
}

void DeleteDictionary(Dictionary* dictionary)
{
	DeleteTable(dictionary->Table);
	delete dictionary;
}




