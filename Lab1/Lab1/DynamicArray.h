#pragma once

/**
 * \brief Представляет реализацию по представлению структуры данных "Динамический массив".
 */
struct DynamicArray
{
	/**
	 * \brief Массив.
	 */
	int* Array;
	/**
	 * \brief Емкость.
	 */
	int Capacity;
	/**
	 * \brief Длина.
	 */
	int Length;
	/**
	 * \brief Проверка сортировки.
	 */
	bool IsSorted = false;

	/**
	 * \brief Число роста размера массива.
	 */
	const int GrowthFactor = 2;

	/**
	 * \brief Создает экземпляр класса DynamicArray
	 */
	DynamicArray()
	{
		Capacity = 4;
		Length = 0;
		Array = new int[Capacity];
	}
};
/**
 * \brief Добавляет элемент в динамический массив.
 * \param dynamicArray Динамический массив.
 * \param value Значение элемента.
 */
void AddElement(DynamicArray* dynamicArray, int value);

/**
 * \brief Изменяет емкость динамического массива.
 * \param dynamicArray Динамический массив.
 */
void ResizeArray(DynamicArray* dynamicArray);

/**
 * \brief Заполнение динамического массива случайными значениями.
 * \param dynamicArray Динамический массив.
 * \param length Количество добавляемых элементов.
 */
void GetArrayRandom(DynamicArray* dynamicArray, int length);

/**
 * \brief Удаляет элемент из динамического массива.
 * \param dynamicArray Динамический массив.
 * \param index Индекс элемента.
 */
void RemoveElement(DynamicArray* dynamicArray, int index);

/**
 * \brief Вставляет элемент в определенную позицию в динамическом массиве.
 * \param dynamicArray Динамический массив.
 * \param value Значение элемента.
 * \param index Индекс элемента.
 */
void InsertElement(DynamicArray* dynamicArray, int value, int index);

/**
 * \brief Сортирует динамический массив.
 * \param dynamicArray Динамический массив.
 */
void SortArray(DynamicArray* dynamicArray);

/**
 * \brief Проводит линейный поиск элемента в динамическом массиве по значению.
 * \param dynamicArray Динамический массив.
 * \param value Значение элемента.
 * \return Возвращает индекс найденного элемента. 
 */
int LinearSearch(DynamicArray* dynamicArray, int value);

/**
 * \brief Проводит бинарный поиск элемента в динамическом массиве по значению.
 * \param dynamicArray Динамический массив.
 * \param value Значение элемента.
 * \return Возвращает индекс найденного элемента.
 */
int BinarySearch(DynamicArray* dynamicArray, int value);