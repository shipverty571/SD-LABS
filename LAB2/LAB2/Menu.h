#pragma once
#include "List.h"
#include <string>

/**
 * \brief Показывает меню.
 * \param list Указатель на список.
 */
void Menu(List* list);

/**
 * \brief Используется для ввода числа.
 * \return Возвращает введенное число.
 */
int InputValue(std::string outputString);

/**
 * \brief Проверяет введенное число.
 * \param list	Указатель на список.
 * \param index Индекс.
 * \return Возвращает true, если число введено верно, иначе false.
 */
bool IndexValidator(List* list, int index);

/**
 * \brief Инициализирует список.
 * \param list Указатель на список.
 */
void CreateListFromMenu(List* list);

/**
 * \brief Вставляет элемент в начало списка.
 * \param list Указатель на список.
 */
void InsertElementInFirstPositionFromMenu(List* list);

/**
 * \brief Вставляет элемент в конец списка.
 * \param list Указатель на список.
 */
void InsertElementInLastPositionFromMenu(List* list);

/**
 * \brief Вставляет элемент после указанного индекса.
 * \param list Указатель на список.
 */
void InsertElementAfterPositionFromMenu(List* list);

/**
 * \brief Вставляет элемент перед указанным индексом.
 * \param list Указатель на список.
 */
void InsertElementBeforePositionFromMenu(List* list);

/**
 * \brief Удаляет элемент из списка.
 * \param list Указатель на список.
 */
void RemoveElementFromMenu(List* list);

/**
 * \brief Сортирует список.
 * \param list Указатель на список.
 */
void SortListFromMenu(List* list);

/**
 * \brief Показывает список.
 * \param list Указатель на список.
 */
void ShowListFromMenu(List* list);

/**
 * \brief Производит линейный поиск.
 * \param list Указатель на список.
 */
void LinearSearchFromMenu(List* list);