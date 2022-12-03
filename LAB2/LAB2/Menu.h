#pragma once
#include "List.h"
#include <string>

/**
 * \brief ���������� ����.
 * \param list ��������� �� ������.
 */
void Menu(List* list);

/**
 * \brief ������������ ��� ����� �����.
 * \return ���������� ��������� �����.
 */
int InputValue(std::string outputString);

/**
 * \brief ��������� ��������� �����.
 * \param list	��������� �� ������.
 * \param index ������.
 * \return ���������� true, ���� ����� ������� �����, ����� false.
 */
bool IndexValidator(List* list, int index);

/**
 * \brief �������������� ������.
 * \param list ��������� �� ������.
 */
void CreateListFromMenu(List* list);

/**
 * \brief ��������� ������� � ������ ������.
 * \param list ��������� �� ������.
 */
void InsertElementInFirstPositionFromMenu(List* list);

/**
 * \brief ��������� ������� � ����� ������.
 * \param list ��������� �� ������.
 */
void InsertElementInLastPositionFromMenu(List* list);

/**
 * \brief ��������� ������� ����� ���������� �������.
 * \param list ��������� �� ������.
 */
void InsertElementAfterPositionFromMenu(List* list);

/**
 * \brief ��������� ������� ����� ��������� ��������.
 * \param list ��������� �� ������.
 */
void InsertElementBeforePositionFromMenu(List* list);

/**
 * \brief ������� ������� �� ������.
 * \param list ��������� �� ������.
 */
void RemoveElementFromMenu(List* list);

/**
 * \brief ��������� ������.
 * \param list ��������� �� ������.
 */
void SortListFromMenu(List* list);

/**
 * \brief ���������� ������.
 * \param list ��������� �� ������.
 */
void ShowListFromMenu(List* list);

/**
 * \brief ���������� �������� �����.
 * \param list ��������� �� ������.
 */
void LinearSearchFromMenu(List* list);