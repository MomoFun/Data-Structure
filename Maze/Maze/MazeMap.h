#ifndef __MAZEMAP_H_H
#define __MAZEMAP_H_H

class MazeMap
{
public:
	//MazeMap();
	// 构造函数初始化
	MazeMap(int *map, int row, int column) : m_iMap(map), m_iRow(row), m_iColumn(column)
	{

	}
	// 提供给外面的接口，用于设置迷宫map[rowIdx][colIdx]的值
	void setMazeMap(int rowIdx, int colIdx, int value);
	
	// 提供给外面的接口，用于获取迷宫map[rowIdx][colIdx]的值
	int getMazeMap(int rowIdx, int colIdx);
	void setMazeWall(char _wall, char _road);
	void drawMap();
	int getRow();
	int getColumn();

private:
	char m_cWall;
	char m_cRoad;
	int m_iRow;
	int m_iColumn;
	int *m_iMap;
};

#endif