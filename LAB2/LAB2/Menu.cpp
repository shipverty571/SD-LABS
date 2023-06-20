#include <iostream>
#include "Menu.h"
#include <string>

#include "List.h"
using namespace std;

bool ListIsCreated(List* list)
{
	if (list != nullptr)
	{
		return true;
	}

	cout << "������ �� ������" << endl;
	return false;
}

bool IndexValidator(List* list, int index)
{
	if (index < 0)
	{
		cout << "������ ������ ���� ������ ��� ����� ����" << endl;
		return false;
	}
	if (index >= list->Length)
	{
		cout << "������ ������ ���� ������ ����� �������" << endl;
		return false;
	}

	return true;
}

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
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			cout << "��������� ������. ���������� �����" << endl;
			continue;
		}

		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		if (std::cin.gcount() > 1)
		{
			cout << "��������� ������. ���������� �����" << endl;
			continue;
		}

		break;
	}

	return value;
}

void CreateListFromMenu(List* list)
{
	int count;
	cout << "������� ���������� ��������� ������" << endl;
	while (true)
	{
		count = InputValue("");

		if (count <= 0)
		{
			cout << "���������� ��������� � ������ ������ ���� ������ 0"
				<< " ���������� �����" << endl;
			continue;
		}

		break;
	}
	
	cout << "��������:" << endl;
	cout << "1. ������� ������ �� ���������� ����������" << endl;
	cout << "2. ������� ������ �� ������ ����������" << endl;
	while (true)
	{
		int key = InputValue("");
		switch (key)
		{
			case 1:
				GetRandomList(list, count);
				break;
			case 2:
				for (int i = 0; i < count; i++)
				{
					cout << "������� " << i << " ������� �������: ";
					int value = InputValue("");
					InsertElementInLastPosition(list, value);
				}
				break;
			default:
				cout << "������� �������� ��������. ���������� �����";
				break;
		}

		cout << endl;
		return;
	}
}

void InsertElementInFirstPositionFromMenu(List* list)
{
	if (!ListIsCreated(list)) return;
	
	int data = InputValue("������� �������� ��������");
	InsertElementInFirstPosition(list, data);
}

void InsertElementInLastPositionFromMenu(List* list)
{
	if (!ListIsCreated(list)) return;
	
	int data = InputValue("������� �������� ��������");
	InsertElementInLastPosition(list, data);
}

void InsertElementAfterPositionFromMenu(List* list)
{
	if (!ListIsCreated(list)) return;
	if (list->Length == 0)
	{
		cout << "� ������ ��� ���������" << endl;
		return;
	}

	int index;
	while (true)
	{
		index = InputValue("������� ������");
		if (!IndexValidator(list, index)) continue;
		break;
	}

	int data = InputValue("������� �������� ��������");
	InsertElementAfterPosition(list, data, index);
}

void InsertElementBeforePositionFromMenu(List* list)
{
	if (!ListIsCreated(list)) return;
	if (list->Length == 0)
	{
		cout << "� ������ ��� ���������" << endl;
		return;
	}

	int index;
	while (true)
	{
		index = InputValue("������� ������");
		if (!IndexValidator(list, index)) continue;
		break;
	}

	int data = InputValue("������� �������� ��������");
	InsertElementBeforePosition(list, data, index);
}

void ShowListFromMenu(List* list)
{
	if (!ListIsCreated(list)) return;
	if (list->Length == 0)
	{
		cout << "� ������ ��� ���������" << endl;
		return;
	}

	Element* tempElement = list->Head;
	while (tempElement != nullptr)
	{
		cout << tempElement->Data << " ";
		tempElement = tempElement->Next;
	}

	cout << endl;
}

void RemoveElementFromMenu(List* list)
{
	if (!ListIsCreated(list)) return;

	if (list->Length == 0)
	{
		cout << "� ������ ��� ���������" << endl;
		return;
	}

	int index;
	while (true)
	{
		index = InputValue("������� ������");
		if (!IndexValidator(list, index)) continue;
		break;
	}

	RemoveElement(list, index);
}

void SortListFromMenu(List* list)
{
	if (!ListIsCreated(list)) return;
	if (list->Length == 0)
	{
		cout << "� ������ ��� ���������" << endl;
		return;
	}

	SortList(list);
}

void LinearSearchFromMenu(List* list)
{
	if (!ListIsCreated(list)) return;
	
	int value = InputValue("������� �����");
	int index = LinearSearch(list, value);
	if (index == -1)
	{
		cout << "������� �� ������" << endl;
	}
	else
	{
		cout << "������� " << value << " ������ �� ������� " << index << endl;
	}
}

void Menu(List* list)
{
	cout << "����� ����������!" << endl;
	cout << "�������� ������� �� ������ ����" << endl;

	list = nullptr;
	while (true)
	{
		cout << "1. ������� ������" << endl;
		cout << "2. �������� ������� � ������" << endl;
		cout << "3. �������� ������� � �����" << endl;
		cout << "4. �������� ������� ����� �������" << endl;
		cout << "5. �������� ������� ����� ������" << endl;
		cout << "6. �������� ������" << endl;
		cout << "7. ������� �������" << endl;
		cout << "8. ������������� ������" << endl;
		cout << "9. �������� �����" << endl;
		
		int key = InputValue("");
		switch (key)
		{
			case 1:
				list = new List();
				CreateListFromMenu(list);
				break;
			case 2:
				InsertElementInFirstPositionFromMenu(list);
				break;
			case 3:
				InsertElementInLastPositionFromMenu(list);
				break;
			case 4:
				InsertElementAfterPositionFromMenu(list);
				break;
			case 5:
				InsertElementBeforePositionFromMenu(list);
				break;
			case 6:
				ShowListFromMenu(list);
				break;
			case 7:
				RemoveElementFromMenu(list);
				break;
			case 8:
				SortListFromMenu(list);
				break;
			case 9:
				LinearSearchFromMenu(list);
				break;
			default:
				cout << "������� �������� ��������. ���������� �����" << endl;
				break;
		}
	}
}
