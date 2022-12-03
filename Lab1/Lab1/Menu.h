#pragma once
#include "DynamicArray.h"

/**
 * \brief �������� ����.
 * \param dynamicArray ������������ ������.
 */
void Menu(DynamicArray* dynamicArray);

/**
 * \brief ������� ������������ ������.
 * \param dynamicArray ������������ ������.
 */
void CreateArrayFromMenu(DynamicArray* dynamicArray);

/**
 * \brief ������� ��� ����������� ����� �����.
 * \return ���������� �����.
 */
int InputValue();

/**
 * \brief ��������� ������� � ������������ ������.
 * \param dynamicArray ������������ ������.
 */
void AddElementFromMenu(DynamicArray* dynamicArray);

/**
 * \brief �������� ������������ ������.
 * \param dynamicArray ������������� ������.
 */
void ShowArrayFromMenu(DynamicArray* dynamicArray);

/**
 * \brief ������� ������� �� ������������� �������.
 * \param dynamicArray ����������� ������.
 */
void RemoveElementFromMenu(DynamicArray* dynamicArray);

/**
 * \brief ��������� ������� � ������������ ������.
 * \param dynamicArray ������������ ������.
 */
void InsertElementFromMenu(DynamicArray* dynamicArray);

/**
 * \brief ��������� ������������ ������.
 * \param dynamicArray ������������ ������.
 */
void SortArrayFromMenu(DynamicArray* dynamicArray);

/**
 * \brief ���������� �������� ����� � ������������ �������.
 * \param dynamicArray ������������ ������.
 */
void LinearSearchFromMenu(DynamicArray* dynamicArray);

/**
 * \brief ���������� �������� ����� � ������������ �������.
 * \param dynamicArray ������������ ������.
 */
void BinarySearchFromMenu(DynamicArray* dynamicArray);

/**
 * \brief ��������� ������������� �������������� �������.
 * \param dynamicArray ����������� ������.
 * \return ���������� true, ���� ������ ���������������, ����� false.
 */
bool DynamicArrayIsCreated(DynamicArray* dynamicArray);
