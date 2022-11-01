#pragma once
#include <iostream>
#include "ConsoleWindow.h"
using namespace std;

class Score
{
	int x, y;
	int score;
	int tHundred, tDozen, tUnit;
public:
	void time_setup(int score_x, int score_y, int scores);
	int time_effect();
};