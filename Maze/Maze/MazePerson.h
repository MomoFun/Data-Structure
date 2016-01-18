#include "Position.h"
#include "MazeMap.h"
#include<windows.h> 

class MazePerson
{
public:
	// 给人一个地图
	MazePerson(int x,int y, MazeMap &map) : m_imap(map), m_curPosition(x, y), m_exPosition(x, y), m_stPosition(x, y), m_iSpeed(1000)
	{
		//需要每个对象一份时
// 		int tmp[][2] = {{-1, 0},{0, -1},{1, 0},{0, 1}};
// 		memcpy(&m_Next[0][0], tmp, sizeof(tmp));

	}
	void setPersonPosition(int x, int y);
	void setPersonSpeed(int spd);
	void setPersonChar(char shpe);
	Position toNextPositon(int dir);
	void gotoxy(int x,int y);
	void start();


private:

	char m_cPersonShap;
	int m_iExDir;
	int m_iCurDir;
	int m_iSpeed;
	int m_iSteps;
	Position m_stPosition;
	Position m_exPosition;
	Position m_curPosition;
	MazeMap &m_imap;
	static const int m_Next[4][2]; //此类中只有一份	
};