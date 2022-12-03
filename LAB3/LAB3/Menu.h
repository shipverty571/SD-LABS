#pragma once	
#include <string>
#include "QueueRingBuffer.h"
#include "QueueStack.h"
#include "RingBuffer.h"
#include "Stack.h"

/**
 * \brief �������� �������� ����.
 */
void Menu();

/**
 * \brief �������� ���� ��� ������ �� ������.
 */
void MenuStack();

/**
 * \brief �������� ���� ��� ������ � ��������� �������.
 */
void MenuRingBuffer();

/**
 * \brief �������� ���� ��� ������ � �������� �� ���� ���������� ������.
 */
void MenuQueueRingBuffer();

/**
 * \brief �������� ���� ��� ������ � �������� �� ���� ���� ������.
 */
void MenuQueueStack();

/**
 * \brief ������� ���� �� �����.
 * \param stack ����.
 */
void PrintStack(Stack* stack);

/**
 * \brief ������� ��������� ����� �� �����.
 * \param buffer ��������� �����.
 */
void PrintBuffer(RingBuffer* buffer);

/**
 * \brief ������� ������� �� �����.
 * \param queue ������� �� ���� ���� ������.
 */
void PrintQueueStack(QueueStack* queue);

/**
 * \brief ���������, ������ �� ����.
 * \param stack ����.
 * \return ���������� true, ���� ���� ������, ����� false.
 */
bool StackIsCreated(Stack* stack);

/**
 * \brief ���������, ������ �� ��������� �����.
 * \param buffer ��������� �����.
 * \return ���������� true, ���� ��������� ����� ������, ����� false.
 */
bool RingBufferIsCreated(RingBuffer* buffer);

/**
 * \brief ���������, ������� �� ������� �� ���� ���������� ������.
 * \param queue ������� �� ���� ���������� ������.
 * \return ���������� true, ���� ������� �������, ����� false.
 */
bool QueueRingBufferIsCreated(QueueRingBuffer* queue);

/**
 * \brief ���������, ������� �� ������� �� ���� ���� ������.
 * \param queue ������� �� ���� ���� ������.
 * \return ���������� true, ���� ������� �������, ����� false.
 */
bool QueueStackIsCreated(QueueStack* queue);

/**
 * \brief ������������ �������� ����� ������� ���������� ������.
 * \return ������.
 */
int RingBufferSize();

/**
 * \brief ������������ ��� ����� �����.
 * \param outputString ������ ��� ������.
 * \return ���������� ��������� �����.
 */
int InputValue(std::string outputString);
