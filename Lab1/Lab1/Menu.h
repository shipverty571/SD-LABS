#pragma once
#include "DynamicArray.h"

/**
 * \brief Вызывает меню.
 * \param dynamicArray Динамический массив.
 */
void Menu(DynamicArray* dynamicArray);

/**
 * \brief Создает динамический массив.
 * \param dynamicArray Динамический массив.
 */
void CreateArrayFromMenu(DynamicArray* dynamicArray);

/**
 * \brief Функция для корректного ввода числа.
 * \return Возвращает число.
 */
int InputValue();

/**
 * \brief Добавляет элемент в динамический массив.
 * \param dynamicArray Динамический массив.
 */
void AddElementFromMenu(DynamicArray* dynamicArray);

/**
 * \brief Печатает динамический массив.
 * \param dynamicArray Динаамический массив.
 */
void ShowArrayFromMenu(DynamicArray* dynamicArray);

/**
 * \brief Удаляет элемент из динамического массива.
 * \param dynamicArray Динамиеский массив.
 */
void RemoveElementFromMenu(DynamicArray* dynamicArray);

/**
 * \brief Вставляет элемент в динамический массив.
 * \param dynamicArray Динамический массив.
 */
void InsertElementFromMenu(DynamicArray* dynamicArray);

/**
 * \brief Сортирует динамический массив.
 * \param dynamicArray Динамический массив.
 */
void SortArrayFromMenu(DynamicArray* dynamicArray);

/**
 * \brief Производит линейный поиск в динамическом массиве.
 * \param dynamicArray Динамический массив.
 */
void LinearSearchFromMenu(DynamicArray* dynamicArray);

/**
 * \brief Производит бинарный поиск в динамическом массиве.
 * \param dynamicArray Динамический массив.
 */
void BinarySearchFromMenu(DynamicArray* dynamicArray);

/**
 * \brief Проверяет инициализацию динаамического массива.
 * \param dynamicArray Динамиеский массив.
 * \return Возвращает true, если массив инициализирован, иначе false.
 */
bool DynamicArrayIsCreated(DynamicArray* dynamicArray);
