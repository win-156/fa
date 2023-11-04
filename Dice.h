#pragma once

class Dice {
private:
	int _faces;
public:
	Dice();
	Dice(int faces);
public:
	int roll();
};