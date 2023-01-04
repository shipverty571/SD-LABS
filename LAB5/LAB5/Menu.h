#pragma once
#include <string>
#include "BinaryTreeElement.h"
#include "TreapElement.h"

/**
 * \brief ������� ��� ����������� ����� �����.
 * \param ������ ��� ������ ����������.
 * \return ���������� �����.
 */
int InputValue(std::string outputString);

/**
 * \brief ���� ��������� ������.
 */
void MenuBinaryTree();

/**
 * \brief ���� ��������� ������.
 */
void MenuTreap();

/**
 * \brief �������� ����.
 */
void Menu();

/**
 * \brief ������� �������� ������.
 * \param current ��������� �������.
 * \param level �������.
 */
void PrintBinaryTree(BinaryTreeElement* current, int level);

/**
 * \brief ������� ��������� ������.
 * \param current ��������� �������.
 * \param level �������.
 */
void PrintTreap(TreapElement* current, int level);

/**
 * \brief ��������� ������� �������� �� ��������� � ������.
 * \param value ��������.
 * \param tree ������.
 * \return ���������� true, ���� ����� ������� ����, ����� false.
 */
bool CheckElement(int value, TreapElement* tree);