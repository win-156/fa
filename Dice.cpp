#include "Dice.h"
#include "RandomIntegerProvider.h"

Dice::Dice() {
	_faces = 6;
}

Dice::Dice(int faces) {
	_faces = faces;
}

int Dice::roll() {
	RandomIntegerProvider provider;
	int result = provider.next(1, _faces);
	return result;
}