#pragma once
#include "BinaryTreeElement.h"

/**
 * \brief Представляет реализацию по представлению бинарного дерева.
 */
struct BinaryTree
{
	/**
	 * \brief Корень дерева.
	 */
	BinaryTreeElement* Root;

	/**
	 * \brief Создает экземпляр структуры BinaryTree.
	 */
	BinaryTree()
	{
		Root = nullptr;
	}
};

/**
 * \brief Создает элемент дерева.
 * \param data Значение.
 * \return ВОзвращает элемент дерева.
 */
BinaryTreeElement* CreateElement(int data);

/**
 * \brief Вставляет элемент в дерево.
 * \param binaryTree Дерево.
 * \param element Элемент.
 */
void InsertElement(BinaryTree* binaryTree, BinaryTreeElement* element);

/**
 * \brief Поиск родителя элемента.
 * \param currentElement Элемент.
 * \param data Значение.
 * \return Возвращает найденного родителя.
 */
BinaryTreeElement* SearchParentElement(BinaryTreeElement* currentElement, int data);

/**
 * \brief Удаляет элемент дерева.
 * \param binaryTree Дерево.
 * \param value Значение.
 * \return Возвращает удаленный элемент.
 */
BinaryTreeElement* DeleteElement(BinaryTreeElement* binaryTree, int value);

/**
 * \brief Поиск минимального элемента.
 * \param current Элемент.
 * \return Возвращает минимальный элемент.
 */
BinaryTreeElement* SearchMinElement(BinaryTreeElement* current);

/**
 * \brief Поиск максимального элемента.
 * \param current Элемент.
 * \return Возвращает максимальный элемент.
 */
BinaryTreeElement* SearchMaxElement(BinaryTreeElement* current);

/**
 * \brief Поиск элемента по значению.
 * \param current Элемент.
 * \param value Значение.
 * \return Возвращает найденный элемент.
 */
BinaryTreeElement* SearchElementByValue(BinaryTreeElement* current, int value);

/**
 * \brief Удаляет дерево.
 * \param current Стартовый элемент.
 */
void DeleteBinaryTree(BinaryTreeElement* current);
