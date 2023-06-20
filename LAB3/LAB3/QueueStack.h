#pragma once
#include "Stack.h"

/**
 * \brief ������������ ���������� �� ������������� ������� �� ���� ���� ������.
 */
struct QueueStack
{
	/**
	 * \brief ������ ����.
	 */
	Stack* InStack;

	/**
	 * \brief ������ ����.
	 */
	Stack* OutStack;

	/**
	 * \brief ������� ��������� ������ QueueStack
	 */
	QueueStack()
	{
		InStack = new Stack;
		OutStack = new Stack;
	}
};

/**
 * \brief ��������� ������� � �������.
 * \param queue �������.
 * \param value ��������.
 * \return ���������� true, ���� ������� ��� ��������, ����� false.
 */
bool Enqueue(QueueStack* queue, int value);

/**
 * \brief ����������� ������� �� �������.
 * \param queue �������.
 * \param value ��������.
 * \return ���������� true, ���� ������� ������, ����� false.
 */
bool Dequeue(QueueStack* queue, int& value);

/**
 * \brief �������� ������ �����.
 * \param queue ����.
 */
void ResizeQueue(QueueStack* queue);

/**
 * \brief ������� ����.
 * \param queue ����.
 */
void DeleteQueue(QueueStack* queue);

