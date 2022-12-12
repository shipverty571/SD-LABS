#pragma once
#include "HashTable.h"

/**
 * \brief ���� ��� ���-�������.
 */
void MenuHashTable();

/**
 * \brief ���� ��� �������.
 */
void MenuDictionary();

/**
 * \brief ������� ��� ����������� ����� �����.
 * \param ������ ��� ������ ����������.
 * \return ���������� �����
 */
int InputValue(std::string outputString);

/**
 * \brief ������� ��� ����� ������.
 * \param outputString ������ ��� ������ ����������.
 * \return ���������� ������.
 */
std::string InputString(std::string outputString);

/**
 * \brief ������� �� ����� ���-�������.
 * \param table �������.
 */
void PrintHashTable(HashTable* table);

/**
 * \brief �������� ����.
 */
void Menu();