#pragma once
#include <string>
#include <tuple>
using std::string, std::tuple, std::make_tuple;
#include "Atm.h"

class BankAccount
{
private:
	inline static const int MINIMUM_BALANCE = 50000;
	string _name;
	int _balance;
public:
	int availableBalance();
	BankAccount(string name, int balance);
	tuple<bool, int, string> withdraw(Atm& atm, int amount);
};