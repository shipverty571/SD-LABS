#include <iostream>

#include "DynamicArray.h"
using namespace std;

bool DynamicArrayIsCreated(DynamicArray* dynamicArray)
{
	return dynamicArray != nullptr;
}

int InputValue()
{ 
	char* choice = new char[256];
	cin >> choice;
	int value = atoi(choice);

	return value;
}

void CreateArrayFromMenu(DynamicArray* dynamicArray)
{
	int count;
	cout << "������� ���������� ��������� �������" << endl;
	while (true)
	{
		count = InputValue();
		if (count <= 0)
		{
			cout << "���������� ��������� � ������� ������ ���� ������ 0"
				<< " ���������� �����" << endl;
			continue;
		}
		break;
	}
	
	cout << "��������:"                                  << endl;
	cout << "1. ������� ������ �� ���������� ����������" << endl;
	cout << "2. ������� ������ �� ������ ����������"     << endl;
	while (true)
	{
		int key = InputValue();

		switch (key)
		{
			case 1:
				GetArrayRandom(dynamicArray, count);
				cout << endl;
				return;
			case 2:
				for (int i = 0; i < count; i++)
				{
					cout << "������� " << i << " ������� �������";
					int value = InputValue();
					AddElement(dynamicArray, value);
				}
				cout << endl;
				return;
			default:
				cout << "������� �������� ��������. ���������� �����";
				break;
		}

		cout << endl;
	}
}

void AddElementFromMenu(DynamicArray* dynamicArray)
{
	if (!DynamicArrayIsCreated(dynamicArray))
	{
		cout << "������ �� ������" << endl;
		return;
	}

	cout << "������� �����" << endl;
	int value = InputValue();
	AddElement(dynamicArray, value);
	dynamicArray->IsSorted = false;
}

void ShowArrayFromMenu(DynamicArray* dynamicArray)
{
	if (!DynamicArrayIsCreated(dynamicArray))
	{
		cout << "������ �� ������" << endl;
		return;
	}

	for (int i = 0; i < dynamicArray->Length; i++)
	{
		cout << dynamicArray->Array[i] << " ";
	}

	cout << endl;
}

void RemoveElementFromMenu(DynamicArray* dynamicArray)
{
	if (!DynamicArrayIsCreated(dynamicArray))
	{
		cout << "������ �� ������" << endl;
		return;
	}

	int index;
	while (true)
	{
		cout << "������� ������" << endl;
		index = InputValue();

		if (index < 0)
		{
			cout << "������ ������ ���� ������ ��� ����� ����" << endl;
			continue;
		}
		if (index >= dynamicArray->Length)
		{
			cout << "������ ������ ���� ������ ����� �������" << endl;
			continue;
		}

		break;
	}

	RemoveElement(dynamicArray, index);
}

void InsertElementFromMenu(DynamicArray* dynamicArray)
{
	if (!DynamicArrayIsCreated(dynamicArray))
	{
		cout << "������ �� ������" << endl;
		return;
	}

	cout << "������� �����" << endl;
	int value = InputValue();
	cout << "��������:"                                << endl;
	cout << "1. �������� � ������"                     << endl;
	cout << "2. �������� ����� ������������� ��������" << endl;
	cout << "3. �������� � �����"                      << endl;
	int index;
	while (true)
	{
		int key = InputValue();
		switch (key)
		{
			case 1:
				index = 0;
				InsertElement(dynamicArray, value, index);
				dynamicArray->IsSorted = false;
				return;
			case 2:
				cout << "������� ������" << endl;
				index = InputValue();
				index++;

				if (index < 0)
				{
					cout << "������ ������ ���� ������ ��� ����� ����" << endl;
					break;
				}

				if (index > dynamicArray->Length)
				{
					cout << "������ �������� ������� �� ��� �����" << endl;
					break;
				}

				InsertElement(dynamicArray, value, index);
				dynamicArray->IsSorted = false;
				return;
			case 3:
				index = dynamicArray->Length;
				InsertElement(dynamicArray, value, index);
				dynamicArray->IsSorted = false;
				return;
			default:
				cout << "������� �������� ��������. ���������� �����";
				break;
		}

		cout << endl;
	}
}

void SortArrayFromMenu(DynamicArray* dynamicArray)
{
	if (!DynamicArrayIsCreated(dynamicArray))
	{
		cout << "������ �� ������" << endl;
		return;
	}

	SortArray(dynamicArray);
	dynamicArray->IsSorted = true;
}

void LinearSearchFromMenu(DynamicArray* dynamicArray)
{
	if (!DynamicArrayIsCreated(dynamicArray))
	{
		cout << "������ �� ������" << endl;
		return;
	}

	cout << "������� �����" << endl;
	int value = InputValue();
	int index = LinearSearch(dynamicArray, value);
	if (index == -1)
	{
		cout << "������� �� ������" << endl;
	}
	else
	{
		cout << "������� " << value << " ������ �� ������� " << index << endl;
	}
}

void BinarySearchFromMenu(DynamicArray* dynamicArray)
{
	if (dynamicArray->IsSorted == false)
	{
		cout << "������ �� ������������" << endl;
		return;
	}

	cout << "������� �����" << endl;
	int value = InputValue();
	int index = BinarySearch(dynamicArray, value);
	if (index == -1)
	{
		cout << "������� �� ������" << endl;
	}
	else
	{
		cout << "������� " << value << " ������ �� ������� " << index << endl;
	}
}

void Menu(DynamicArray* dynamicArray)
{
	cout << "\t����� ����������!"             << endl;
	cout << "�������� ������� �� ������ ����" << endl;

	dynamicArray = nullptr;
	while (true)
	{
		cout << "1. ������� ������"            << endl;
		cout << "2. �������� ������� � ������" << endl;
		cout << "3. ������� �������"           << endl;
		cout << "4. �������� �������"          << endl;
		cout << "5. �������� ������"           << endl;
		cout << "6. ������������� ������"      << endl;
		cout << "7. �������� �����"            << endl;
		cout << "8. �������� �����"            << endl;
		cout << "9. �����"                     << endl;
		int key = InputValue();
		switch (key)
		{
			case 1:
				dynamicArray = new DynamicArray();
				CreateArrayFromMenu(dynamicArray);
				break;
			case 2:
				AddElementFromMenu(dynamicArray);
				break;
			case 3:
				RemoveElementFromMenu(dynamicArray);
				break;
			case 4:
				InsertElementFromMenu(dynamicArray);
				break;
			case 5:
				ShowArrayFromMenu(dynamicArray);
				break;
			case 6:
				SortArrayFromMenu(dynamicArray);
				break;
			case 7:
				LinearSearchFromMenu(dynamicArray);
				break;
			case 8:
				BinarySearchFromMenu(dynamicArray);
				break;
			case 9:
				return;
			default:
				cout << "������� �������� ��������. ���������� �����" << endl;
				break;
		}
	}
}