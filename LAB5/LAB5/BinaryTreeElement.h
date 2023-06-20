#pragma once

/**
 * \brief Представляет реализацию по представлению элемента бинарного дерева.
 */
struct BinaryTreeElement
{
	/**
	 * \brief Указатель на левый элемент.
	 */
	BinaryTreeElement* Left;

	/**
	 * \brief Указатель на правый элемент.
	 */
	BinaryTreeElement* Right;

	/**
	 * \brief Значение.
	 */
	int Data;
};
