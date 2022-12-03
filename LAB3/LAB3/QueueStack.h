#pragma once
#include "Stack.h"

struct QueueStack
{
	Stack* InStack;
	Stack* OutStack;

	QueueStack()
	{
		InStack = new Stack;
		OutStack = new Stack;
	}
};

bool Enqueue(QueueStack* queue, int value);
bool Dequeue(QueueStack* queue, int& value);
void ResizeQueue(QueueStack* queue);
void DeleteQueue(QueueStack* queue);

