#include "DynamicArray.h"
#include <random>
#include <ctime>

void ResizeArray(DynamicArray* dynamicArray)
{
	if (dynamicArray->Capacity / 2 > dynamicArray->Length - 1)
	{
		dynamicArray->Capacity /= dynamicArray->GrowthFactor;
	}
	else if (dynamicArray->Capacity <= dynamicArray->Length + 1)
	{
		dynamicArray->Capacity *= dynamicArray->GrowthFactor;
	}
	else
	{
		return;
	}

	int* tempArray = new int[dynamicArray->Capacity];
	for (int i = 0; i < dynamicArray->Length - 1; i++)
	{
		tempArray[i] = dynamicArray->Array[i];
	}

	delete[] dynamicArray->Array;
	dynamicArray->Array = tempArray;
}

void AddElement(DynamicArray* dynamicArray, int value)
{
	dynamicArray->Length++;
	ResizeArray(dynamicArray);
	dynamicArray->Array[dynamicArray->Length-1] = value;
}

void GetArrayRandom(DynamicArray* dynamicArray, int length)
{
	srand(time(nullptr));
	for (int i = 0; i < length; i++)
	{
		AddElement(dynamicArray, rand());
	}
}

void InsertElement(DynamicArray* dynamicArray, int value, int index)
{
	dynamicArray->Length++;
	ResizeArray(dynamicArray);
	for (int i = dynamicArray->Length; i > index; i--)
	{
		dynamicArray->Array[i] = dynamicArray->Array[i - 1];
	}

	dynamicArray->Array[index] = value;
}

void SortArray(DynamicArray* dynamicArray)
{
	for (int i = 0; i < dynamicArray->Length; i++) 
	{
		for (int j = 0; j < dynamicArray->Length - 1; j++) 
		{
			if (dynamicArray->Array[j] > dynamicArray->Array[j + 1]) 
			{
				int temp = dynamicArray->Array[j];
				dynamicArray->Array[j] = dynamicArray->Array[j + 1];
				dynamicArray->Array[j + 1] = temp;
			}
		}
	}
}

int LinearSearch(DynamicArray* dynamicArray, int value)
{
	int index = -1;
	for (int i = 0; i < dynamicArray->Length; i++)
	{
		if (dynamicArray->Array[i] == value)
		{
			index = i;
			return index;
		}
	}

	return index;
}

int BinarySearch(DynamicArray* dynamicArray, int value)
{
	bool flag = false;
	int left  = 0;
	int right = dynamicArray->Length;
	int middle;
	while ((left <= right) && (flag != true))
	{
		middle = (left + right) / 2;

		if (dynamicArray->Array[middle] == value)
		{
			flag = true;
		}
		if (dynamicArray->Array[middle] > value)
		{
			right = middle - 1;
		}
		if (dynamicArray->Array[middle] < value)
		{
			left = middle + 1;
		}
	}
	if (!flag)
	{
		middle = -1;
	}

	return middle;
}

void RemoveElement(DynamicArray* dynamicArray, int index)
{
	for (int i = index; i < dynamicArray->Length - 1; i++)
	{
		dynamicArray->Array[i] = dynamicArray->Array[i + 1];
	}
	dynamicArray->Length -= 1;
	ResizeArray(dynamicArray);
}