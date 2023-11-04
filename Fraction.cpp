#include "Fraction.h"
#include <exception>
#include <iostream>
#include <sstream>
#include <algorithm>
#include <numeric>
using std::exception;
using std::cout;
using std::istringstream;
using std::gcd;

Fraction::Fraction() {
	_num = 0;
	_den = 1;
}

Fraction::Fraction(int num, int den) {
	_num = num;
	_den = den;

	if (den == 0) {
		throw exception("Divided by zero exception");
	}
}

ostream& operator<<(ostream& writer, const Fraction& f) {
	writer << f._num << "/" << f._den;

	return writer;
}

Fraction Fraction::parse(string info) {
	istringstream reader(info);
	string left;
	getline(reader, left, '/');
	string right;
	getline(reader, right);

	int num = stoi(left);
	int den = stoi(right);
	Fraction result(num, den);
	return result;
}

Fraction operator+(const Fraction& a, const Fraction& b) {
	int num = a._num * b._den + a._den * b._num;
	int den = a._den * b._den;
	int common = gcd(num, den);
	num /= common;
	den /= common;

	Fraction result(num, den);
	return result;
}