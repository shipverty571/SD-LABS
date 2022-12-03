#pragma once

struct Stack
{
	int* Buffer;
	int Top;
	int Capacity;
	const int GrowthFactor = 2;

	Stack()
	{
		Buffer = new int[4];
		Top = 0;
		Capacity = 4;
	}
};

Stack* InitStack(int size);
bool PushStack(Stack* stack, int data);
int PopStack(Stack* stack);
void DeleteStack(Stack* stack);
void Resize(Stack* stack);