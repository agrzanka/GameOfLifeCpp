#pragma once
#include "GOL.h"
#include <fstream>


class RLE {

public:

	void encode(vector<int>status);

	vector<int> decode(vector<string> lines, int width);

	vector<string> readfile(string name);
};