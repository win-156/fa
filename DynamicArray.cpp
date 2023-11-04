#include "DynamicArray.h"
#include <exception>
using std::exception, std::cout, std::endl;

DynamicArray::DynamicArray() {
	const int MAX_SIZE = 5;
	_maxSize = MAX_SIZE;
	_a = new int[_maxSize];	
	_size = 0;
}

DynamicArray::DynamicArray(const DynamicArray& other) {
	_maxSize = other._maxSize;
	_size = other._size;
	_a = new int[_maxSize];

	for (int i = 0; i < _size; i++) { // memset
		_a[i] = other._a[i];
	}
}

const DynamicArray& DynamicArray::operator=(const DynamicArray& other) {
	if (this == &other) {
		cout << "Self assign" << endl;
		return other;
	}
	
	cout << "Not self assign" << endl;
	delete[] _a; // Biết chắc _a khác null

	_maxSize = other._maxSize;
	_size = other._size;
	_a = new int[_maxSize];

	for (int i = 0; i < _size; i++) { // memset
		_a[i] = other._a[i];
	}

	return other;
}

DynamicArray::~DynamicArray() {
	cout << "Destructor" << endl; 
	delete[] _a;
}

void DynamicArray::push_back(int item) {
	if (_size == _maxSize - 1) { // reaches the limit
		const int STEPS = 10; 
		int newSize = _maxSize + STEPS;
		int* temp = new int[newSize];
		 
		// better way 
		for (int i = 0; i < _size; i++) {
			temp[i] = _a[i];
		}

		delete[] _a;

		_a = temp;
		_maxSize = newSize;
	}

	_a[_size] = item;
	_size++;
}

int DynamicArray::getAt(int index) {

	if (index >= _size) { // INdex out of range
		throw exception("Index out of range");
	}

	return _a[index];
}

int DynamicArray::size() {
	return _size;
}

int DynamicArray::operator[](int index) {
	return this->getAt(index);
}

istream& operator>>(istream& reader, DynamicArray& numbers) {
	int count = 0;
	cout << "Nhap so luong phan tu:";
	reader >> count;

	for (int i = 0; i < numbers._size; i++) {
		cout << "numbers[" << i << "]: ";
		int value;
		reader >> value;
		numbers.push_back(value);
	}

	return reader;
}

ostream& operator<<(ostream& writer, const DynamicArray& numbers) {
	for (int i = 0; i < numbers._size; i++) {
		writer << numbers._a[i] << " ";
	}

	return writer;
}