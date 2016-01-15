#include "MazeMap.h"
#include <iostream>
#include<windows.h> 
using namespace std;

#define WALL 0
#define ROAD 1

int MazeMap::getMazeMap(int rowIdx, int colIdx)
{
	return m_iMap[rowIdx * m_iColumn + colIdx];
}
void MazeMap::setMazeMap(int rowIdx, int colIdx, int value)
{
	if (rowIdx < 0 || rowIdx >= m_iRow || colIdx < 0 || colIdx >= m_iColumn) {
		return;
	}
	m_iMap[rowIdx * m_iColumn + colIdx] = value;
}

void MazeMap::setMazeWall(char _wall, char _road)
{
	m_cWall = _wall;
	m_cRoad = _road;
}
void MazeMap::drawMap()
{
	for (int i = 0; i < m_iRow ; i++)
	{
		for (int j = 0; j < m_iColumn; j++)
		{
			if (m_iMap[m_iColumn * i + j] == WALL)
			{
				cout << m_cWall;
			}
			else if (m_iMap[m_iColumn * i + j] == ROAD)
			{
				cout << m_cRoad;
			}
		}
		cout << endl;
	}
}

int MazeMap::getRow()
{
	return m_iRow;
}
int MazeMap::getColumn()
{
	return m_iColumn;
}

