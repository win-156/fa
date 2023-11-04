#include "Fibonacci.h"
using std::endl;

Fibonacci::Fibonacci() {
	_size = 0;
	_elements = nullptr;
}

Fibonacci::Fibonacci(const Fibonacci& other) {
	_size = other._size;
	_elements = new int[_size];

	for (int i = 0; i < _size; i++) {
		_elements[i] = other._elements[i];
	}
}

const Fibonacci& Fibonacci::operator=(const Fibonacci& other) {
	if (this == &other) {
		return other;
	}

	if (_elements != nullptr) {
		delete[] _elements;
	}

	_size = other._size;
	_elements = new int[_size];

	for (int i = 0; i < _size; i++) {
		_elements[i] = other._elements[i];
	}

	return other;
}

Fibonacci::~Fibonacci() {
	if (_elements != nullptr) {
		delete[] _elements;
	}
}

void Fibonacci::generate(int size) {
	if (size <= 0) {
		return;
	}
	
	if (_elements != nullptr) {
		delete[] _elements;
	}

	_size = size;
	_elements = new int[_size];

	if (size > 0) {
		_elements[0] = 0;
	}

	if (size > 1) {
		_elements[1] = 1;
	}

	for (int i = 2; i < _size; i++) {
		_elements[i] = _elements[i - 1] + _elements[i - 2];
	}
}
	
ostream& operator<<(ostream& writer, const Fibonacci& f) {
	if (f._size == 0) {
		writer << "No elements to show" << endl;
	}

	for (int i = 0; i < f._size; i++) {
		writer << "F[" << i << "]=" << f._elements[i] << endl;
	}

	return writer;
}