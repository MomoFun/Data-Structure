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

bool operator==(Position& p1, Position &p2)
{
	if (p1.getX() == p2.getX() && p1.getY() == p2.getY())
	{
		return true;
	}

	return false;
}

//�����������
void MazePerson::setPersonPosition(int x, int y)
{
	m_stPosition.setX(x);
	m_stPosition.setY(y);
}

//�����ٶ�
void MazePerson::setPersonSpeed(int spd)
{
	m_iSpeed = spd;
}

//���ñ�ʾ�˵��ַ�
void MazePerson::setPersonChar(char shpe)
{
	m_cPersonShap = shpe;
}

void MazePerson::gotoxy(int x,int y)
{
	cout << char(8) << " ";
	COORD cd;
	cd.X = y;
	cd.Y = x+1;
	HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleCursorPosition(handle,cd);
	cout << m_cPersonShap;
	//system("pause");
	Sleep(m_iSpeed);
}

//��ʼ���Թ�
void MazePerson::start()
{
	int exX;
	int exY;
	int curX;
	int curY;

	//��ȡ��ʼ������
	success++;
	int initX = m_stPosition.getX();
	int initY = m_stPosition.getY();
    gotoxy(m_stPosition.getX(), m_stPosition.getY());
// 	cout << "the " << success << "th:";
// 	cout << "(" << m_stPosition.getX() << "," << m_stPosition.getY() << ")" << endl;

	
	//�õ���������
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
	gotoxy(m_curPosition.getX(), m_curPosition.getY());
// 	cout << "the " << success << "th:";
// 	cout << "(" << m_curPosition.getX() << "," << m_curPosition.getY() << ")" << endl;

	//�õ������������һ����
	while (curX > 0 && curY > 0 && curX < m_imap.getRow()-1 && curY < m_imap.getColumn()-1)
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
// 		cout << "the " << success << "th:";
// 		cout << "(" << m_curPosition.getX() << "," << m_curPosition.getY() << ")" << endl;
		gotoxy(m_curPosition.getX(), m_curPosition.getY());
	}
	gotoxy(m_imap.getRow()+1,0);
	if (!(m_curPosition == m_stPosition))
	{
		cout << "���ĵ�˵���������ҳ���������" << endl;
		cout << "���ܹ�����" << success << "����" << endl;
	}
	else if(m_curPosition == m_stPosition)
	{
		cout << "������˵��ˣ�ҿ���������" << endl;
		cout << "���ܹ�����" << success << "����" << endl;
	}
}      

