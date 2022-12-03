#pragma once
#include "Element.h"

/**
 * \brief Представляет реализацию по представлению списка.
 */
struct List
{
	/**
	 * \brief Указатель на первый элемент списка.
	 */
	Element* Head;
	/**
	 * \brief Указатель на последний элемент списка.
	 */
	Element* Tail;
	/**
	 * \brief Количество элементов в списке.
	 */
	int Length;

	/**
	 * @brief Создает экземпляр структуры List.
	*/
	List()
	{
		Head = nullptr;
		Tail = nullptr;
		Length = 0;
	}
};

/**
 * \brief Вставляет элемент в начало списка.
 * \param list Список.
 * \param data Число.
 */
void InsertElementInFirstPosition(List* list, int data);

/**
 * \brief Вставляет элемент в конец списка.
 * \param list Список.
 * \param data Число.
 */
void InsertElementInLastPosition(List* list, int data);

/**
 * \brief Вставляет элемент после указанного индекса.
 * \param list Список.
 * \param data Число.
 * \param index Индекс.
 */
void InsertElementAfterPosition(List* list, int data, int index);

/**
 * \brief Вставляет элемент перед указанным индексом.
 * \param list Список.
 * \param data Число.
 * \param index Индекс.
 */
void InsertElementBeforePosition(List* list, int data, int index);

/**
 * \brief Удаляет элемент с указанным индексом.
 * \param list Список.
 * \param index Индекс.
 */
void RemoveElement(List* list, int index);

/**
 * \brief Сортирует список.
 * \param list Список.
 */
void SortList(List* list);

/**
 * \brief Меняет местами два элемента списка.
 * \param list Список.
 * \param one Первый элемент.
 * \param two Второй элемент.
 */
void SwapElements(List* list, Element* one, Element* two);

/**
 * \brief Заполняет список случайными числами.
 * \param list Список.
 * \param count Количество элементов.
 */
void GetRandomList(List* list, int count);

/**
 * \brief Производит линейный поиск элемента в списке.
 * \param list Список.
 * \param value Значение.
 * \return Возвращает индекс элемента со значением value.
 */
int LinearSearch(List* list, int value);