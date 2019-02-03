#include "Maze.h"
#include<fstream>
#include <sstream>
using std::endl;
Maze::Maze(std::istream& inFS)
{

	inFS >> rows;
	inFS >> cols;
	inFS >> layers;
	

	maze = new CellValue**[layers];
	for (int i = 0; i < layers; i++)
	{
		maze[i] = new CellValue*[rows];
		for (int j = 0; j < rows; j++)
		{
			maze[i][j] = new CellValue[cols];
		}
	}

	int cell;
	for (int i=0;i<layers;i++)
	{
		for (int j = 0; j < rows; j++)
		{
			for (int k = 0; k < cols; k++)
			{
				inFS >> cell;
				if (cell == 0)
					maze[i][j][k] = OPEN;

				if (cell == 1)
					maze[i][j][k] = BLOCKED;
			}
		}
	}

}


string Maze::toString () const
{
	std::ostringstream outSS;
	
	for (int i = 0; i < layers; i++)
	{
		outSS << "Layer " << i + 1 << endl;
		for (int j = 0; j < rows; j++)
		{
			for (int k = 0; k < cols; k++)
			{
				int cell = maze[i][j][k];
				if (cell == PATH) { outSS << "2 "; }
				else if (cell == BLOCKED) { outSS << "X "; }
				else if (cell == OPEN||cell==TEMPORARY) { outSS << "_ "; }
				else if (cell == EXIT) { outSS << "3 "; }
			}
			outSS << endl;
		}
		outSS << endl;
	}
	return outSS.str();
}

bool Maze::find_maze_path() 
{
	
	return recursiveSolve(0, 0, 0);
}

bool Maze::recursiveSolve(int x, int y, int z) 
{
	if (x == (layers - 1) && y == (rows - 1) && z == (cols - 1))
	{
		maze[x][y][z] = EXIT;
		return true;
	}
	if (x<0 || x>(layers - 1) || y<0 || y>(rows - 1) || z<0 || z>(cols - 1))
	{
		return false;
	}
	if (maze[x][y][z] == BLOCKED)
	{
		return false;
	}
	if (maze[x][y][z] == TEMPORARY)
	{
		return false;
	}
	if (maze[x][y][z] == PATH)
	{
		return false;
	}

	maze[x][y][z] = PATH;

	if (recursiveSolve(x - 1, y, z) || recursiveSolve(x + 1, y, z) ||
		recursiveSolve(x, y - 1, z) || recursiveSolve(x, y + 1, z) ||
		recursiveSolve(x, y, z - 1) || recursiveSolve(x, y, z + 1))
		return true;

	maze[x][y][z] = TEMPORARY;
	return false;
}

void Maze::setValue(int height, int width, int layer, int value)
{

}

Maze::~Maze()
{
}