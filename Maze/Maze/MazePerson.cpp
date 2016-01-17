#include "MazePerson.h"
#include <iostream>
using namespace std;

//�궨���ͼ
#define WALL 0
#define ROAD 1

//�궨�巽��
#define UP 0
#define LEFT 1
#define DOWN 2
#define RIGHT 3

const int MazePerson::m_Next[4][2] = {{-1, 0},{0, -1},{1, 0},{0, 1}};

//���ط��ź������Ƚ�����Position����������Ƿ���ͬ
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

//���ù��ָ��λ��
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
	int curX;
	int curY;
	/*int next[4][2] = {{-1, 0},{0, -1},{1, 0},{0, 1}}; //��һλ��*/

	//��ȡ��ʼ������
	m_iSteps = 0;
	int initX = m_stPosition.getX();
	int initY = m_stPosition.getY();
	gotoxy(m_stPosition.getX(), m_stPosition.getY());

	//�õ��ڶ�����
	m_exPosition = m_stPosition;
	int i = RIGHT;	//����һ����������ԣ����Ҿ��޴�
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

	//�õ������������һ����
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
		cout << "���ĵ�˵���������ҳ���������" << endl;
		cout << "���ܹ�����" << m_iSteps << "����" << endl;
	}
	else if(m_curPosition == m_stPosition)
	{
		cout << "������˵��ˣ�ҿ���������" << endl;
		cout << "���ܹ�����" << m_iSteps << "����" << endl;
	}
}      

Position MazePerson::toNextPositon(int dir)
{
	/*int next[4][2] = {{-1, 0},{0, -1},{1, 0},{0, 1}}; //��һλ��*/
	m_curPosition.setX(m_exPosition.getX() + m_Next[dir%4][0]);
	m_curPosition.setY(m_exPosition.getY() + m_Next[dir%4][1]);
	gotoxy(m_curPosition.getX(), m_curPosition.getY());
	return m_curPosition;
}
