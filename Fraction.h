#pragma once
#include <iostream>
#include <string>
using std::ostream;
using std::string;

class Fraction {
private:
	int _num;
	int _den;
public:
	Fraction();
	Fraction(int num, int den);
public:
	friend ostream& operator<<(ostream& writer, const Fraction& f);
	friend Fraction operator+(const Fraction& a, const Fraction& b);
public:
	static Fraction parse(string info);
};