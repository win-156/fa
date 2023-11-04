#include "BankAccount.h"
#include <exception>
#include <string>
using std::exception;
using std::to_string;

BankAccount::BankAccount(string name, int balance) {
	_name = name;
	 
	if (balance < 0) {
		throw exception("Cannot init an account with negative balance");
	}

	if (balance < MINIMUM_BALANCE) {
		throw exception("Initial balance is not enough");
	}

	_balance = balance;
}

tuple<bool, int, string> BankAccount::withdraw(Atm& atm, int amount) {
	if (amount <= 0) {
		// TODO:  check amount < 0
	}

	if (_balance - amount < MINIMUM_BALANCE) {
		return make_tuple(false, 0, "Not sufficient balance");
	} 

	auto [success, paid, message] = atm.withdraw(amount);

	if (success) {
		_balance -= paid;
		return make_tuple(true, paid, "");
	}
	else {
		return make_tuple(false, 0, message);
	}
}

int BankAccount::availableBalance() {
	return _balance;
}