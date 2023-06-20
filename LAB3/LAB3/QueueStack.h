#pragma once
#include "Stack.h"

/**
 * \brief Представляет реализацию по представлению очереди на базе двух стеков.
 */
struct QueueStack
{
	/**
	 * \brief Первый стек.
	 */
	Stack* InStack;

	/**
	 * \brief Второй стек.
	 */
	Stack* OutStack;

	/**
	 * \brief Создает экземпляр класса QueueStack
	 */
	QueueStack()
	{
		InStack = new Stack;
		OutStack = new Stack;
	}
};

/**
 * \brief Вставляет элемент в очередь.
 * \param queue Очередь.
 * \param value Значение.
 * \return Возвращает true, если элемент был вставлен, иначе false.
 */
bool Enqueue(QueueStack* queue, int value);

/**
 * \brief Вытаскивает элемент из очереди.
 * \param queue Очередь.
 * \param value Значение.
 * \return Возвращает true, если элемент достан, иначе false.
 */
bool Dequeue(QueueStack* queue, int& value);

/**
 * \brief Изменяет размер стека.
 * \param queue Стек.
 */
void ResizeQueue(QueueStack* queue);

/**
 * \brief Удаляет стек.
 * \param queue Стек.
 */
void DeleteQueue(QueueStack* queue);

