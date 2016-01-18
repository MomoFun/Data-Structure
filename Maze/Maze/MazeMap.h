#ifndef __MAZEMAP_H_H
#define __MAZEMAP_H_H

class MazeMap
{
public:
	//MazeMap();
	// ���캯����ʼ��
	MazeMap(int *map, int row, int column) : m_iMap(map), m_iRow(row), m_iColumn(column)
	{

	}
	// �ṩ������Ľӿڣ����������Թ�map[rowIdx][colIdx]��ֵ
	void setMazeMap(int rowIdx, int colIdx, int value);
	
	// �ṩ������Ľӿڣ����ڻ�ȡ�Թ�map[rowIdx][colIdx]��ֵ
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