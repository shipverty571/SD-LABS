#pragma once
#include "TreapElement.h"

/**
 * \brief ������������ ���������� �� ������������� ��������� ������.
 */
struct Treap
{
	/**
	 * \brief ������������ ����� ����������.
	 */
	const int MaxPriority = 100;

	/**
	 * \brief ������ ������.
	 */
	TreapElement* Root;

	/**
	 * \brief ������� ��������� ��������� Treap.
	 */
	Treap()
	{
		Root = nullptr;
	}
};

/**
 * \brief �������������� ������.
 * \return ���������� ������.
 */
Treap* Initialize();

/**
 * \brief ��������� ������� � ������.
 * \param treap ������.
 * \param element �������.
 */
void InsertElement(Treap* treap, TreapElement* element);

/**
 * \brief ������������ ����� �������� ��������.
 * \param currentElement �������.
 * \param data ��������.
 * \return ���������� ��������.
 */
TreapElement* SearchParentElement(TreapElement* currentElement, int data);

/**
 * \brief ��������� ����� �� ��� �����.
 * \param key ��������.
 * \param current �������.
 * \param left ������ �� ����� �������.
 * \param right ������ �� ������ �������.
 */
void Split(TreapElement* tree, int key, TreapElement*& left, TreapElement*& right);

/**
 * \brief ��������� ��� ����� �����.
 * \param left ����� �����.
 * \param right ������ �����.
 */
void Merge(TreapElement*& tree, TreapElement* left, TreapElement* right);

/**
 * \brief ������������ ����� �������� �� ��������.
 * \param current �������.
 * \param value ��������.
 * \return ���������� ��������� �������.
 */
TreapElement* SearchElementByValue(TreapElement* current, int value);

/**
 * \brief ������� �� ���������������� ��������.
 * \param root ������.
 * \param value ��������.
 */
void InsertNotOpt(TreapElement*& root, int value);

/**
 * \brief ������� ���������������� ��������.
 * \param value ��������.
 * \param priority ���������.
 * \param current �������.
 */
void InsertOpt(int value, int priority, TreapElement*& current);

/**
 * \brief �������� �� ���������������� ��������.
 * \param root ������.
 * \param value ��������.
 * \return ���������� true, ���� ������� ��� ������, ����� false.
 */
void DeleteNotOpt(TreapElement*& root, int value);

/**
 * \brief �������� ���������������� ��������.
 * \param value ��������.
 * \param current �������.
 */
void DeleteOpt(int value, TreapElement*& current);

/**
 * \brief ������� ������.
 * \param current �������.
 */
void DeleteTreap(TreapElement* current);
