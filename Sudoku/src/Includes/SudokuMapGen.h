#pragma once

#include <vector>
#include<iostream>

struct Field {

	int row, col;
};

class SudokuMapGen
{

public:

	static constexpr int MaxSize = 9;

	int gameMap[MaxSize][MaxSize] = {

	{7,8,0,4,0,0,1,2,0},
	{6,0,0,0,7,5,0,0,9},
	{0,0,0,6,0,1,0,7,8},
	{0,0,7,0,4,0,2,6, 0},
	{0,0,1,0,5,0,9,3,0},
	{9,0,4,0,6,0,0,0,5},
	{0,7,0,3,0,0,0,1,2},
	{1,2,0,0,0,7,4,0,0},
	{0,4,9,2,0,6,0,0,7}

	};

	SudokuMapGen() {
	}


	bool Solve(int grid[MaxSize][MaxSize]);
	bool FindUnassignedLocation(int grid[MaxSize][MaxSize], int&, int&);
	bool isSafe(int grid[MaxSize][MaxSize], int, int, int);
	void printGrid(int grid[MaxSize][MaxSize]);

private:

	bool UsedInRow(int grid[MaxSize][MaxSize], int row, int value, int currentCol);
	bool UsedInCol(int grid[MaxSize][MaxSize], int col, int value, int CurrentRow);
	bool UsedInBox(int grid[MaxSize][MaxSize], int, int, int, Field gameField);

};

