#pragma once
#include "Chain.h"

/**
 * \brief Представляет реализацию по представлению структуры данных Хеш-таблица.
 */
struct HashTable
{
	/**
	 * \brief Число роста размера таблицы.
	 */
	const int GrowthFactor = 2;

	/**
	 * \brief Количество заполненных элементов.
	 */
	int CountFilledElements;

	/**
	 * \brief Размер.
	 */
	int Size;

	/**
	 * \brief Двумерный динамический массив цепочек.
	 */
	Chain** Array;

	/**
	 * \brief Создает экземпляр структуры HashTable.
	 */
	HashTable()
	{
		CountFilledElements = 0;
		Size = 4;
		Array = new Chain * [Size];
	}
};

/**
 * \brief Создает хеш-таблицу.
 * \param size Размер.
 * \return Возвращает хеш-таблицу.
 */
HashTable* CreateTable(int size);

/**
 * \brief Создает элемент.
 * \param key Ключ.
 * \param value Значение.
 * \return Возвращает элемент.
 */
Element* CreateElement(std::string key, std::string value);

/**
 * \brief Вставляет элемент в хеш-таблицу.
 * \param table Хеш-таблица.
 * \param element Элемент.
 * \param index Индекс.
 * \return Возвращает true, если элемент вставлен удачно, иначе false.
 */
bool InsertElement(HashTable* table, Element* element, int index);

/**
 * \brief Преобразует значение key в хеш-сумму.
 * \param key Ключ.
 * \param tableSize Размер таблицы.
 * \return Возвращает хеш-сумму.
 */
int HashFunc(std::string key, int tableSize);

/**
 * \brief Решение коллизий.
 * \param first Первый элемент.
 * \param element Элемент.
 */
void ResolveCollisions(Element* first, Element* element);

/**
 * \brief Удаляет элемент с заданным ключом.
 * \param table Таблица.
 * \param key Ключ.
 * \return Возвращает true, если элемент был удален успешно, иначе false.
 */
bool RemoveElement(HashTable* table, std::string key);

/**
 * \brief Производит перехеширование таблицы.
 * \param table Таблица.
 */
void Rehashing(HashTable& table);

/**
 * \brief Производит поиск элемента с заданным ключом.
 * \param table Таблица.
 * \param key Ключ.
 * \param data Данные.
 * \return Возвращает true, если элемент был найден, иначе false.
 */
bool FindElement(HashTable* table, std::string key, std::string& data);

/**
 * \brief Удаляет таблицу.
 * \param table Таблица.
 */
void DeleteTable(HashTable* table);

