#include "Element.h"
#include "List.h"

#include <cstdlib>
#include <ctime>

void InsertElementInFirstPosition(List* list, int data)
{
	Element* element = new Element;
	element->Data = data;

	if (list->Head == nullptr)
	{
		element->Next = nullptr;
		element->Prev = nullptr;
		list->Head = element;
		list->Tail = element;
	}
	else
	{
		list->Head->Prev = element;
		element->Next = list->Head;
		element->Prev = nullptr;
		list->Head = element;
	}

	list->Length++;
}

void InsertElementInLastPosition(List* list, int data)
{
	Element* element = new Element;
	element->Data = data;

	if (list->Tail == nullptr)
	{
		element->Next = nullptr;
		element->Prev = nullptr;
		list->Head = element;
		list->Tail = element;
	}
	else
	{
		list->Tail->Next = element;
		element->Prev = list->Tail;
		element->Next = nullptr;
		list->Tail = element;
	}

	list->Length++;
}

void GetRandomList(List* list, int count)
{
	srand(time(nullptr));

	for (int i = 0; i < count; i++)
	{
		InsertElementInLastPosition(list, rand());
	}
}

void InsertElementAfterPosition(List* list, int data, int index)
{
	
	if (index == list->Length-1)
	{
		InsertElementInLastPosition(list, data);
		return;
	}

	Element* tempElement = new Element;
	tempElement = list->Head;
	for (int i = 0; i < index; i++)
	{
		tempElement = tempElement->Next;
	}

	Element* element = new Element;
	element->Data = data;
	element->Next = tempElement->Next;
	tempElement->Next->Prev = element;
	element->Prev = tempElement;
	tempElement->Next = element;

	list->Length++;
}

void InsertElementBeforePosition(List* list, int data, int index)
{
	if (index == 0)
	{
		InsertElementInFirstPosition(list, data);
		return;
	}

	Element* tempElement = new Element;
	tempElement = list->Head;
	for (int i = 0; i < index; i++)
	{
		tempElement = tempElement->Next;
	}

	Element* element = new Element;
	element->Data = data;
	element->Next = tempElement;
	element->Prev = tempElement->Prev;
	tempElement->Prev->Next = element;
	tempElement->Prev = element;

	list->Length++;
}

void SwapElements(List* list, Element* first, Element* second)
{
	if (first == list->Head)
	{
		list->Head = second;
	}
	else
	{
		first->Prev->Next = second;
	}

	if (second == list->Tail)
	{
		list->Tail = first;
	}
	else
	{
		second->Next->Prev = first;
	}

	first->Next = second->Next;
	second->Prev = first->Prev;
	first->Prev = second;
	second->Next = first;
}


void RemoveElement(List* list, int index)
{
	if ((list->Head->Next == nullptr) || (list->Tail->Prev == nullptr))
	{
		Element* element = list->Head;
		list->Head = nullptr;
		list->Tail = nullptr;
		delete element;
		list->Length--;
		return;
	}
	if (index == 0)
	{
		Element* element = list->Head;
		list->Head->Next->Prev = nullptr;
		list->Head = element->Next;
		delete element;
		list->Length--;
		return;
	}
	if (index == list->Length-1)
	{
		Element* element = list->Tail;
		list->Tail->Prev->Next = nullptr;
		list->Tail = element->Prev;
		delete element;
		list->Length--;
		return;
	}

	Element* tempElement = new Element;
	tempElement = list->Head;
	for (int i = 0; i < index; i++)
	{
		tempElement = tempElement->Next;
	}

	tempElement->Prev->Next = tempElement->Next;
	tempElement->Next->Prev = tempElement->Prev;
	delete tempElement;
	list->Length--;
}



void SortList(List* list)
{
	Element* first = list->Head;

	for (int i = 0; i < list->Length; i++)
	{
		for (int j = 0; j < list->Length-1; j++)
		{
			if (first == nullptr) break;
			if (first->Next == nullptr) break;

			Element* second = first->Next;

			if (first->Data > second->Data)
			{
				SwapElements(list, first, second);
			}

			first = first->Next;
		}

		first = list->Head;
	}
}

int LinearSearch(List* list, int value)
{
	Element* element = list->Head;
	int index = -1;

	for (int i = 0; i < list->Length; i++)
	{
		if (element->Data == value)
		{
			index = i;
			break;
		}

		element = element->Next;
	}

	return index;
}