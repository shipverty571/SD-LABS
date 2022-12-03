#include "QueueRingBuffer.h"
#include <cstdlib>
#include <ctime>

void CreateQueueBuffer(QueueRingBuffer* queue, int size)
{
	srand(time(nullptr));

	RingBuffer* buffer = new RingBuffer;
	queue->Buffer = buffer;
	queue->Buffer->Size = size;
	Element* current = nullptr;

	for (int i = 0; i < queue->Buffer->Size; i++)
	{
		Element* element = new Element;
		element->Data = rand() % 100;
		element->IsHaveData = true;

		if (i == 0)
		{
			queue->Buffer->IndexOutput = element;
			current = queue->Buffer->IndexOutput;
			current->Next = current;
			queue->Buffer->Head = current;
		}
		else if (i == size - 1)
		{
			current->Next = element;
			current = element;
			current->Next = queue->Buffer->IndexOutput;
			queue->Buffer->Head = current;
		}
		else
		{
			current->Next = element;
			current = element;
		}
	}
	queue->Buffer->IndexInput = nullptr;
	queue->Buffer->UsedMemory = queue->Buffer->FreeMemory = 0;
}

void EnqueueBuffer(QueueRingBuffer* queue, int value)
{
	Element* newItem = new Element;
	newItem->Data = value;
	newItem->IsHaveData = true;
	Element* current = nullptr;

	if (queue->Buffer->Size != 0)
	{
		current = queue->Buffer->Head;
		current->Next = newItem;
		newItem->Next = queue->Buffer->IndexOutput;
		queue->Buffer->Head = newItem;
	}
	else
	{
		queue->Buffer->Head = newItem;
		current = queue->Buffer->Head;
		current->Next = queue->Buffer->IndexOutput;
		queue->Buffer->IndexOutput = current;
	}
	queue->Buffer->Size++;
}

int DequeueBuffer(QueueRingBuffer* queue)
{
	Element* removeItem = queue->Buffer->IndexOutput;
	queue->Buffer->IndexOutput = removeItem->Next;
	queue->Buffer->Size--;
	int deleteElement = removeItem->Data;
	queue->Buffer->Head->Next = queue->Buffer->IndexOutput;
	delete removeItem;
	return deleteElement;
}

void DeleteQueue(QueueRingBuffer* queue)
{
	for (int i = 0; i < queue->Buffer->Size; i++)
	{
		DequeueBuffer(queue);
	}
	queue->Buffer->Head = nullptr;
	delete queue;
}
