#pragma once
#include "Cell.h"
#include<iostream>

using namespace std;

class Board {

private:
	

public:
	Board();
	Board(int a, int b);
	vector<Cell>cells;
	int a;
	int b;
	int numOfIterations;
	void update();
	void show();
	void init(vector<int>alive);
	void setup();
};
