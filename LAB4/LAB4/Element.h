#pragma once
#include <string>

struct Element
{
	std::string Key;
	std::string Value;
	Element* Next;
};
