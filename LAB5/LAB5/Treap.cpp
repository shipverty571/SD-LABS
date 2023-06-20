#include "Treap.h"
#include <cstdlib>
#include <ctime>

TreapElement* SearchParentElement(TreapElement* currentElement, int data)
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

void Split(TreapElement* tree, int key, TreapElement*& left, TreapElement*& right)
{
	if (tree == nullptr)
		left = right = nullptr;
	else
	{
		if (tree->Data > key)
		{
			Split(tree->Left, key, left, tree->Left);
			right = tree;
		}
		else
		{
			Split(tree->Right, key, tree->Right, right);
			left = tree;
		}
	}
}

void Merge(TreapElement*& tree, TreapElement* left, TreapElement* right)
{
	if (left == nullptr || right == nullptr)
	{
		tree = left ? left : right;
	}
	else if (left->Priority > right->Priority)
	{
		Merge(left->Right, left->Right, right);
		tree = left;
	}
	else
	{
		Merge(right->Left, left, right->Left);
		tree = right;
	}
}

void InsertNotOpt(TreapElement*& root, int value)
{
	TreapElement* left;
	TreapElement* right;
	Split(root, value, left, right);
	TreapElement* newElement = new TreapElement;
	newElement->Left = nullptr;
	newElement->Right = nullptr;
	newElement->Data = value;
	newElement->Priority = rand() % Treap().MaxPriority;
	Merge(root, left, newElement);
	Merge(root, root, right);
}

void InsertOpt(int value, int priority, TreapElement*& current)
{
	if (current == nullptr)
	{
		current = new TreapElement;
		current->Left = nullptr;
		current->Right = nullptr;
		current->Data = value;
		current->Priority = priority;
		return;
	}

	if (priority >= current->Priority)
	{
		TreapElement* left;
		TreapElement* right;
		Split(current, value, left, right);
		TreapElement* newElement = new TreapElement;
		newElement->Left = left;
		newElement->Right = right;
		newElement->Data = value;
		newElement->Priority = priority;
		current = newElement;
	}
	else if (value < current->Data)
	{
		InsertOpt(value, priority, current->Left);
	}
	else
	{
		InsertOpt(value, priority, current->Right);
	}
}

void DeleteNotOpt(TreapElement*& root, int value)
{
	TreapElement* left;
	TreapElement* right;
	TreapElement* element;
	Split(root, value - 1, left, right);
	Split(right, value, element, right);
	Merge(root, left, right);
	delete element;
}

void DeleteOpt(int value, TreapElement*& current)
{
	if (current == nullptr)
	{
		return;
	}
	if (value == current->Data)
	{
		TreapElement* element = current;
		Merge(current, current->Left, current->Right);
		delete element;
	}
	else if (value < current->Data)
	{
		DeleteOpt(value, current->Left);
	}
	else
	{
		DeleteOpt(value, current->Right);
	}
}

TreapElement* SearchElementByValue(TreapElement* current, int value)
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

void DeleteTreap(TreapElement* current)
{
	if (current == nullptr)
	{
		return;
	}
	DeleteTreap(current->Left);
	DeleteTreap(current->Right);
	delete current;
}