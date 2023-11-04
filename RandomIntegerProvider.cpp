#include "RandomIntegerProvider.h"
#include <cstdlib>
#include <time.h>

RandomIntegerProvider::RandomIntegerProvider() {
	if (_seeded == false) {
		srand(time(NULL));
		_seeded = true;
	}
}

int RandomIntegerProvider::next() {
	return rand(); // 0-4 bil
}

int RandomIntegerProvider::next(int max) {
	return rand() % max;
}


int RandomIntegerProvider::next(int left, int right) {
	return rand() % (right - left + 1) + left;
}