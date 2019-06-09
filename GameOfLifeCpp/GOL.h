#pragma once
using namespace System;
using namespace System::ComponentModel;
using namespace System::Collections;
using namespace System::Windows::Forms;
using namespace System::Data;
using namespace System::Drawing;

class GOL {

public:
	bool active;
	int size;
	GOL();

	void drawSth( Graphics graphics);

	void setSize(int size);
	void setActive(bool a);
};
