#include "HashTable.h"

HashTable* CreateTable(int size)
{
	HashTable* table = new HashTable;
	table->Size = size;
	table->CountFilledElements = 0;
	table->Array = new Chain * [table->Size];
	for (int i = 0; i < table->Size; i++)
	{
		Chain* newChain = new Chain;
		table->Array[i] = newChain;
		table->Array[i]->Size = 0;
		table->Array[i]->Head = nullptr;
	}
	return table;
}

Element* CreateElement(std::string key, std::string value)
{
	Element* element = new Element;
	element->Key = key;
	element->Value = value;
	element->Next = nullptr;

	return element;
}

bool InsertElement(HashTable* table, Element* element, int index)
{
	
	Element* currentElement = table->Array[index]->Head;
	while (currentElement != nullptr)
	{
		if (currentElement->Key == element->Key && currentElement->Value == element->Value)
		{
			return false;
		}

		currentElement = currentElement->Next;
	}
	if (table->Array[index]->Head == nullptr)
	{
		table->Array[index]->Head = element;
	}
	else
	{
		ResolveCollisions(table->Array[index]->Head, element);
	}
	table->Array[index]->Size++;
	table->CountFilledElements++;
	int fullValue = table->Size * 4 / 3;
	if (table->CountFilledElements == fullValue)
	{
		Rehashing(*table);
	}
	return true;
}

int HashFunc(std::string key, int tableSize)
{
	int size = key.length();
	int hash = 0;
	for (int i = 0; i < size; i++)
	{
		hash = (hash * (tableSize - 1) + key[i]) % tableSize;
	}

	return abs(hash);
}

void ResolveCollisions(Element* first, Element* element)
{
	Element* current = first;
	while (current->Next != nullptr)
	{
		current = current->Next;
	}
	current->Next = element;
}

bool RemoveElement(HashTable* table, std::string key)
{
	int removeIndex = HashFunc(key, table->Size);
	if (table->Array[removeIndex]->Size == 0) return false;
	Element* current = table->Array[removeIndex]->Head;
	int count = 0;
	bool isNeedRemove = false;
	while (current != nullptr)
	{
		if (current->Key == key)
		{
			count++;
			isNeedRemove = true;
		}
		current = current->Next;
	}

	if (isNeedRemove == false)
	{
		return false;
	}
	while (count != 0)
	{
		if (table->Array[removeIndex]->Head->Key == key)
		{
			Element* removeElement = table->Array[removeIndex]->Head;
			table->Array[removeIndex]->Head = table->Array[removeIndex]->Head->Next;
			delete removeElement;
		}
		else
		{
			Element* prevRemoveElement = table->Array[removeIndex]->Head;
			int secondCount = 0;

			while (prevRemoveElement->Next->Key != key)
			{
				secondCount++;
				prevRemoveElement = prevRemoveElement->Next;
			}
			Element* deleteElement = prevRemoveElement->Next;

			if (secondCount == table->Array[removeIndex]->Size - 2)
			{
				prevRemoveElement->Next = nullptr;
			}
			else
			{
				prevRemoveElement->Next = prevRemoveElement->Next->Next;
			}
			delete deleteElement;
		}
		table->CountFilledElements--;
		table->Array[removeIndex]->Size--;
		count--;
	}
	return true;
}

void Rehashing(HashTable& table)
{
	int newSize = table.Size;

	if (table.Size == 1)
	{
		newSize++;
	}
	else
	{
		newSize *= table.GrowthFactor;
	}
	HashTable newTable = *CreateTable(newSize);
	for (int i = 0; i < table.Size; i++)
	{
		Element* current = table.Array[i]->Head;

		while (current != nullptr)
		{
			int index = HashFunc(current->Key, newTable.Size);
			InsertElement(&newTable, current, index);
			table.Array[i]->Head = current->Next;
			current->Next = nullptr;
			current = table.Array[i]->Head;
		}
	}
	table.CountFilledElements = newTable.CountFilledElements;
	table.Array = newTable.Array;
	table.Size = newTable.Size;
}

bool FindElement(HashTable* table, std::string key, std::string& data)
{
	int index = HashFunc(key, table->Size);
	Element* current;
	if (!table->Array[index]->Head)
	{
		return false;
		
	}
	current = table->Array[index]->Head;
	while (current != nullptr)
	{
		if (current->Key == key)
		{
			data.append(current->Value);
			data.push_back(' ');
		}
		current = current->Next;
	}
	if (data.empty())
	{
		return false;
	}
	return true;
}

void DeleteTable(HashTable* table)
{
	for (int i = 0; i < table->Size; i++)
	{
		for (int j = 0; j < table->Array[i]->Size; j++)
		{
			Element* removeElement = table->Array[i]->Head;

			if (table->Array[i]->Head->Next != nullptr)
			{
				table->Array[i]->Head = table->Array[i]->Head->Next;
			}
			delete removeElement;
		}
		delete table->Array[i];
	}
	delete[] table->Array;
	delete table;
}

