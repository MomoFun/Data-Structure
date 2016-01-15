#include "Position.h"

Position::Position(int _x,int _y)
{
	m_iX = _x;
	m_iY = _y;
}

void Position::setX(int _x)
{
	m_iX = _x;
}

int Position::getX()
{
	return m_iX;
}

void Position::setY(int _y)
{
	m_iY = _y;
}

int Position::getY()
{
	return m_iY;
}