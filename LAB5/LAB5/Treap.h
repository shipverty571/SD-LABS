#pragma once
#include "TreapElement.h"

/**
 * \brief Представляет реализацию по представлению декартова дерева.
 */
struct Treap
{
	/**
	 * \brief Максимальное число приоритета.
	 */
	const int MaxPriority = 100;

	/**
	 * \brief Корень дерева.
	 */
	TreapElement* Root;

	/**
	 * \brief Создает экземпляр структуры Treap.
	 */
	Treap()
	{
		Root = nullptr;
	}
};

/**
 * \brief Инициализирует дерево.
 * \return Возвращает дерево.
 */
Treap* Initialize();

/**
 * \brief Вставляет элемент в дерево.
 * \param treap Дерево.
 * \param element Элемент.
 */
void InsertElement(Treap* treap, TreapElement* element);

/**
 * \brief Осуществляет поиск родителя элемента.
 * \param currentElement Элемент.
 * \param data Значение.
 * \return Возвращает родителя.
 */
TreapElement* SearchParentElement(TreapElement* currentElement, int data);

/**
 * \brief Разрезает ветвь на две части.
 * \param key Значение.
 * \param current Элемент.
 * \param left Ссылка на левый элемент.
 * \param right Ссылка на правый элемент.
 */
void Split(TreapElement* tree, int key, TreapElement*& left, TreapElement*& right);

/**
 * \brief Соединяет две части ветви.
 * \param left Левая часть.
 * \param right Правая часть.
 */
void Merge(TreapElement*& tree, TreapElement* left, TreapElement* right);

/**
 * \brief Осуществляет поиск элемента по значению.
 * \param current Элемент.
 * \param value Значение.
 * \return Возвращает найденный элемент.
 */
TreapElement* SearchElementByValue(TreapElement* current, int value);

/**
 * \brief Вставка не оптимизированным способом.
 * \param root Корень.
 * \param value Значение.
 */
void InsertNotOpt(TreapElement*& root, int value);

/**
 * \brief Вставка оптимизированным способом.
 * \param value Значение.
 * \param priority Приоритет.
 * \param current Элемент.
 */
void InsertOpt(int value, int priority, TreapElement*& current);

/**
 * \brief Удаление не оптимизированным способом.
 * \param root Корень.
 * \param value Значение.
 * \return Возвращает true, если элемент был удален, иначе false.
 */
void DeleteNotOpt(TreapElement*& root, int value);

/**
 * \brief Удаление оптимизированным способом.
 * \param value Значение.
 * \param current Элемент.
 */
void DeleteOpt(int value, TreapElement*& current);

/**
 * \brief Удаляет дерево.
 * \param current Элемент.
 */
void DeleteTreap(TreapElement* current);
