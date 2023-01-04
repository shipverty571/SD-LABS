#pragma once
#include "Chain.h"

/**
 * \brief ������������ ���������� �� ������������� ��������� ������ ���-�������.
 */
struct HashTable
{
	/**
	 * \brief ����� ����� ������� �������.
	 */
	const int GrowthFactor = 2;

	/**
	 * \brief ���������� ����������� ���������.
	 */
	int CountFilledElements;

	/**
	 * \brief ������.
	 */
	int Size;

	/**
	 * \brief ��������� ������������ ������ �������.
	 */
	Chain** Array;

	/**
	 * \brief ������� ��������� ��������� HashTable.
	 */
	HashTable()
	{
		CountFilledElements = 0;
		Size = 4;
		Array = new Chain * [Size];
	}
};

/**
 * \brief ������� ���-�������.
 * \param size ������.
 * \return ���������� ���-�������.
 */
HashTable* CreateTable(int size);

/**
 * \brief ������� �������.
 * \param key ����.
 * \param value ��������.
 * \return ���������� �������.
 */
Element* CreateElement(std::string key, std::string value);

/**
 * \brief ��������� ������� � ���-�������.
 * \param table ���-�������.
 * \param element �������.
 * \param index ������.
 * \return ���������� true, ���� ������� �������� ������, ����� false.
 */
bool InsertElement(HashTable* table, Element* element, int index);

/**
 * \brief ����������� �������� key � ���-�����.
 * \param key ����.
 * \param tableSize ������ �������.
 * \return ���������� ���-�����.
 */
int HashFunc(std::string key, int tableSize);

/**
 * \brief ������� ��������.
 * \param first ������ �������.
 * \param element �������.
 */
void ResolveCollisions(Element* first, Element* element);

/**
 * \brief ������� ������� � �������� ������.
 * \param table �������.
 * \param key ����.
 * \return ���������� true, ���� ������� ��� ������ �������, ����� false.
 */
bool RemoveElement(HashTable* table, std::string key);

/**
 * \brief ���������� ��������������� �������.
 * \param table �������.
 */
void Rehashing(HashTable& table);

/**
 * \brief ���������� ����� �������� � �������� ������.
 * \param table �������.
 * \param key ����.
 * \param data ������.
 * \return ���������� true, ���� ������� ��� ������, ����� false.
 */
bool FindElement(HashTable* table, std::string key, std::string& data);

/**
 * \brief ������� �������.
 * \param table �������.
 */
void DeleteTable(HashTable* table);

