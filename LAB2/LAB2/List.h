#pragma once
#include "Element.h"

/**
 * \brief ������������ ���������� �� ������������� ������.
 */
struct List
{
	/**
	 * \brief ��������� �� ������ ������� ������.
	 */
	Element* Head;
	/**
	 * \brief ��������� �� ��������� ������� ������.
	 */
	Element* Tail;
	/**
	 * \brief ���������� ��������� � ������.
	 */
	int Length;

	/**
	 * @brief ������� ��������� ��������� List.
	*/
	List()
	{
		Head = nullptr;
		Tail = nullptr;
		Length = 0;
	}
};

/**
 * \brief ��������� ������� � ������ ������.
 * \param list ������.
 * \param data �����.
 */
void InsertElementInFirstPosition(List* list, int data);

/**
 * \brief ��������� ������� � ����� ������.
 * \param list ������.
 * \param data �����.
 */
void InsertElementInLastPosition(List* list, int data);

/**
 * \brief ��������� ������� ����� ���������� �������.
 * \param list ������.
 * \param data �����.
 * \param index ������.
 */
void InsertElementAfterPosition(List* list, int data, int index);

/**
 * \brief ��������� ������� ����� ��������� ��������.
 * \param list ������.
 * \param data �����.
 * \param index ������.
 */
void InsertElementBeforePosition(List* list, int data, int index);

/**
 * \brief ������� ������� � ��������� ��������.
 * \param list ������.
 * \param index ������.
 */
void RemoveElement(List* list, int index);

/**
 * \brief ��������� ������.
 * \param list ������.
 */
void SortList(List* list);

/**
 * \brief ������ ������� ��� �������� ������.
 * \param list ������.
 * \param one ������ �������.
 * \param two ������ �������.
 */
void SwapElements(List* list, Element* one, Element* two);

/**
 * \brief ��������� ������ ���������� �������.
 * \param list ������.
 * \param count ���������� ���������.
 */
void GetRandomList(List* list, int count);

/**
 * \brief ���������� �������� ����� �������� � ������.
 * \param list ������.
 * \param value ��������.
 * \return ���������� ������ �������� �� ��������� value.
 */
int LinearSearch(List* list, int value);