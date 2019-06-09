#include "GOL.h"

GOL::GOL()
{
	this->active = false;
	//this->size = size;
}

void GOL::drawSth(Graphics graphics)
{
	//SolidBrush brush (Color::Red);
	//graphics.FillRectangle(brush, 4, 4, this->size,this->size);

}

void GOL::setSize(int size)
{
	this->size = size;
}

void GOL::setActive(bool a)
{
	this->active = a;
}