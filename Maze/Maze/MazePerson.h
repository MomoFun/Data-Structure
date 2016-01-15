#include "Position.h"
#include "MazeMap.h"
#include<windows.h> 

class MazePerson
{
public:
	// 给人一个地图
	MazePerson(int x,int y, MazeMap &map) : m_imap(map), m_curPosition(x, y), m_exPosition(-1, -1), m_stPosition(x, y)
	{

	}
	void setPersonPosition(int x, int y);
	void setPersonSpeed(int spd);
	void setPersonChar(char shpe);
	int start();
	void gotoxy(int x,int y);

private:

	char m_cPersonShap;
	int m_iPersonDir;
	int m_iSpeed;
	Position m_stPosition;
	Position m_exPosition;
	Position m_curPosition;
	MazeMap &m_imap;
};