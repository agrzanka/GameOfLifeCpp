#pragma once
#include"Board.h"
#include "Cell.h"

using namespace System;
using namespace System::ComponentModel;
using namespace System::Collections;
using namespace System::Windows::Forms;
using namespace System::Data;
using namespace System::Drawing;

class GOL {

	vector<vector<int>>pastIterations;
	
public:
	
	Board board;

	bool active;
	int size;
	GOL();

	void setBoard(int height, int width);

	void draw( Graphics graphics);

	void setSize(int size);
	void setActive(bool a);

	void addIterationInfo(vector<int> info);
	vector<int> getPastIteration();

	bool firstIter();

	vector<int>makePattern(vector<vector<int>>pattern);

	vector<int>checkCurrent();
};
