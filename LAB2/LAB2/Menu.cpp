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

	cout << "Список не создан" << endl;
	return false;
}

bool IndexValidator(List* list, int index)
{
	if (index < 0)
	{
		cout << "Индекс должен быть больше или равен нулю" << endl;
		return false;
	}
	if (index >= list->Length)
	{
		cout << "Индекс должен быть меньше длины массива" << endl;
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
			cout << "Произошла ошибка. Попробуйте снова" << endl;
			continue;
		}

		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		if (std::cin.gcount() > 1)
		{
			cout << "Произошла ошибка. Попробуйте снова" << endl;
			continue;
		}

		break;
	}

	return value;
}

void CreateListFromMenu(List* list)
{
	int count;
	cout << "Введите количество элементов списка" << endl;
	while (true)
	{
		count = InputValue("");

		if (count <= 0)
		{
			cout << "Количество элементов в списке должно быть больше 0"
				<< " Попробуйте снова" << endl;
			continue;
		}

		break;
	}
	
	cout << "Выберите:" << endl;
	cout << "1. Создать список со случайными значениями" << endl;
	cout << "2. Создать список со своими значениями" << endl;
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
					cout << "Введите " << i << " элемент массива: ";
					int value = InputValue("");
					InsertElementInLastPosition(list, value);
				}
				break;
			default:
				cout << "Введено неверное значение. Попробуйте снова";
				break;
		}

		cout << endl;
		return;
	}
}

void InsertElementInFirstPositionFromMenu(List* list)
{
	if (!ListIsCreated(list)) return;
	
	int data = InputValue("Введите значение элемента");
	InsertElementInFirstPosition(list, data);
}

void InsertElementInLastPositionFromMenu(List* list)
{
	if (!ListIsCreated(list)) return;
	
	int data = InputValue("Введите значение элемента");
	InsertElementInLastPosition(list, data);
}

void InsertElementAfterPositionFromMenu(List* list)
{
	if (!ListIsCreated(list)) return;
	if (list->Length == 0)
	{
		cout << "В списке нет элементов" << endl;
		return;
	}

	int index;
	while (true)
	{
		index = InputValue("Введите индекс");
		if (!IndexValidator(list, index)) continue;
		break;
	}

	int data = InputValue("Введите значение элемента");
	InsertElementAfterPosition(list, data, index);
}

void InsertElementBeforePositionFromMenu(List* list)
{
	if (!ListIsCreated(list)) return;
	if (list->Length == 0)
	{
		cout << "В списке нет элементов" << endl;
		return;
	}

	int index;
	while (true)
	{
		index = InputValue("Введите индекс");
		if (!IndexValidator(list, index)) continue;
		break;
	}

	int data = InputValue("Введите значение элемента");
	InsertElementBeforePosition(list, data, index);
}

void ShowListFromMenu(List* list)
{
	if (!ListIsCreated(list)) return;
	if (list->Length == 0)
	{
		cout << "В списке нет элементов" << endl;
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
		cout << "В списке нет элементов" << endl;
		return;
	}

	int index;
	while (true)
	{
		index = InputValue("Введите индекс");
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
		cout << "В списке нет элементов" << endl;
		return;
	}

	SortList(list);
}

void LinearSearchFromMenu(List* list)
{
	if (!ListIsCreated(list)) return;
	
	int value = InputValue("Введите число");
	int index = LinearSearch(list, value);
	if (index == -1)
	{
		cout << "Элемент не найден" << endl;
	}
	else
	{
		cout << "Элемент " << value << " найден по индексу " << index << endl;
	}
}

void Menu(List* list)
{
	cout << "Добро пожаловать!" << endl;
	cout << "Выберите функцию из списка ниже" << endl;

	list = nullptr;
	while (true)
	{
		cout << "1. Создать список" << endl;
		cout << "2. Вставить элемент в начало" << endl;
		cout << "3. Вставить элемент в конец" << endl;
		cout << "4. Вставить элемент после другого" << endl;
		cout << "5. Вставить элемент перед другим" << endl;
		cout << "6. Показать список" << endl;
		cout << "7. Удалить элемент" << endl;
		cout << "8. Отсортировать список" << endl;
		cout << "9. Линейный поиск" << endl;
		
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
				cout << "Введено неверное значение. Попробуйте снова" << endl;
				break;
		}
	}
}
