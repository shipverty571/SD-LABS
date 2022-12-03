#include "QueueStack.h"

bool Enqueue(QueueStack* queue, int value)
{
	bool isOverflow;
	if (queue->InStack->Top + queue->OutStack->Top == queue->InStack->Capacity)
	{
		isOverflow = false;
	}
	else
	{
		isOverflow = PushStack(queue->InStack, value);
	}

	return isOverflow;
}

bool Dequeue(QueueStack* queue, int& value)
{
	if (queue->OutStack->Top == 0)
	{
		if (queue->InStack->Top == 0)
		{
			return false;
		}

		while (queue->InStack->Top != 0)
		{
			PushStack(queue->OutStack, (PopStack(queue->InStack)));
		}
	}

	value = PopStack(queue->OutStack);
	return true;
}

void ResizeQueue(QueueStack* queue)
{
	Resize(queue->InStack);
	Resize(queue->OutStack);
}

void DeleteQueue(QueueStack* queue)
{
	DeleteStack(queue->InStack);
	DeleteStack(queue->OutStack);
}