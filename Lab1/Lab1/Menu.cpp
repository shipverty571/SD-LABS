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
	cout << "Введите количество элементов массива" << endl;
	while (true)
	{
		count = InputValue();
		if (count <= 0)
		{
			cout << "Количество элементов в массиве должно быть больше 0"
				<< " Попробуйте снова" << endl;
			continue;
		}
		break;
	}
	
	cout << "Выберите:"                                  << endl;
	cout << "1. Создать массив со случайными значениями" << endl;
	cout << "2. Создать массив со своими значениями"     << endl;
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
					cout << "Введите " << i << " элемент массива";
					int value = InputValue();
					AddElement(dynamicArray, value);
				}
				cout << endl;
				return;
			default:
				cout << "Введено неверное значение. Попробуйте снова";
				break;
		}

		cout << endl;
	}
}

void AddElementFromMenu(DynamicArray* dynamicArray)
{
	if (!DynamicArrayIsCreated(dynamicArray))
	{
		cout << "Массив не создан" << endl;
		return;
	}

	cout << "Введите число" << endl;
	int value = InputValue();
	AddElement(dynamicArray, value);
	dynamicArray->IsSorted = false;
}

void ShowArrayFromMenu(DynamicArray* dynamicArray)
{
	if (!DynamicArrayIsCreated(dynamicArray))
	{
		cout << "Массив не создан" << endl;
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
		cout << "Массив не создан" << endl;
		return;
	}

	int index;
	while (true)
	{
		cout << "Введите индекс" << endl;
		index = InputValue();

		if (index < 0)
		{
			cout << "Индекс должен быть больше или равен нулю" << endl;
			continue;
		}
		if (index >= dynamicArray->Length)
		{
			cout << "Индекс должен быть меньше длины массива" << endl;
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
		cout << "Массив не создан" << endl;
		return;
	}

	cout << "Введите число" << endl;
	int value = InputValue();
	cout << "Выберите:"                                << endl;
	cout << "1. Вставить в начало"                     << endl;
	cout << "2. Вставить после определенного элемента" << endl;
	cout << "3. Вставить в конец"                      << endl;
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
				cout << "Введите индекс" << endl;
				index = InputValue();
				index++;

				if (index < 0)
				{
					cout << "Индекс должен быть больше или равен нулю" << endl;
					break;
				}

				if (index > dynamicArray->Length)
				{
					cout << "Нельзя добавить элемент на это место" << endl;
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
				cout << "Введено неверное значение. Попробуйте снова";
				break;
		}

		cout << endl;
	}
}

void SortArrayFromMenu(DynamicArray* dynamicArray)
{
	if (!DynamicArrayIsCreated(dynamicArray))
	{
		cout << "Массив не создан" << endl;
		return;
	}

	SortArray(dynamicArray);
	dynamicArray->IsSorted = true;
}

void LinearSearchFromMenu(DynamicArray* dynamicArray)
{
	if (!DynamicArrayIsCreated(dynamicArray))
	{
		cout << "Массив не создан" << endl;
		return;
	}

	cout << "Введите число" << endl;
	int value = InputValue();
	int index = LinearSearch(dynamicArray, value);
	if (index == -1)
	{
		cout << "Элемент не найден" << endl;
	}
	else
	{
		cout << "Элемент " << value << " найден по индексу " << index << endl;
	}
}

void BinarySearchFromMenu(DynamicArray* dynamicArray)
{
	if (dynamicArray->IsSorted == false)
	{
		cout << "Массив не отсортирован" << endl;
		return;
	}

	cout << "Введите число" << endl;
	int value = InputValue();
	int index = BinarySearch(dynamicArray, value);
	if (index == -1)
	{
		cout << "Элемент не найден" << endl;
	}
	else
	{
		cout << "Элемент " << value << " найден по индексу " << index << endl;
	}
}

void Menu(DynamicArray* dynamicArray)
{
	cout << "\tДобро пожаловать!"             << endl;
	cout << "Выберите функцию из списка ниже" << endl;

	dynamicArray = nullptr;
	while (true)
	{
		cout << "1. Создать массив"            << endl;
		cout << "2. Добавить элемент в массив" << endl;
		cout << "3. Удалить элемент"           << endl;
		cout << "4. Вставить элемент"          << endl;
		cout << "5. Показать массив"           << endl;
		cout << "6. Отсортировать массив"      << endl;
		cout << "7. Линейный поиск"            << endl;
		cout << "8. Бинарный поиск"            << endl;
		cout << "9. Выйти"                     << endl;
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
				cout << "Введено неверное значение. Попробуйте снова" << endl;
				break;
		}
	}
}