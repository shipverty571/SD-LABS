#include "Menu.h"
#include <iostream>
#include "Dictionary.h"

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
			cout << "Произошла ошибка. Попробуйте снова" << endl;
			continue;
		}

		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		if (cin.gcount() > 1)
		{
			cout << "Произошла ошибка. Попробуйте снова" << endl;
			continue;
		}

		break;
	}

	return value;
}

string InputString(string outputString)
{
	if (outputString != "")
	{
		cout << outputString << endl;
	}
	string str;
	cin >> str;
	return str;
}

void MenuDictionary()
{
	Dictionary* dictionary = new Dictionary();
	cout << "Выберите пункт меню" << endl;
	while (true)
	{
		cout << "1. Добавить элемент в словарь" << endl;
		cout << "2. Удалить элемент из словаря" << endl;
		cout << "3. Найти элемент по ключу" << endl;
		cout << "0. Выйти в главное меню" << endl;
		int key = InputValue("");
		switch (key)
		{
			case 1:
			{
				string key = InputString("Введите ключ");
				string value = InputString("Введите значение");
				Element* element = CreateElement(key, value);
				if (!InsertElement(dictionary, element, key))
				{
					cout << "Такой элемент уже существует" << endl;
				}
				PrintHashTable(dictionary->Table);
				break;
			}
			case 2:
			{
				string key = InputString("Введите ключ");
				if (!RemoveElement(dictionary, key))
				{
					cout << "Такого элемента не существует" << endl;
				}
				PrintHashTable(dictionary->Table);
				break;
			}
			case 3:
			{
				string key = InputString("Введите ключ");
				string data;
				if (FindElement(dictionary, key, data))
				{
					cout << "Найденная информация: " << data << endl;
				}
				else
				{
					cout << "Не найдено" << endl;
				}
				break;
			}
			case 0:
			{
				DeleteDictionary(dictionary);
				return;
			}
			default:
				cout << "Введено неверное значение. Попробуйте снова" << endl;
				break;
			}
	}
}

void MenuHashTable()
{
	HashTable* table = CreateTable(4);
	cout << "Выберите пункт меню" << endl;
	while(true)
	{
		//TODO: убрать в HashTable 
		cout << "1. Добавить элемент в таблицу" << endl;
		cout << "2. Удалить элемент из таблицы" << endl;
		cout << "3. Найти элемент по ключу" << endl;
		cout << "0. Выйти в главное меню" << endl;
		int key = InputValue("");
		switch (key)
		{
			case 1:
			{
				string key = InputString("Введите ключ");
				string value = InputString("Введите значение");
				Element* element = CreateElement(key, value);
				int index = HashFunc(key, table->Size);
				if (!InsertElement(table, element, index))
				{
					cout << "Такой элемент уже существует" << endl;
				}
				PrintHashTable(table);
				break;
			}
			case 2:
			{
				string key = InputString("Введите ключ");
				if (!RemoveElement(table, key))
				{
					cout << "Такого элемента не существует" << endl;
				}
				PrintHashTable(table);
				break;
			}
			case 3:
			{
				string key = InputString("Введите ключ");
				string data;
				if (FindElement(table, key, data))
				{
					cout << "Найденная информация: " << data << endl;
				}
				else
				{
					cout << "Не найдено" << endl;
				}
				break;
			}
			case 0:
			{
				DeleteTable(table);
				return;
			}
			default:
				cout << "Введено неверное значение. Попробуйте снова" << endl;
				break;
		}
	}
}

void PrintHashTable(HashTable* table)
{
	Element* current;
	for (int i = 0; i < table->Size; i++)
	{
		current = table->Array[i]->Head;

		if (current != nullptr)
		{
			cout << "[" << i << "] " <<current->Key << " : " << current->Value << endl;
			current = current->Next;

			while (current != nullptr)
			{
				cout << " >> ";
				cout << "[" << i << "] " << current->Key << " : " << current->Value << endl;
				current = current->Next;
			}
		}
		else
		{
			cout << "[" << i << "] _ : _" << endl;
		}
	}
}


void Menu()
{
	cout << "Добро пожаловать!" << endl;
	cout << "Выберите функцию из списка ниже" << endl;

	while (true)
	{
		cout << "1. Хеш-таблица" << endl;
		cout << "2. Словарь" << endl;
		cout << "0. Выйти" << endl;

		int key = InputValue("");
		switch (key)
		{
			case 1:
				MenuHashTable();
				break;
			case 2:
				MenuDictionary();
				break;
			case 0:
				return;
			default:
				cout << "Введено неверное значение. Попробуйте снова" << endl;
				break;
		}
	}
} 