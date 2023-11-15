#pragma once

class Cell
{
public:

	void Draw(sf::RenderWindow& showWindow);
	Cell CheckNeigborCells(std::vector<Cell>& Grid);
	void CellVistedColour(sf::RenderWindow& showWindow);

	int X, Y;

	bool Available = false;
	bool VisitedCell = false;
	int  size = 40;
	
	//array
	std::vector<bool> Walls;
	std::vector<Cell> Neighbors;
	
	Cell(int x, int y)
	{
		X = x;
		Y = y;
		
		//bool array to store visited cells false when unvisited
		VisitedCell = { false};
		// bool array top,right,bottom,left, N,E,S,W True to draw gridded lines false to remove them 
		Walls = { true,true,true,true };
		// cell location exists 
		Available = { true };
	}
};