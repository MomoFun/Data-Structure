#include "MazePerson.h"
#include <iostream>
using namespace std;

#define WALL 0
#define ROAD 1

#define UP 1
#define DOWN 2
#define LEFT 3
#define RIGHT 4

#define FAST 1
#define SLOW 0

int success = 0;

//设置入口坐标
void MazePerson::setPersonPosition(int x, int y)
{
	m_exPosition.setX(x);
	m_exPosition.setY(y);
}

//设置速度
void MazePerson::setPersonSpeed(int spd)
{
	m_iSpeed = spd;
}

//设置表示人的字符
void MazePerson::setPersonChar(char shpe)
{
	m_cPersonShap = shpe;
}

//void MazePerson::gotoxy(int x,int y)
//{
//	COORD cd;
//	cd.X = x;
//	cd.Y = y;
//	HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
//	SetConsoleCursorPosition(handle,cd)
//}

//开始走迷宫
int MazePerson::start()
{
	int exX;
	int exY;
	int curX;
	int curY;

	//获取初始点坐标
	success++;
	int initX = m_stPosition.getX();
	int initY = m_stPosition.getY();
	gotoxy(m_stPosition.getX(), m_stPosition.getY());
	cout << "the " << success << "th:";
	cout << "(" << m_stPosition.getX() << "," << m_stPosition.getY() << ")" << endl;

	
	//得到第两个点
	m_exPosition = m_stPosition;
	exX = initX;
	exY = initY;

	if (m_imap.getMazeMap(initX,initY + 1) == WALL && m_imap.getMazeMap(initX - 1,initY) == ROAD)
	{
		
		curX = initX - 1;
		curY = initY;
		m_curPosition.setX(curX);
		m_curPosition.setY(curY);
		m_iPersonDir = UP;
	}

	if (m_imap.getMazeMap(initX - 1, initY) == WALL && m_imap.getMazeMap(initX, initY - 1) == ROAD)
	{
		
		curX = initX;
		curY = initY - 1;
		m_curPosition.setX(curX);
		m_curPosition.setY(curY);
		m_iPersonDir = LEFT;
	}

	if (m_imap.getMazeMap(initX, initY - 1) == WALL && m_imap.getMazeMap(initX + 1, initY) == ROAD)
	{
		curX = initX + 1;
		curY = initY;
		m_curPosition.setX(curX);
		m_curPosition.setY(curY);
		m_iPersonDir = DOWN;
	}

	if (m_imap.getMazeMap(initX + 1, initY) == WALL && m_imap.getMazeMap(initX + 1, initY) == ROAD)
	{
		curX = initX + 1;
		curY = initY;
		m_curPosition.setX(curX);
		m_curPosition.setY(curY);
		m_iPersonDir = RIGHT;
	}
	success++;
	gotoxy(m_stPosition.getX(), m_stPosition.getY());
	cout << "the " << success << "th:";
	cout << "(" << m_curPosition.getX() << "," << m_curPosition.getY() << ")" << endl;

	//得到第三个到最后一个点
	while (curX > 0 && curY > 0 && curX < m_imap.getRow() && curY < m_imap.getColumn())
	{
		//(exX == curX + 1 && exY == curY) && m_imap.getMazeMap(curX + 1,curY+1) == WALL
		if (m_iPersonDir == UP)
		{
			//1
			if (m_imap.getMazeMap(curX,curY+1) == ROAD )
			{
				exX = curX;
				exY = curY;
				curX = curX;
				curY = curY+1;
				m_iPersonDir = RIGHT;
			}
			else if (m_imap.getMazeMap(curX,curY+1) == WALL)
			{
				if (m_imap.getMazeMap(curX - 1, curY) == ROAD )
				{
					exX = curX;
					exY = curY;
					curX = curX - 1;
					curY = curY;
					m_iPersonDir = UP;
				}
				else if (m_imap.getMazeMap(curX - 1, curY) == WALL)
				{
					if (m_imap.getMazeMap(curX, curY - 1) == ROAD)
					{
						exX = curX;
						exY = curY;
						curX = curX;
						curY = curY - 1;
						m_iPersonDir = LEFT;
					}
					else if (m_imap.getMazeMap(curX, curY - 1) == WALL)
					{
						exX = curX;
						exY = curY;
						curX = curX + 1;
						curY = curY;
						m_iPersonDir = DOWN;
					}
				}
			}
		}

		//(exX == curX - 1 && exY == curY) && m_imap.getMazeMap(curX - 1,curY - 1) == WALL
		else if (m_iPersonDir == DOWN)
		{
			//2
			if (m_imap.getMazeMap(curX,curY-1) == ROAD )
			{
				exX = curX;
				exY = curY;
				curX = curX;
				curY = curY-1;
				m_iPersonDir = LEFT;

			}
			else if (m_imap.getMazeMap(curX,curY-1) == WALL)
			{
				if (m_imap.getMazeMap(curX+1, curY) == ROAD )
				{
					exX = curX;
					exY = curY;
					curX = curX + 1;
					curY = curY;
					m_iPersonDir = DOWN;
				}
				else if (m_imap.getMazeMap(curX+1, curY) == WALL)
				{
					if (m_imap.getMazeMap(curX, curY+1) == ROAD)
					{
						exX = curX;
						exY = curY;
						curX = curX;
						curY = curY+1;
						m_iPersonDir = RIGHT;
					}
					else if (m_imap.getMazeMap(curX, curY+1) == WALL)
					{
						exX = curX;
						exY = curY;
						curX = curX - 1;
						curY = curY;
						m_iPersonDir = UP;
					}
				}
			}
		}

		//(exX == curX && exY == curY + 1) && m_imap.getMazeMap(curX - 1,curY + 1) == WALL
		else if (m_iPersonDir == LEFT)
		{
			//3
			if (m_imap.getMazeMap(curX-1,curY) == ROAD )
			{
				exX = curX;
				exY = curY;
				curX = curX-1;
				curY = curY;
				m_iPersonDir = UP;

			}
			else if (m_imap.getMazeMap(curX-1,curY) == WALL)
			{
				if (m_imap.getMazeMap(curX, curY-1) == ROAD )
				{
					exX = curX;
					exY = curY;
					curX = curX;
					curY = curY-1;
					m_iPersonDir = LEFT;
				}
				else if (m_imap.getMazeMap(curX, curY-1) == WALL)
				{
					if (m_imap.getMazeMap(curX+1, curY) == ROAD)
					{
						exX = curX;
						exY = curY;
						curX = curX + 1;
						curY = curY;
						m_iPersonDir = DOWN;
					}
					else if (m_imap.getMazeMap(curX+1, curY) == WALL)
					{
						exX = curX;
						exY = curY;
						curX = curX;
						curY = curY + 1;
						m_iPersonDir = RIGHT;
					}
				}
			}
		}

		//(exX == curX && exY == curY - 1) && m_imap.getMazeMap(curX + 1,curY - 1) == WALL
		else if (m_iPersonDir == RIGHT)
		{
			//4
			if (m_imap.getMazeMap(curX+1,curY) == ROAD )
			{
				exX = curX;
				exY = curY;
				curX = curX+1;
				curY = curY;
				m_iPersonDir = DOWN;

			}
			else if (m_imap.getMazeMap(curX+1,curY) == WALL)
			{
				if (m_imap.getMazeMap(curX, curY+1) == ROAD )
				{
					exX = curX;
					exY = curY;
					curX = curX;
					curY = curY+1;
					m_iPersonDir = RIGHT;
				}
				else if (m_imap.getMazeMap(curX, curY+1) == WALL)
				{
					if (m_imap.getMazeMap(curX-1, curY) == ROAD)
					{
						exX = curX;
						exY = curY;
						curX = curX-1;
						curY = curY;
						m_iPersonDir = UP;
					}
					else if (m_imap.getMazeMap(curX-1, curY) == WALL)
					{
						exX = curX;
						exY = curY;
						curX = curX;
						curY = curY-1;
						m_iPersonDir = LEFT;
					}
				}
			}
		}
		m_curPosition.setX(curX);
		m_curPosition.setY(curY);
		success++;
		cout << "the " << success << "th:";
		cout << "(" << m_curPosition.getX() << "," << m_curPosition.getY() << ")" << endl;
		gotoxy(m_stPosition.getX(), m_stPosition.getY());
	}
	return success;
}      

