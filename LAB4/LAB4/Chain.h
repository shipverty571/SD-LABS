#pragma once
#include "Element.h"

/**
 * \brief Представляет структуру данных цепочки.
 */
struct Chain
{
	/**
	 * \brief Элемент "Голова".
	 */
	Element* Head;

	/**
	 * \brief Размер.
	 */
	int Size;
};