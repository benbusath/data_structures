#ifndef MAZE_H
#define MAZE_H
#include <string>
#include <vector>
#include "MazeInterface.h"

using std::string;
using std::vector;

class Maze : public MazeInterface
{
public: 
	Maze(std::istream& stream);
	~Maze();
	/* I did not end up using the setValue function*/
	void setValue(int height, int width, int layer, int value);
	/*Outputs the maze*/
	string toString() const;
	/*find_maze_path calls on the recursiveSolve function to find a path through the maze*/
	bool find_maze_path();
	/*recursiveSolve takes in coordinate values for the 3D array maze and recursively
	finds a path through the maze*/
	bool recursiveSolve(int x, int y, int z);
private:
	int layers;
	int rows; 
	int cols;
	enum CellValue { OPEN, BLOCKED, PATH, EXIT, TEMPORARY };
	CellValue ***maze=NULL;
};


#endif
