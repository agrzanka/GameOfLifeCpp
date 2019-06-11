#include "GOL.h"

GOL::GOL()
{
	//this->active = false;
	//this->size = size;


}

void GOL::draw(Graphics graphics)
{
	/*SolidBrush brush (Color::Red);
	for(int y=0;y<this->board.a;y++)
		for (int x = 0; x < this->board.b; x++)
		{
			if(this->board.cells[y*this->board.b+x].isAlive())
				graphics.FillRectangle(brush, x*this->size, y*this->size, this->size, this->size);
		}
		*/
}

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