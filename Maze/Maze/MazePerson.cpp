#include "MazePerson.h"
#include <iostream>
using namespace std;

#define WALL 0
#define ROAD 1

#define UP 0
#define LEFT 1
#define DOWN 2
#define RIGHT 3

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

//设置入口坐标
void MazePerson::setPersonPosition(int x, int y)
{
	m_stPosition.setX(x);
	m_stPosition.setY(y);
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

//开始走迷宫
void MazePerson::start()
{
	int exDir;
	int exX;
	int exY;
	int curX;
	int curY;
	int next[4][2] = {{-1, 0},{0, -1},{1, 0},{0, 1}};

	//获取初始点坐标
	success++;
	int initX = m_stPosition.getX();
	int initY = m_stPosition.getY();
	gotoxy(m_stPosition.getX(), m_stPosition.getY());

	//得到第两个点
	m_exPosition = m_stPosition;
	int i = RIGHT;
	while (m_imap.getMazeMap(initX + next[i][0],initY + next[i][1]) != WALL
		|| m_imap.getMazeMap(initX + next[(i+1)%4][0], initY + next[(i+1)%4][1]) != ROAD)
	{
		i = (i + 1)%4;
	}
	m_iPersonDir = (i+1)%4;
	curX = m_exPosition.getX() + next[m_iPersonDir][0];
	curY = m_exPosition.getY() + next[m_iPersonDir][1];
	m_curPosition.setX(curX);
	m_curPosition.setY(curY); 
	success++;
	gotoxy(m_curPosition.getX(), m_curPosition.getY());

	//得到第三个到最后一个点
	while (curX > 0 && curY > 0 && curX < m_imap.getRow()-1 && curY < m_imap.getColumn()-1)
	{
		exDir = m_iPersonDir;
		m_exPosition = m_curPosition;
		int i = exDir - 1 + 4;

		while(m_imap.getMazeMap(m_exPosition.getX() + next[i%4][0], m_exPosition.getY() + next[i%4][1])!= ROAD)
		{
			i++;
		}
		m_iPersonDir = i;
		curX = m_exPosition.getX() + next[i%4][0];
		curY = m_exPosition.getY() + next[i%4][1];
		m_curPosition.setX(curX);
		m_curPosition.setY(curY);
		success++;
		gotoxy(m_curPosition.getX(), m_curPosition.getY());
	}
	gotoxy(m_imap.getRow()+1,0);
	if (!(m_curPosition == m_stPosition))
	{
		cout << "开心地说：哈哈，我出来咯～～" << endl;
		cout << "（总共走了" << success << "步）" << endl;
	}
	else if(m_curPosition == m_stPosition)
	{
		cout << "生气地说：耍我咯！！！！" << endl;
		cout << "（总共走了" << success << "步）" << endl;
	}
}      

