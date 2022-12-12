#pragma once
#include <string>

/**
 * \brief ������������ ���������� �� ������������� ��������.
 */
struct Element
{
	/**
	 * \brief ����.
	 */
	std::string Key;

	/**
	 * \brief ��������.
	 */
	std::string Value;

	/**
	 * \brief ��������� �� ��������� �������.
	 */
	Element* Next;
};
