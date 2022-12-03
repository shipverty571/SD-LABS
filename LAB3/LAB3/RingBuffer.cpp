#include "RingBuffer.h"
#include <cstdlib>
#include <ctime>

void CreateRingBuffer(RingBuffer* buffer, int size)
{
	srand(time(nullptr));
	buffer->Size = size;
	Element* current = nullptr;

	for (int i = 0; i < buffer->Size; i++)
	{
		Element* element = new Element();
		element->Data = rand() % 100;
		element->IsHaveData = true;
		if (i == 0)
		{
			buffer->Head = element;
			current = buffer->Head;
		}
		else if (i == buffer->Size - 1)
		{
			current->Next = element;
			current = element;
			current->Next = buffer->Head;
		}
		else
		{
			current->Next = element;
			current = element;
		}
	}

	buffer->UsedMemory = size;
	buffer->FreeMemory = 0;
	buffer->IndexInput = buffer->IndexOutput = buffer->Head;
}

int FreeMemoryInfo(RingBuffer* buffer)
{
	return buffer->FreeMemory;
}

int UsedMemoryInfo(RingBuffer* buffer)
{
	return buffer->UsedMemory;
}

void PushElement(RingBuffer* buffer, int data)
{
	buffer->IndexInput->IsHaveData = true;
	buffer->IndexInput->Data = data;
	buffer->IndexInput = buffer->IndexOutput = buffer->IndexInput->Next;

	if (buffer->FreeMemory != 0)
	{
		buffer->FreeMemory--;
		buffer->UsedMemory++;
	}
}

int PopElement(RingBuffer* buffer)
{
	while (!buffer->IndexOutput->IsHaveData)
	{
		buffer->IndexOutput = buffer->IndexOutput->Next;
	}
	buffer->IndexOutput->IsHaveData = false;
	buffer->FreeMemory++;
	buffer->UsedMemory--;

	return buffer->IndexOutput->Data;
}

void AddNewElement(RingBuffer* buffer)
{
	Element* element = new Element;

	if (buffer->IndexInput->IsHaveData == true)
	{
		buffer->IndexInput->IsHaveData = false;
		element->IsHaveData = true;
	}
	else
	{
		element->IsHaveData = false;
	}
	element->Data = buffer->IndexInput->Data;
	element->Next = buffer->IndexInput->Next;
	buffer->IndexInput->Next = element;
	buffer->Size++;
	buffer->FreeMemory++;
}

void DeleteBuffer(RingBuffer* buffer)
{
	delete buffer;
}

