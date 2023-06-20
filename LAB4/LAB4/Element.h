#pragma once
#include <string>

/**
 * \brief Представляет реализацию по представлению элемента.
 */
struct Element
{
	/**
	 * \brief Ключ.
	 */
	std::string Key;

	/**
	 * \brief Значение.
	 */
	std::string Value;

	/**
	 * \brief Указатель на следующий элемент.
	 */
	Element* Next;
};
