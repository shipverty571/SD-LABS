#pragma once
#include "HashTable.h"

/**
 * \brief Представляет структуру данных Словарь.
 */
struct Dictionary
{
	/**
	 * \brief Таблица.
	 */
	HashTable* Table;

	/**
	 * \brief Создает экземпляр структуры Dictionary.
	 */
	Dictionary()
	{
		Table = CreateTable(4);
	}
};

/**
 * \brief Вставляет элемент в словарь.
 * \param dictionary Словарь.
 * \param element Элемент.
 * \param key Ключ.
 * \return Возвращает true, если элемент был вставлен успешно, иначе false.
 */
bool InsertElement(Dictionary* dictionary, Element* element, std::string key);

/**
 * \brief Удаляет элемент из словаря.
 * \param dictionary Словарь.
 * \param key Ключ.
 * \return Возвращает true, если элемент был удален успешно, иначе false.
 */
bool RemoveElement(Dictionary* dictionary, std::string key);

/**
 * \brief Производит поиск элемента по ключу.
 * \param dictionary Словарь.
 * \param key Ключ.
 * \param data Данные.
 * \return Возвращает true, если элемент был найден, иначе false.
 */
bool FindElement(Dictionary* dictionary, std::string key, std::string& data);

/**
 * \brief Удаляет словарь.
 * \param dictionary Словарь.
 */
void DeleteDictionary(Dictionary* dictionary);