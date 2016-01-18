#include "MazePerson.h"
#include <iostream>
using namespace std;

//宏定义地图
#define WALL 0
#define ROAD 1

//宏定义方向
#define UP 0
#define LEFT 1
#define DOWN 2
#define RIGHT 3

const int MazePerson::m_Next[4][2] = {{-1, 0},{0, -1},{1, 0},{0, 1}};

//重载符号函数，比较两个Position对象的坐标是否相同
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

//设置光标指向位置
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
	int curX;
	int curY;
	/*int next[4][2] = {{-1, 0},{0, -1},{1, 0},{0, 1}}; //下一位置*/

	//获取初始点坐标
	m_iSteps = 0;
	int initX = m_stPosition.getX();
	int initY = m_stPosition.getY();
	gotoxy(m_stPosition.getX(), m_stPosition.getY());

	//得到第二个点
	m_exPosition = m_stPosition;
	int i = RIGHT;	//×第一步存在随机性，而且局限大
	while (m_imap.getMazeMap(initX + m_Next[i][0],initY + m_Next[i][1]) != WALL
		|| m_imap.getMazeMap(initX + m_Next[(i+1)%4][0], initY + m_Next[(i+1)%4][1]) != ROAD)
	{
		i = (i + 1)%4;
	}
	m_iCurDir = (i+1)%4;
	m_curPosition = toNextPositon(m_iCurDir);
	curX = m_curPosition.getX();
	curY = m_curPosition.getY();
	m_iSteps++;

	//得到第三个到最后一个点
	while (curX > 0 && curY > 0 && curX < m_imap.getRow()-1 && curY < m_imap.getColumn()-1)
	{
		exDir = m_iCurDir;
		m_exPosition = m_curPosition;
		int i = exDir - 1 + 4;

		while(m_imap.getMazeMap(m_exPosition.getX() + m_Next[i%4][0], m_exPosition.getY() + m_Next[i%4][1])!= ROAD)
		{
			i++;
		}
		m_iCurDir = i;
		m_curPosition = toNextPositon(m_iCurDir);
		curX = m_curPosition.getX();
		curY = m_curPosition.getY();
		m_iSteps++;
	}
	gotoxy(m_imap.getRow()+1,0);
	if (!(m_curPosition == m_stPosition))
	{
		cout << "开心地说：哈哈，我出来咯～～" << endl;
		cout << "（总共走了" << m_iSteps << "步）" << endl;
	}
	else if(m_curPosition == m_stPosition)
	{
		cout << "生气地说：耍我咯！！！！" << endl;
		cout << "（总共走了" << m_iSteps << "步）" << endl;
	}
}      

Position MazePerson::toNextPositon(int dir)
{
	/*int next[4][2] = {{-1, 0},{0, -1},{1, 0},{0, 1}}; //下一位置*/
	m_curPosition.setX(m_exPosition.getX() + m_Next[dir%4][0]);
	m_curPosition.setY(m_exPosition.getY() + m_Next[dir%4][1]);
	gotoxy(m_curPosition.getX(), m_curPosition.getY());
	return m_curPosition;
}
