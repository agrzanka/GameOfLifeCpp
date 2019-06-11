#include "GOL.h"

void GOL::setBoard(int height, int width)
{
	this->board = Board(height, width);
}

void GOL::setSize(int size)
{
	this->size = size;
}

void GOL::setActive(bool a)
{
	this->active = a;
}

void GOL::addIterationInfo(vector<int>info)
{
	if (this->pastIterations.size() >= 100)
		this->pastIterations.erase(this->pastIterations.begin());

	this->pastIterations.push_back(info);
}

vector<int> GOL::getPastIteration()
{
	vector<int> past;
	

	if (this->pastIterations.size() > 1)
	{
		past = this->pastIterations.back();
		this->pastIterations.pop_back();
	}
	
	else
		past = {};
	return past;
}

bool GOL::firstIter()
{
	if (this->pastIterations.size() < 1)
		return true;
	else
		return false;
}

vector<int> GOL::makePattern(vector<vector<int>>pattern)
{
	vector<int>alive;

	for (auto&p : pattern)
	{
		int id = p[0] + p[1] * this->board.b;
		alive.push_back(id);
	}
	return alive;
}

vector<int>GOL::checkCurrent()
{
	vector<int>current;

	for (auto&c : this->board.cells)
		if (c.isAlive())
			current.push_back(c.id);

	return current;
}