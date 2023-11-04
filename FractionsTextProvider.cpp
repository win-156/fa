#include "FractionsTextProvider.h"
#include <fstream>
using std::ifstream;

vector<Fraction> FractionsTextProvider::next(string filename) {
	vector<Fraction> fractions;

	ifstream reader(filename);
	string buffer;
	getline(reader, buffer);

	int count = stoi(buffer);

	for (int i = 0; i < count; i++) {
		string line;
		getline(reader, line);

		Fraction f = Fraction::parse(line); //"10/6"
		fractions.push_back(f);
	}

	reader.close();
	return fractions;
}