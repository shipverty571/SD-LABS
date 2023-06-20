#include "BinaryTree.h"

BinaryTreeElement* CreateElement(int data)
{
	BinaryTreeElement* newElement = new BinaryTreeElement;
	newElement->Data = data;
	newElement->Left = nullptr;
	newElement->Right = nullptr;
	return newElement;
}

void InsertElement(BinaryTree* binaryTree, BinaryTreeElement* element)
{
	if (binaryTree->Root == nullptr)
	{
		binaryTree->Root = element;
		return;
	}
	BinaryTreeElement* elementPrev = SearchParentElement(binaryTree->Root, element->Data);
	if (elementPrev->Data > element->Data)
	{
		elementPrev->Left = element;
	}
	else if (elementPrev->Data == element->Data)
	{
		if (elementPrev->Left)
		{
			element->Left = elementPrev->Left;
			elementPrev->Left = nullptr;
		}
		if (elementPrev->Right)
		{
			element->Right = elementPrev->Right;
		}
		elementPrev->Right = element;
		if (elementPrev == binaryTree->Root)
		{
			elementPrev->Left = element->Left;
			element->Left = nullptr;
		}
	}
	else
	{
		elementPrev->Right = element;
	}
}

BinaryTreeElement* SearchParentElement(BinaryTreeElement* currentElement, int data)
{
	if ((currentElement->Data < data) && (currentElement->Right == nullptr)
		|| (currentElement->Data >= data) && (currentElement->Left == nullptr))
	{
		return currentElement;
	}

	if (currentElement->Data < data)
	{
		SearchParentElement(currentElement->Right, data);
	}
	else if (currentElement->Data > data)
	{
		SearchParentElement(currentElement->Left, data);
	}
}

BinaryTreeElement* DeleteElement(BinaryTreeElement* binaryTree, int value)
{
	if (binaryTree == nullptr)
	{
		return binaryTree;
	}

	if (value < binaryTree->Data)
	{
		binaryTree->Left = DeleteElement(binaryTree->Left, value);
	}
	else if (value > binaryTree->Data)
	{
		binaryTree->Right = DeleteElement(binaryTree->Right, value);
	}
	else
	{
		if (binaryTree->Left == nullptr)
		{
			BinaryTreeElement* tempNode = binaryTree->Right;
			delete binaryTree;
			return tempNode;
		}
		if (binaryTree->Right == nullptr)
		{
			BinaryTreeElement* tempNode = binaryTree->Left;
			delete binaryTree;
			return tempNode;
		}

		BinaryTreeElement* tempNode = SearchMinElement(binaryTree->Right);
		binaryTree->Data = tempNode->Data;
		binaryTree->Right = DeleteElement(binaryTree->Right, tempNode->Data);
	}
	return binaryTree;

	/*if (binaryTree == nullptr)
	{
		return nullptr;
	}
	if (value < binaryTree->Data)
	{
		binaryTree->Left = DeleteElement(binaryTree->Left, value);
	}
	else
	{
		if (value > binaryTree->Data)
		{
			binaryTree->Right = DeleteElement(binaryTree->Right, value);
		}
		else
		{
			if (binaryTree->Left != nullptr && binaryTree->Right != nullptr)
			{
				binaryTree->Data = SearchMinElement(binaryTree->Right)->Data;
				binaryTree->Right = DeleteElement(binaryTree->Right, binaryTree->Data);
			}
			else
			{
				BinaryTreeElement* temp = binaryTree;
				if (binaryTree->Left != nullptr)
				{
					binaryTree = binaryTree->Left;
				}
				else
				{
					binaryTree = binaryTree->Right;
				}
				delete temp;
			}
		}
	}
	return binaryTree;*/
}

BinaryTreeElement* SearchMinElement(BinaryTreeElement* current)
{
	if (current->Left != nullptr)
	{
		current = SearchMinElement(current->Left);
	}
	else
	{
		return current;
	}
}

BinaryTreeElement* SearchMaxElement(BinaryTreeElement* current)
{
	if (current->Right != nullptr)
	{
		current = SearchMaxElement(current->Right);
	}
	else
	{
		return current;
	}
}


BinaryTreeElement* SearchElementByValue(BinaryTreeElement* current, int value)
{
	if (current->Data == value)
	{
		return current;
	}
	if ((current->Data < value) && (current->Right != nullptr))
	{
		SearchElementByValue(current->Right, value);
	}
	else if ((current->Data > value) && (current->Left != nullptr))
	{
		SearchElementByValue(current->Left, value);
	}
	else
	{
		return nullptr;
	}
}

void DeleteBinaryTree(BinaryTreeElement* current)
{
	if (current == nullptr)
	{
		return;
	}
	DeleteBinaryTree(current->Left);
	DeleteBinaryTree(current->Right);
	delete current;
}
