#pragma once

class Cell
{

public:

	int X, Y;
	std::vector<bool> visitedCell;
	std::vector<bool> walls;
	int i = this->X * cellWidthHeight();
	int j = this->Y * cellWidthHeight();
	std::vector<bool>real;


	

	Cell(int x, int y)
	{
		X = x;
		Y = y;

		// current cell 
		int Current;

		//bool array to store visited cells false when unvisited
		visitedCell = {false};

		// bool array top,right,bottom,left, N,E,S,W True to draw gridded lines false to remove them 
		walls = { true,true,true,true };

		

	}

void draw(sf::RenderWindow& showWindow);
void CheckNeigborCells(std::vector<Cell>& Grid);

};






