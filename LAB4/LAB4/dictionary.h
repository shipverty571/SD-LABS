#pragma once
#include "HashTable.h"

/**
 * \brief ������������ ��������� ������ �������.
 */
struct Dictionary
{
	/**
	 * \brief �������.
	 */
	HashTable* Table;

	/**
	 * \brief ������� ��������� ��������� Dictionary.
	 */
	Dictionary()
	{
		Table = CreateTable(4);
	}
};

/**
 * \brief ��������� ������� � �������.
 * \param dictionary �������.
 * \param element �������.
 * \param key ����.
 * \return ���������� true, ���� ������� ��� �������� �������, ����� false.
 */
bool InsertElement(Dictionary* dictionary, Element* element, std::string key);

/**
 * \brief ������� ������� �� �������.
 * \param dictionary �������.
 * \param key ����.
 * \return ���������� true, ���� ������� ��� ������ �������, ����� false.
 */
bool RemoveElement(Dictionary* dictionary, std::string key);

/**
 * \brief ���������� ����� �������� �� �����.
 * \param dictionary �������.
 * \param key ����.
 * \param data ������.
 * \return ���������� true, ���� ������� ��� ������, ����� false.
 */
bool FindElement(Dictionary* dictionary, std::string key, std::string& data);

/**
 * \brief ������� �������.
 * \param dictionary �������.
 */
void DeleteDictionary(Dictionary* dictionary);