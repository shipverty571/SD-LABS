#include "Menu.h"
#include "BinaryTree.h"
#include "Treap.h"
#include <iostream>

using namespace std;

int InputValue(string outputString)
{
	if (outputString != "")
	{
		cout << outputString << endl;
	}

	int value;
	while (true)
	{
		cin >> value;
		if (cin.fail())
		{
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << "��������� ������. ���������� �����" << endl;
			continue;
		}

		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		if (cin.gcount() > 1)
		{
			cout << "��������� ������. ���������� �����" << endl;
			continue;
		}

		break;
	}

	return value;
}

bool CheckElement(int value, TreapElement* tree)
{
	return SearchElementByValue(tree, value);
}

void PrintBinaryTree(BinaryTreeElement* current, int level)
{
	if (current)
	{
		PrintBinaryTree(current->Right, level + 1);

		for (int i = 0; i < level; i++)
		{
			cout << "   ";
		}
		cout << current->Data << endl;
		PrintBinaryTree(current->Left, level + 1);
	}
}


void MenuBinaryTree()
{
	BinaryTree* binaryTree = new BinaryTree();
	cout << "�������� ����� ����" << endl;
	while (true)
	{
		cout << "1. �������� ������� � ������" << endl;
		cout << "2. ������� ������� �� ������" << endl;
		cout << "3. ����� ������� �� ��������" << endl;
		cout << "4. ����� ������������ �������" << endl;
		cout << "5. ����� ����������� �������" << endl;
		cout << "6. �������� ������" << endl;
		cout << "0. ����� � ������� ����" << endl;
		int key = InputValue("");
		switch (key)
		{
			case 1:
			{
				int value = InputValue("������� ��������: ");
				BinaryTreeElement* element = CreateElement(value);
				InsertElement(binaryTree, element);
				cout << "�������!" << endl;
				break;
			}
			case 2:
			{
				int value = InputValue("������� ��������: ");
				binaryTree->Root = DeleteElement(binaryTree->Root, value);
				break;
			}
			case 3:
			{
				int value = InputValue("������� ��������: ");
				BinaryTreeElement* element = SearchElementByValue(binaryTree->Root, value);
				if (!element)
				{
					cout << "������ �������� ���" << endl;
					
				}
				else
				{
					cout << "������� ������" << endl;
				}
				break;
			}
			case 4:
			{
				if (!binaryTree->Root)
				{
					cout << "������ ������" << endl;
					break;
				}
				BinaryTreeElement* maxElement = SearchMaxElement(binaryTree->Root);
				cout << "������������ �������: " << maxElement->Data << endl;
				break;
			}
			case 5:
			{
				if (!binaryTree->Root)
				{
					cout << "������ ������" << endl;
					break;
				}
				BinaryTreeElement* minElement = SearchMinElement(binaryTree->Root);
				cout << "����������� �������: " << minElement->Data << endl;
				break;
			}
			case 6:
				if (!binaryTree->Root)
				{
					cout << "������ ������" << endl;
					break;
				}
				cout << "--------------------" << endl;
				PrintBinaryTree(binaryTree->Root, 0);
				break;
			case 0:
				DeleteBinaryTree(binaryTree->Root);
				return;
			default:
				cout << "������� �������� ��������. ���������� �����" << endl;
				break;
		}
	}
}

void PrintTreap(TreapElement* current, int level)
{
	if (current)
	{
		PrintTreap(current->Right, level + 1);

		for (int i = 0; i < level; i++)
		{
			cout << "   ";
		}
		cout << current->Priority << " : " << current->Data << endl;
		PrintTreap(current->Left, level + 1);
	}
}

void MenuTreap()
{
	Treap* treap = new Treap();
	cout << "�������� ����� ����" << endl;
	while (true)
	{
		cout << "1. �������� ������� ���������������� ����������" << endl;
		cout << "2. �������� ������� �� ���������������� ����������" << endl;
		cout << "3. ������� ������� �� ������ ���������������� ����������" << endl;
		cout << "4. ������� ������� �� ������ �� ���������������� ����������" << endl;
		cout << "5. ����� ��������" << endl;
		cout << "6. �������� ������" << endl;
		cout << "0. ����� � ������� ����" << endl;
		int key = InputValue("");
		switch (key)
		{
			case 1:
			{
				int value = InputValue("������� ��������: ");
				if (treap->Root)
				{
					if (CheckElement(value, treap->Root))
					{
						cout << "������� �� ��������� " << value << " ��� ����������." << endl;
						break;
					}
				}
				InsertOpt(value, rand() % treap->MaxPriority, treap->Root);
				break;
			}
			case 2:
			{
				int value = InputValue("������� ��������: ");
				if (treap->Root)
				{
					if (CheckElement(value, treap->Root))
					{
						cout << "������� �� ��������� " << value << " ��� ����������." << endl;
						break;
					}
				}
				InsertNotOpt(treap->Root, value);
				break;
			}
			case 3:
			{
				int value = InputValue("������� ��������: ");
				DeleteOpt(value, treap->Root);
				break;
			}
			case 4:
			{
				int value = InputValue("������� ��������: ");
				DeleteNotOpt(treap->Root, value);
				break;
			}
			case 5:
			{
				int value = InputValue("������� ��������: ");
				TreapElement* element = SearchElementByValue(treap->Root, value);
				if (!element)
				{
					cout << "������ �������� ���" << endl;

				}
				else
				{
					cout << "������� ������" << endl;
				}
				break;
			}
			case 6:
				PrintTreap(treap->Root, 0);
				break;
			case 0:
				DeleteTreap(treap->Root);
				return;
			default:
				cout << "������� �������� ��������. ���������� �����" << endl;
				break;
		}
	}
}

void Menu()
{
	cout << "����� ����������!" << endl;
	cout << "�������� ������� �� ������ ����" << endl;
	while (true)
	{
		cout << "1. �������� ������" << endl;
		cout << "2. ��������� ������" << endl;
		cout << "0. �����" << endl;

		int key = InputValue("");
		switch (key)
		{
			case 1:
				MenuBinaryTree();
				break;
			case 2:
				MenuTreap();
				break;
			case 0:
				return;
			default:
				cout << "������� �������� ��������. ���������� �����" << endl;
				break;
		}
	}
}


