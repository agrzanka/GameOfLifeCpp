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

	
public:
	
	Board board;

	bool active;
	int size;
	GOL();

	void setBoard(int height, int width);

	void draw( Graphics graphics);

	void setSize(int size);
	void setActive(bool a);
};
