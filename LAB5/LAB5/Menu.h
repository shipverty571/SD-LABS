#pragma once
#include <string>
#include "BinaryTreeElement.h"
#include "TreapElement.h"

/**
 * \brief Функция для корректного ввода числа.
 * \param Строка для вывода информации.
 * \return Возвращает число.
 */
int InputValue(std::string outputString);

/**
 * \brief Меню бинарного дерева.
 */
void MenuBinaryTree();

/**
 * \brief Меню декартово дерева.
 */
void MenuTreap();

/**
 * \brief Основное меню.
 */
void Menu();

/**
 * \brief Выводит бинарное дерево.
 * \param current Стартовый элемент.
 * \param level Уровень.
 */
void PrintBinaryTree(BinaryTreeElement* current, int level);

/**
 * \brief Выводит декартово дерево.
 * \param current Стартовый элемент.
 * \param level Уровень.
 */
void PrintTreap(TreapElement* current, int level);

/**
 * \brief Проверяет наличие элемента со значением в дереве.
 * \param value Значение.
 * \param tree Дерево.
 * \return Возвращает true, если такой элемент есть, иначе false.
 */
bool CheckElement(int value, TreapElement* tree);