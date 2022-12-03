#include <iostream>
#include "List.h"
#include "Menu.h"

int main()
{
    setlocale(LC_ALL, "ru");
    List* list = new List();
    Menu(list);

    delete list;
}