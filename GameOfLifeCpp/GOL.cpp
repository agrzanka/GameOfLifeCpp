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