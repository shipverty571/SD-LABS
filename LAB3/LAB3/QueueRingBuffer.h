#pragma once
#include "RingBuffer.h"

/**
 * \brief ������������ ���������� �� ������������� ������� �� ���� ���������� ������.
 */
struct QueueRingBuffer
{
	/**
	 * \brief �����.
	 */
	RingBuffer* Buffer;
};

/**
 * \brief ������� ������� �� ���� ���������� ������.
 * \param queue �������.
 * \param size ������ �������.
 */
void CreateQueueBuffer(QueueRingBuffer* queue, int size);

/**
 * \brief ��������� ������� � �������.
 * \param queue �������.
 * \param value �������� ��������.
 */
void EnqueueBuffer(QueueRingBuffer* queue, int value);

/**
 * \brief ��������� ������� �� �������.
 * \param queue �������.
 * \return ���������� �������� ��������.
 */
int DequeueBuffer(QueueRingBuffer* queue);

/**
 * \brief �������� �������.
 * \param queue �������.
 */
void DeleteQueue(QueueRingBuffer* queue);
