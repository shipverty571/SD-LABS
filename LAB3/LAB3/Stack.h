#pragma once

/**
 * \brief Представляет реализацию по представлению стека.
 */
struct Stack
{
	/**
	 * \brief Буфер.
	 */
	int* Buffer;

	/**
	 * \brief Элемент вершины стека.
	 */
	int Top;

	/**
	 * \brief Емкость.
	 */
	int Capacity;

	/**
	 * \brief Число роста стека.
	 */
	const int GrowthFactor = 2;

	/**
	 * \brief Создает экземпляр класса Stack
	 */
	Stack()
	{
		Buffer = new int[4];
		Top = 0;
		Capacity = 4;
	}
};

/**
 * \brief Заполняет стек значениями.
 * \param size Размер.
 * \return Возвращает стек.
 */
Stack* InitStack(int size);

/**
 * \brief Вставляет элемент в стек.
 * \param stack Стек.
 * \param data Значение.
 * \return Возвращает true, если элемент был вставлен, иначе false.
 */
bool PushStack(Stack* stack, int data);

/**
 * \brief Вытаскивает элемент из стека.
 * \param stack Стек.
 * \return Возвращает значение достанного элемента.
 */
int PopStack(Stack* stack);

/**
 * \brief Удаляет стек.
 * \param stack Стек.
 */
void DeleteStack(Stack* stack);

/**
 * \brief Изменяет размер стека.
 * \param stack Стек.
 */
void Resize(Stack* stack);