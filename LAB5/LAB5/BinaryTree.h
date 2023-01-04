#pragma once
#include "BinaryTreeElement.h"

/**
 * \brief ������������ ���������� �� ������������� ��������� ������.
 */
struct BinaryTree
{
	/**
	 * \brief ������ ������.
	 */
	BinaryTreeElement* Root;

	/**
	 * \brief ������� ��������� ��������� BinaryTree.
	 */
	BinaryTree()
	{
		Root = nullptr;
	}
};

/**
 * \brief ������� ������� ������.
 * \param data ��������.
 * \return ���������� ������� ������.
 */
BinaryTreeElement* CreateElement(int data);

/**
 * \brief ��������� ������� � ������.
 * \param binaryTree ������.
 * \param element �������.
 */
void InsertElement(BinaryTree* binaryTree, BinaryTreeElement* element);

/**
 * \brief ����� �������� ��������.
 * \param currentElement �������.
 * \param data ��������.
 * \return ���������� ���������� ��������.
 */
BinaryTreeElement* SearchParentElement(BinaryTreeElement* currentElement, int data);

/**
 * \brief ������� ������� ������.
 * \param binaryTree ������.
 * \param value ��������.
 * \return ���������� ��������� �������.
 */
BinaryTreeElement* DeleteElement(BinaryTreeElement* binaryTree, int value);

/**
 * \brief ����� ������������ ��������.
 * \param current �������.
 * \return ���������� ����������� �������.
 */
BinaryTreeElement* SearchMinElement(BinaryTreeElement* current);

/**
 * \brief ����� ������������� ��������.
 * \param current �������.
 * \return ���������� ������������ �������.
 */
BinaryTreeElement* SearchMaxElement(BinaryTreeElement* current);

/**
 * \brief ����� �������� �� ��������.
 * \param current �������.
 * \param value ��������.
 * \return ���������� ��������� �������.
 */
BinaryTreeElement* SearchElementByValue(BinaryTreeElement* current, int value);

/**
 * \brief ������� ������.
 * \param current ��������� �������.
 */
void DeleteBinaryTree(BinaryTreeElement* current);
