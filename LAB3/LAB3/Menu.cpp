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
			cout << "Произошла ошибка. Попробуйте снова" << endl;
			continue;
		}

		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		if (std::cin.gcount() > 1)
		{
			cout << "Произошла ошибка. Попробуйте снова" << endl;
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

	cout << "Стек не создан" << endl;
	return false;
}

bool QueueStackIsCreated(QueueStack* queue)
{
	if (queue != nullptr)
	{
		return true;
	}

	cout << "Очередь не создана" << endl;
	return false;
}


bool RingBufferIsCreated(RingBuffer* buffer)
{
	if (buffer != nullptr)
	{
		return true;
	}

	cout << "Буфер не создан" << endl;
	return false;
}

bool QueueRingBufferIsCreated(QueueRingBuffer* queue)
{
	if (queue != nullptr)
	{
		return true;
	}

	cout << "Очередь не создана" << endl;
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
		cout << "В очереди нет элементов" << endl;
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
		size = InputValue("Введите размер");
		if (size <= 0)
		{
			cout << "Введен не корректный размер" << endl;
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
		cout << "Выберите действие:" << endl;
		cout << "1. Создать очередь" << endl;
		cout << "2. Добавить в очередь" << endl;
		cout << "3. Извлечь из очереди" << endl;
		cout << "4. Вывести очередь" << endl;
		cout << "0. Выход" << endl;

		int key = InputValue("");
		switch (key)
		{
			case 1:
			{
				if (QueueRingBufferIsCreated(queue))
				{
					cout << "Очередь уже создана" << endl;
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
				int value = InputValue("Введите значение");
				EnqueueBuffer(queue, value);
				PrintQueueBuffer(queue);
				break;
			}
			case 3:
				if (!QueueRingBufferIsCreated(queue)) break;
				if (!queue->Buffer->Size) break;
				cout << "Достали элемент: " << DequeueBuffer(queue) << endl;
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
				cout << "Введено неверное значение. Попробуйте снова" << endl;
				break;
		}
	}
}

void MenuQueueStack()
{
	QueueStack* queue = nullptr;

	while (true)
	{
		cout << "Выберите действие:" << endl;
		cout << "1. Создать очередь" << endl;
		cout << "2. Добавить в очередь" << endl;
		cout << "3. Извлечь из очереди" << endl;
		cout << "4. Увеличить размер очереди" << endl;
		cout << "5. Вывести очередь" << endl;
		cout << "0. Выход" << endl;

		int key = InputValue("");
		switch (key)
		{
			case 1:
				if (QueueStackIsCreated(queue))
				{
					cout << "Очередь уже создана" << endl;
					break;
				}
				queue = new QueueStack();
				cout << "Очередь успешно создана" << endl;
				break;
			case 2:
			{
				if (!QueueStackIsCreated(queue)) break;
				int value = InputValue("Введите число");
				if (!Enqueue(queue, value))
				{
					cout << "Очередь переполнена" << endl;
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
					cout << "Очередь пуста" << endl;
					break;
				}
				cout << "Извлеченное значение: " << value << endl;
				PrintQueueStack(queue);
				break;
			}
			case 4:
				if (!QueueStackIsCreated(queue)) break;
				ResizeQueue(queue);
				cout << "Текущая емкость: " << queue->InStack->Capacity << endl;
				break;
			case 5:
				if (!QueueStackIsCreated(queue)) break;
				PrintQueueStack(queue);
				break;
			case 0:
				if (QueueStackIsCreated(queue)) DeleteQueue(queue);
				return;
			default:
				cout << "Введено неверное значение. Попробуйте снова" << endl;
				break;
		}
	}
}


void MenuRingBuffer()
{
	RingBuffer* buffer = nullptr;

	while (true)
	{
		cout << "Выберите действие:" << endl;
		cout << "1. Создать буфер" << endl;
		cout << "2. Вернуть свободное место" << endl;
		cout << "3. Вернуть занятое место" << endl;
		cout << "4. Добавить элемент" << endl;
		cout << "5. Достать элемент" << endl;
		cout << "6. Увеличить размер буфера на 1 элемент" << endl;
		cout << "7. Вывести буфер" << endl;
		cout << "0. Выход" << endl;

		int key = InputValue("");
		switch (key)
		{
			case 1:
			{
				if (RingBufferIsCreated(buffer))
				{
					cout << "Буфер уже создан" << endl;
					break;
				}
				buffer = new RingBuffer();
				int size = RingBufferSize();
				CreateRingBuffer(buffer, size);
				break;
			}
			case 2:
				if (!RingBufferIsCreated(buffer)) break;
				cout << "Свободно " << FreeMemoryInfo(buffer) << endl;
				break;
			case 3:
				if (!RingBufferIsCreated(buffer)) break;
				cout << "Занято " << UsedMemoryInfo(buffer) << endl;
				break;
			case 4:
			{
				if (!RingBufferIsCreated(buffer)) break;
				int data = InputValue("Введите число");
				PushElement(buffer, data);
				PrintBuffer(buffer);
				break;
			}
			case 5:
			{
				if (!RingBufferIsCreated(buffer)) break;
				if (buffer->FreeMemory == buffer->Size) break;
				cout << "Достали элемент: " << PopElement(buffer) << endl;
				PrintBuffer(buffer);
				break;
			}
			case 6:
				if (!RingBufferIsCreated(buffer)) break;
				AddNewElement(buffer);
				cout << "Новая ячейка успешно добавлена" << endl;
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
				cout << "Введено неверное значение. Попробуйте снова" << endl;
				break;
		}
	}
}

void MenuStack()
{
	Stack* stack = nullptr;
	
	while (true)
	{
		cout << "Выберите действие:" << endl;
		cout << "1. Создать стек" << endl;
		cout << "2. Добавить элемент в стек" << endl;
		cout << "3. Удалить элемент из стека" << endl;
		cout << "4. Увеличить размер стека" << endl;
		cout << "5. Вывести стек" << endl;
		cout << "0. Выход" << endl;
		int key = InputValue("");
		switch (key)
		{
			case 1:
			{
				if (StackIsCreated(stack))
				{
					cout << "Стек уже создан" << endl;
					break;
				}
				int size = InputValue("Введите размер стека");
				stack = InitStack(size);
				cout << "Стек успешно создан" << endl;
				PrintStack(stack);
				break;
			}
			case 2:
			{
				if (!StackIsCreated(stack)) break;
				int value = InputValue("Введите значение элемента");
				if (!PushStack(stack, value))
				{
					cout << "Стек переполнен" << endl;
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
				cout << "Введено неверное значение. Попробуйте снова" << endl;
				break;
		}
	}
}

void Menu()
{
	cout << "Добро пожаловать!" << endl;
	cout << "Выберите функцию из списка ниже" << endl;

	while (true)
	{
		cout << "1. Стек" << endl;
		cout << "2. Кольцевой буфер" << endl;
		cout << "3. Очередь на базе кольцевого буфера" << endl;
		cout << "4. Очередь на базе двух стеков" << endl;
		cout << "0. Выйти" << endl;

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
