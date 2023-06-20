#pragma once

class Cell
{

public:

	int X, Y;
	bool visitedCell;


	Cell(int x, int y)
	{
		X = x;
		Y = y;

		int Current;
		visitedCell= false;

	}

void draw(sf::RenderWindow& showWindow);

};






