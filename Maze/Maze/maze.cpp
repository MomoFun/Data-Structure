#include "MazeMap.h"
#include "MazePerson.h"
#include <iostream>
using namespace std;

#define WALL 0
#define ROAD 1
#define FAST 1
#define SLOW 0

int SUCCESS = 0;

int main()
{
	int map[8][9]= {
		{WALL,WALL,WALL,WALL,WALL,WALL,WALL,ROAD,WALL},
		{WALL,WALL,WALL,WALL,ROAD,WALL,WALL,ROAD,WALL},
		{WALL,WALL,WALL,WALL,ROAD,WALL,WALL,ROAD,WALL},
		{WALL,WALL,WALL,WALL,ROAD,WALL,WALL,ROAD,WALL},
		{WALL,WALL,ROAD,ROAD,ROAD,ROAD,WALL,ROAD,WALL},
		{WALL,WALL,ROAD,WALL,WALL,ROAD,ROAD,ROAD,WALL},
		{WALL,ROAD,ROAD,WALL,WALL,WALL,WALL,WALL,WALL},
		{WALL,ROAD,WALL,WALL,WALL,WALL,WALL,WALL,WALL}
	};
	//MazeMap maze;
	MazeMap maze(&map[0][0], 8, 9);
	maze.setMazeMap(8,9, WALL);
	maze.setMazeWall('*',' ');
	maze.drawMap();

	MazePerson mazer(7,1,maze);
	mazer.setPersonPosition(7,1);
	mazer.setPersonSpeed(FAST);
	mazer.setPersonChar('T');
	SUCCESS = mazer.start();
	cout << SUCCESS << endl;

	system("pause");
	return 0;
}