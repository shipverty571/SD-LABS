#pragma once
#include "RingBuffer.h"

/**
 * \brief Представляет реализацию по представлению очереди на базе кольцевого буфера.
 */
struct QueueRingBuffer
{
	/**
	 * \brief Буфер.
	 */
	RingBuffer* Buffer;
};

/**
 * \brief Создает очередь на базе кольцевого буфера.
 * \param queue Очередь.
 * \param size Размер очереди.
 */
void CreateQueueBuffer(QueueRingBuffer* queue, int size);

/**
 * \brief Вставляет элемент в очередь.
 * \param queue Очередь.
 * \param value Значение элемента.
 */
void EnqueueBuffer(QueueRingBuffer* queue, int value);

/**
 * \brief Извлекает элемент из очереди.
 * \param queue Очередь.
 * \return Возвращает значение элемента.
 */
int DequeueBuffer(QueueRingBuffer* queue);

/**
 * \brief Удаление очереди.
 * \param queue Очередь.
 */
void DeleteQueue(QueueRingBuffer* queue);
