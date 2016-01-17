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
	int exDir;
	int exX;
	int exY;
	int curX;
	int curY;
	int next[4][2] = {{-1, 0},{0, -1},{1, 0},{0, 1}};

	//��ȡ��ʼ������
	success++;
	int initX = m_stPosition.getX();
	int initY = m_stPosition.getY();
	gotoxy(m_stPosition.getX(), m_stPosition.getY());

	//�õ���������
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

	//�õ������������һ����
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
		cout << "���ĵ�˵���������ҳ���������" << endl;
		cout << "���ܹ�����" << success << "����" << endl;
	}
	else if(m_curPosition == m_stPosition)
	{
		cout << "������˵��ˣ�ҿ���������" << endl;
		cout << "���ܹ�����" << success << "����" << endl;
	}
}      

