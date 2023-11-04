#include "IntegerKeyboardProvider.h"
#include <iostream>
#include <tuple>
#include <regex>
using std::cin, std::cout, std::endl;
using std::to_string;
using std::tuple, std::make_tuple;
using std::regex, std::regex_match;

tuple<bool, int, string> IntegerKeyboardProvider::next(string prompt) {
	int number;
	cout << prompt;
	string buffer;
	getline(cin, buffer);

	bool success = true;
	int data = 0;
	string message = "";

	if (buffer.length() == 0) {
		success = false;
		message = "Empty input string is not allowed";
		auto result = make_tuple(success, data, message);
		return result;
	}

	regex pattern("\\d+");

	if (regex_match(buffer, pattern) == false) {
		success = false;
		message = "Invalid input format";
		auto result = make_tuple(success, data, message);
		return result;
	}

	data = stoi(buffer);
	auto result = make_tuple(success, data, message);
	return result;
}

DynamicArray IntegersKeyboardProvider::next(string prompt) {
	cout << prompt << endl;

	IntegerKeyboardProvider provider;
	bool shouldRepeat;
	int count = 0;

	do {
		auto [success, n, message] = 
			provider.next("Nhap so luong phan tu:");
		if (success) {

			if (n == 0) {
				cout << "Xin nhap so duong" << endl;
				shouldRepeat = true;
			}
			else {
				count = n;
				shouldRepeat = false;
			}
		}
		else {
			cout << message;
			cout << ". Xin hay nhap lai." << endl;
			shouldRepeat = true;
		}
	} while (shouldRepeat);
	
	DynamicArray numbers;

	for (int i = 0; i < count; i++) {
		do {
			auto [success, data, message] =
				provider.next("Nhap phan tu thu " + to_string(i) + ": ");
			if (success) {
				numbers.push_back(data);
			}
			else {
				cout << message;
				cout << ". Xin hay nhap lai." << endl;
			}
			shouldRepeat = (success == false);
		} while (shouldRepeat);
	}

	return numbers;
}


	//DynamicArray next(string prompt);