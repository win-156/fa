#pragma once
#include <iostream>
using std::ostream;

class Fibonacci {
private:
	int _size;
	int* _elements;

public:
	Fibonacci();
	Fibonacci(const Fibonacci& other);
	const Fibonacci& operator=(const Fibonacci& other);
	~Fibonacci();
public:
	void generate(int size);
	friend ostream& operator<<(ostream& writer, const Fibonacci& f);
};