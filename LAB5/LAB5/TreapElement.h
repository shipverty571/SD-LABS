#pragma once

/**
 * \brief Представляет реализацию по представлению элемента декартово дерева.
 */
struct TreapElement
{
	/**
	 * \brief Указатель на левый элемент.
	 */
	TreapElement* Left;

	/**
	 * \brief Указатель на правый элемент.
	 */
	TreapElement* Right;

	/**
	 * \brief Значение.
	 */
	int Data;

	/**
	 * \brief Приоритет.
	 */
	int Priority;
};
