#include "Atm.h"
#include <exception>

using std::exception, std::make_tuple;

Atm::Atm(int balance) {
	if (balance < 0) {
		throw exception("Atm cannot be init with negative balance");
	}

	_balance = balance;
}

tuple<bool, int, string> Atm::withdraw(int amount) {
	if (amount % 50000 != 0) {
		return make_tuple(false, 0, "Withdraw amount must be a multiple of 50.000");
	}

	if (amount > _balance) {
		return make_tuple(false, 0, "Atm does not have enough money");
	}

	_balance -= amount;

	return make_tuple(true, amount, "");
}