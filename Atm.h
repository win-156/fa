#pragma once
#include <tuple>
#include <string>
using std::tuple, std::string;

class Atm {
private:
	int _balance;
public:
	Atm(int balance);
	tuple<bool, int, string> withdraw(int amount);
};