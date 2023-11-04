#pragma once
#include <vector>
#include <string>
using std::vector, std::string;

#include "Fraction.h"

class FractionsTextProvider {
public:
	vector<Fraction> next(string filename);
};