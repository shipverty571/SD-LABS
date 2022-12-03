#include "Stack.h"
#include <cstdlib>
#include <ctime>

Stack* InitStack(int size)
{
	srand(time(nullptr));
	Stack* stack = new Stack();

	for (int i = 0; i < size; i++)
	{
		if (stack->Top >= stack->Capacity)
		{
			Resize(stack);
		}
		PushStack(stack, rand() % 100);
	}
	return stack;
}

bool PushStack(Stack* stack, int data)
{
	if (stack->Top >= stack->Capacity)
	{
		return false;
	}
	stack->Buffer[stack->Top] = data;
	stack->Top++;
	return true;
}

void Resize(Stack* stack)
{
	stack->Capacity *= stack->GrowthFactor;

	int* newArray = new int[stack->Capacity];
	for (int i = 0; i < stack->Top; i++)
	{
		newArray[i] = stack->Buffer[i];
	}
	delete[] stack->Buffer;
	stack->Buffer = newArray;
}

int PopStack(Stack* stack)
{
	if (stack->Top > 0)
	{
		stack->Top--;
		return stack->Buffer[stack->Top];
	}
}

void DeleteStack(Stack* stack)
{
	delete[] stack->Buffer;
	delete stack;
}