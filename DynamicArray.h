#pragma once
#include <iostream>
using std::istream, std::ostream;

/// <summary>
/// A class for storing integers dynamically
/// </summary>
class DynamicArray {
private: // attributes
	int* _a;
	int _maxSize;
	int _size;
public:
	DynamicArray();

	DynamicArray(const DynamicArray& other); // Copy constructor
	const DynamicArray& operator=(const DynamicArray& other);

	~DynamicArray();
public:
	void push_back(int item);
	int getAt(int index);
	int size();

	int operator[](int index);
	
	friend istream& operator>>(istream& reader, DynamicArray& numbers);
	friend ostream& operator<<(ostream& writer, const DynamicArray& numbers);
};