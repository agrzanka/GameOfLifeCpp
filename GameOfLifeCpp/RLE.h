#pragma once
#include "GOL.h"


class RLE {

public:

	void encode(vector<int>status);

	vector<int> decode();
};