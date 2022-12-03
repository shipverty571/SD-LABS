#include <clocale>
#include "Menu.h"
#include "DynamicArray.h"
using namespace std;

int main()
{
	setlocale(LC_ALL, "ru");
	DynamicArray* dynamicArray = new DynamicArray();
	Menu(dynamicArray);

	delete[] dynamicArray->Array;
	delete dynamicArray;
}
