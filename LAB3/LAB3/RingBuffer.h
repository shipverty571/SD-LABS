#pragma once

/**
 * \brief Представляет реализацию по представлению элемента буфера.
 */
struct Element
{
	/**
	 * \brief Хранит true, если есть значение Data, иначе false.
	 */
	bool IsHaveData;

	/**
	 * \brief Значение.
	 */
	int Data;

	/**
	 * \brief Указатель на следующий элемент.
	 */
	Element* Next;
};

/**
 * \brief Представляет реализацию по представлению кольцевого буфера.
 */
struct RingBuffer
{
	/**
	 * \brief Размер.
	 */
	int Size;

	/**
	 * \brief Использованное место.
	 */
	int UsedMemory;

	/**
	 * \brief Свободное место.
	 */
	int FreeMemory;

	/**
	 * \brief Головной элемент.
	 */
	Element* Head;

	/**
	 * \brief Указатель вывода.
	 */
	Element* IndexOutput;

	/**
	 * \brief Указатель ввода.
	 */
	Element* IndexInput;
};

/**
 * \brief Создает кольцевой буфер.
 * \param buffer Буфер.
 * \param size Размер.
 */
void CreateRingBuffer(RingBuffer* buffer, int size);

/**
 * \brief Информация по свободному месту.
 * \param buffer Буфер.
 * \return Возвращает количество свободного места в буфере.
 */
int FreeMemoryInfo(RingBuffer* buffer);

/**
 * \brief Информация по занятому месту.
 * \param buffer Буфер.
 * \return Возвращает количество занятого места в буфере.
 */
int UsedMemoryInfo(RingBuffer* buffer);

/**
 * \brief Вставляет элемент в буфер.
 * \param buffer Буфер.
 * \param data Значение.
 */
void PushElement(RingBuffer* buffer, int data);

/**
 * \brief Вытаскивает элемент из буфера.
 * \param buffer Буфер.
 * \return Возвращает значение достанного элемента.
 */
int PopElement(RingBuffer* buffer);

/**
 * \brief Добавляет новую ячейку в буфер.
 * \param buffer Буфер.
 */
void AddNewElement(RingBuffer* buffer);

/**
 * \brief Удаляет буфер.
 * \param buffer Буфер.
 */
void DeleteBuffer(RingBuffer* buffer);
