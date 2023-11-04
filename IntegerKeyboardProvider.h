#pragma once

#include <string>
using std::string;
#include <tuple>
#include <regex>
using std::tuple, std::make_tuple;

#include "DynamicArray.h"

 // RandomIntegerProvider
class IntegerKeyboardProvider {
public:
	tuple<bool, int, string> next(string prompt);
};

class IntegersKeyboardProvider {
public:
	DynamicArray next(string prompt);
};

class PrimeKeyboardProvider {
public:
	DynamicArray next(string prompt);
};