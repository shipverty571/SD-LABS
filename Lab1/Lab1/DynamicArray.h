#pragma once

/**
 * \brief ������������ ���������� �� ������������� ��������� ������ "������������ ������".
 */
struct DynamicArray
{
	/**
	 * \brief ������.
	 */
	int* Array;
	/**
	 * \brief �������.
	 */
	int Capacity;
	/**
	 * \brief �����.
	 */
	int Length;
	/**
	 * \brief �������� ����������.
	 */
	bool IsSorted = false;

	/**
	 * \brief ����� ����� ������� �������.
	 */
	const int GrowthFactor = 2;

	/**
	 * \brief ������� ��������� ������ DynamicArray
	 */
	DynamicArray()
	{
		Capacity = 4;
		Length = 0;
		Array = new int[Capacity];
	}
};
/**
 * \brief ��������� ������� � ������������ ������.
 * \param dynamicArray ������������ ������.
 * \param value �������� ��������.
 */
void AddElement(DynamicArray* dynamicArray, int value);

/**
 * \brief �������� ������� ������������� �������.
 * \param dynamicArray ������������ ������.
 */
void ResizeArray(DynamicArray* dynamicArray);

/**
 * \brief ���������� ������������� ������� ���������� ����������.
 * \param dynamicArray ������������ ������.
 * \param length ���������� ����������� ���������.
 */
void GetArrayRandom(DynamicArray* dynamicArray, int length);

/**
 * \brief ������� ������� �� ������������� �������.
 * \param dynamicArray ������������ ������.
 * \param index ������ ��������.
 */
void RemoveElement(DynamicArray* dynamicArray, int index);

/**
 * \brief ��������� ������� � ������������ ������� � ������������ �������.
 * \param dynamicArray ������������ ������.
 * \param value �������� ��������.
 * \param index ������ ��������.
 */
void InsertElement(DynamicArray* dynamicArray, int value, int index);

/**
 * \brief ��������� ������������ ������.
 * \param dynamicArray ������������ ������.
 */
void SortArray(DynamicArray* dynamicArray);

/**
 * \brief �������� �������� ����� �������� � ������������ ������� �� ��������.
 * \param dynamicArray ������������ ������.
 * \param value �������� ��������.
 * \return ���������� ������ ���������� ��������. 
 */
int LinearSearch(DynamicArray* dynamicArray, int value);

/**
 * \brief �������� �������� ����� �������� � ������������ ������� �� ��������.
 * \param dynamicArray ������������ ������.
 * \param value �������� ��������.
 * \return ���������� ������ ���������� ��������.
 */
int BinarySearch(DynamicArray* dynamicArray, int value);