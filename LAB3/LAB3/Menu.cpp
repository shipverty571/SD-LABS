#include "Menu.h"
#include "Stack.h"
#include "RingBuffer.h"
#include <iostream>
#include "QueueRingBuffer.h"
#include "QueueStack.h"

using namespace std;

int InputValue(string outputString)
{
	if (outputString != "")
	{
		cout << outputString << endl;
	}

	int value;
	while (true)
	{
		cin >> value;
		if (cin.fail())
		{
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			cout << "��������� ������. ���������� �����" << endl;
			continue;
		}

		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		if (std::cin.gcount() > 1)
		{
			cout << "��������� ������. ���������� �����" << endl;
			continue;
		}

		break;
	}

	return value;
}

bool StackIsCreated(Stack* stack)
{
	if (stack != nullptr)
	{
		return true;
	}

	cout << "���� �� ������" << endl;
	return false;
}

bool QueueStackIsCreated(QueueStack* queue)
{
	if (queue != nullptr)
	{
		return true;
	}

	cout << "������� �� �������" << endl;
	return false;
}


bool RingBufferIsCreated(RingBuffer* buffer)
{
	if (buffer != nullptr)
	{
		return true;
	}

	cout << "����� �� ������" << endl;
	return false;
}

bool QueueRingBufferIsCreated(QueueRingBuffer* queue)
{
	if (queue != nullptr)
	{
		return true;
	}

	cout << "������� �� �������" << endl;
	return false;
}


void PrintStack(Stack* stack)
{
	for (int i = 0; i < stack->Top; i++)
	{
		cout << stack->Buffer[i] << " ";
	}
	cout << endl;
}

void PrintBuffer(RingBuffer* buffer)
{


	Element* current = buffer->Head;
	for (int i = 0; i < buffer->Size; i++)
	{
		if (current->IsHaveData)
		{
			cout << current->Data << " ";
			current = current->Next;
			continue;
		}
		cout << "- ";
		current = current->Next;
	}
	cout << endl;
}

void PrintQueueBuffer(QueueRingBuffer* queue)
{
	if (queue->Buffer->Size)
	{
		cout << "value index: " << queue->Buffer->IndexOutput->Data << endl;
		Element* element = queue->Buffer->IndexOutput;
		for (int i = 0; i < queue->Buffer->Size; i++)
		{
			cout << element->Data << " ";
			element = element->Next;
		}
		cout << endl;
	}
	else
	{
		cout << "� ������� ��� ���������" << endl;
	}
}

void PrintQueueStack(QueueStack* queue)
{
	cout << "InStack: ";
	PrintStack(queue->InStack);
	cout << "OutStack: ";
	PrintStack(queue->OutStack);
}

int RingBufferSize()
{
	int size;
	while (true)
	{
		size = InputValue("������� ������");
		if (size <= 0)
		{
			cout << "������ �� ���������� ������" << endl;
			continue;
		}
		break;
	}

	return size;
}

void MenuQueueRingBuffer()
{
	QueueRingBuffer* queue = nullptr;

	while (true)
	{
		cout << "�������� ��������:" << endl;
		cout << "1. ������� �������" << endl;
		cout << "2. �������� � �������" << endl;
		cout << "3. ������� �� �������" << endl;
		cout << "4. ������� �������" << endl;
		cout << "0. �����" << endl;

		int key = InputValue("");
		switch (key)
		{
			case 1:
			{
				if (QueueRingBufferIsCreated(queue))
				{
					cout << "������� ��� �������" << endl;
					break;
				}
				queue = new QueueRingBuffer();
				int size = RingBufferSize();
				CreateQueueBuffer(queue, size);
				break;
			}
			case 2:
			{
				if (!QueueRingBufferIsCreated(queue)) break;
				int value = InputValue("������� ��������");
				EnqueueBuffer(queue, value);
				PrintQueueBuffer(queue);
				break;
			}
			case 3:
				if (!QueueRingBufferIsCreated(queue)) break;
				if (!queue->Buffer->Size) break;
				cout << "������� �������: " << DequeueBuffer(queue) << endl;
				PrintQueueBuffer(queue);
				break;
			case 4:
				if (!QueueRingBufferIsCreated(queue)) break;
				PrintQueueBuffer(queue);
				break;
			case 0:
				if (QueueRingBufferIsCreated(queue)) DeleteQueue(queue);
				return;
			default:
				cout << "������� �������� ��������. ���������� �����" << endl;
				break;
		}
	}
}

void MenuQueueStack()
{
	QueueStack* queue = nullptr;

	while (true)
	{
		cout << "�������� ��������:" << endl;
		cout << "1. ������� �������" << endl;
		cout << "2. �������� � �������" << endl;
		cout << "3. ������� �� �������" << endl;
		cout << "4. ��������� ������ �������" << endl;
		cout << "5. ������� �������" << endl;
		cout << "0. �����" << endl;

		int key = InputValue("");
		switch (key)
		{
			case 1:
				if (QueueStackIsCreated(queue))
				{
					cout << "������� ��� �������" << endl;
					break;
				}
				queue = new QueueStack();
				cout << "������� ������� �������" << endl;
				break;
			case 2:
			{
				if (!QueueStackIsCreated(queue)) break;
				int value = InputValue("������� �����");
				if (!Enqueue(queue, value))
				{
					cout << "������� �����������" << endl;
					break;
				}
				PrintQueueStack(queue);
				break;
			}
			case 3:
			{
				if (!QueueStackIsCreated(queue)) break;
				int value;
				if (!Dequeue(queue, value))
				{
					cout << "������� �����" << endl;
					break;
				}
				cout << "����������� ��������: " << value << endl;
				PrintQueueStack(queue);
				break;
			}
			case 4:
				if (!QueueStackIsCreated(queue)) break;
				ResizeQueue(queue);
				cout << "������� �������: " << queue->InStack->Capacity << endl;
				break;
			case 5:
				if (!QueueStackIsCreated(queue)) break;
				PrintQueueStack(queue);
				break;
			case 0:
				if (QueueStackIsCreated(queue)) DeleteQueue(queue);
				return;
			default:
				cout << "������� �������� ��������. ���������� �����" << endl;
				break;
		}
	}
}


void MenuRingBuffer()
{
	RingBuffer* buffer = nullptr;

	while (true)
	{
		cout << "�������� ��������:" << endl;
		cout << "1. ������� �����" << endl;
		cout << "2. ������� ��������� �����" << endl;
		cout << "3. ������� ������� �����" << endl;
		cout << "4. �������� �������" << endl;
		cout << "5. ������� �������" << endl;
		cout << "6. ��������� ������ ������ �� 1 �������" << endl;
		cout << "7. ������� �����" << endl;
		cout << "0. �����" << endl;

		int key = InputValue("");
		switch (key)
		{
			case 1:
			{
				if (RingBufferIsCreated(buffer))
				{
					cout << "����� ��� ������" << endl;
					break;
				}
				buffer = new RingBuffer();
				int size = RingBufferSize();
				CreateRingBuffer(buffer, size);
				break;
			}
			case 2:
				if (!RingBufferIsCreated(buffer)) break;
				cout << "�������� " << FreeMemoryInfo(buffer) << endl;
				break;
			case 3:
				if (!RingBufferIsCreated(buffer)) break;
				cout << "������ " << UsedMemoryInfo(buffer) << endl;
				break;
			case 4:
			{
				if (!RingBufferIsCreated(buffer)) break;
				int data = InputValue("������� �����");
				PushElement(buffer, data);
				PrintBuffer(buffer);
				break;
			}
			case 5:
			{
				if (!RingBufferIsCreated(buffer)) break;
				if (buffer->FreeMemory == buffer->Size) break;
				cout << "������� �������: " << PopElement(buffer) << endl;
				PrintBuffer(buffer);
				break;
			}
			case 6:
				if (!RingBufferIsCreated(buffer)) break;
				AddNewElement(buffer);
				cout << "����� ������ ������� ���������" << endl;
				PrintBuffer(buffer);
				break;
			case 7:
				if (!RingBufferIsCreated(buffer)) break;
				PrintBuffer(buffer);
				break;
			case 0:
				if (RingBufferIsCreated(buffer)) DeleteBuffer(buffer);
				return;
			default:
				cout << "������� �������� ��������. ���������� �����" << endl;
				break;
		}
	}
}

void MenuStack()
{
	Stack* stack = nullptr;
	
	while (true)
	{
		cout << "�������� ��������:" << endl;
		cout << "1. ������� ����" << endl;
		cout << "2. �������� ������� � ����" << endl;
		cout << "3. ������� ������� �� �����" << endl;
		cout << "4. ��������� ������ �����" << endl;
		cout << "5. ������� ����" << endl;
		cout << "0. �����" << endl;
		int key = InputValue("");
		switch (key)
		{
			case 1:
			{
				if (StackIsCreated(stack))
				{
					cout << "���� ��� ������" << endl;
					break;
				}
				int size = InputValue("������� ������ �����");
				stack = InitStack(size);
				cout << "���� ������� ������" << endl;
				PrintStack(stack);
				break;
			}
			case 2:
			{
				if (!StackIsCreated(stack)) break;
				int value = InputValue("������� �������� ��������");
				if (!PushStack(stack, value))
				{
					cout << "���� ����������" << endl;
					break;
				}
				PrintStack(stack);
				break;
			}
			case 3:
				if (!StackIsCreated(stack)) break;
				PopStack(stack);
				PrintStack(stack);
				break;
			case 4:
				if (!StackIsCreated(stack)) break;
				Resize(stack);
				break;
			case 5:
				if (!StackIsCreated(stack)) break;
				PrintStack(stack);
				break;
			case 0:
				if (StackIsCreated(stack)) DeleteStack(stack);
				return;
			default:
				cout << "������� �������� ��������. ���������� �����" << endl;
				break;
		}
	}
}

void Menu()
{
	cout << "����� ����������!" << endl;
	cout << "�������� ������� �� ������ ����" << endl;

	while (true)
	{
		cout << "1. ����" << endl;
		cout << "2. ��������� �����" << endl;
		cout << "3. ������� �� ���� ���������� ������" << endl;
		cout << "4. ������� �� ���� ���� ������" << endl;
		cout << "0. �����" << endl;

		int key = InputValue("");
		switch (key)
		{
			case 1:
				MenuStack();
				break;
			case 2:
				MenuRingBuffer();
				break;
			case 3:
				MenuQueueRingBuffer();
				break;
			case 4:
				MenuQueueStack();
				break;
			case 0:
				return;
		}
	}
}
