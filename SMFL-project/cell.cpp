#include <SFML/Graphics.hpp>
#include"sizes.h"
#include"cell.h"
#include<iostream>

#include<cstdlib>
#include<ctime>
#include<cmath>

void Cell::Draw(sf::RenderWindow& showWindow)
{
	sf::VertexArray lines(sf::Lines, 8);

	// SFML function class  to  (position, rotation, scale, outline, colour, texture)
	sf::RectangleShape Rect;

	int posX = X * size;
	int posY = Y * size;

	// boolean array 
	if (Walls[0])
	{
		// clockwise N,E,S,W 
		//top left corner   // convert int i and j to floats 
		lines[0].position = sf::Vector2f(posX, posY);
		lines[1].position = sf::Vector2f(posX + cellSize(), posY);
	}
	if (Walls[1])
	{
		//top right corner
		lines[2].position = sf::Vector2f(posX + cellSize(), posY);
		lines[3].position = sf::Vector2f(posX + cellSize(), posY + cellSize());
	}
	if (Walls[2])
	{
		//bottom right corner 
		lines[4].position = sf::Vector2f(posX + cellSize(),posY + cellSize());
		lines[5].position = sf::Vector2f(posX, posY + cellSize());
	}
	if (Walls[3])
	{
		//bottom left corner
		lines[6].position = sf::Vector2f(posX, posY + cellSize());
		lines[7].position = sf::Vector2f(posX, posY);
	}

	//visited cell too equal true 
	if (VisitedCell)
	{
		//outline cell
		Rect.setOutlineThickness(0);
		//set the size of cell
		Rect.setSize(sf::Vector2f(cellSize(),cellSize()));
		//set and fill the colour of the cell
		Rect.setFillColor(sf::Color(255, 0, 255, 100));
		//set the position of the rectangle 
		Rect.setPosition(X * size,Y * size);
	}
	else
	{
		//outline cell
		Rect.setOutlineThickness(0);
		//set the size of cell
		Rect.setSize(sf::Vector2f(cellSize(), cellSize()));
		//set and fill the colour of the cell
		Rect.setFillColor(sf::Color(0, 0, 0, 100));
		//set the position of the rectangle 
		Rect.setPosition(X * size, Y * size);
	}

	//print the visited cell 
	showWindow.draw(Rect);
	//prints out the Grid lines to create the cells
	showWindow.draw(lines);
}


Cell Cell::CheckNeigborCells(std::vector<Cell>& Grid)
{
	Neighbors.clear();
	// location of neighboring cells
	Cell &TopCell    = Grid[index(Y    , X - 1)];// above the main cell
	Cell &RightCell  = Grid[index(Y + 1, X    )];// right side of the main cell
	Cell &BottomCell = Grid[index(Y   ,  X + 1)];// below of the main cell
	Cell &LeftCell   = Grid[index(Y - 1, X    )];//left side of the main cell

	// check that the cell location exists and if the cell has NOT been visited
	if (TopCell.Available && !TopCell.VisitedCell)
	{
		Neighbors.push_back(TopCell);// add cell to the neighbors array
	}
	if (RightCell.Available && !RightCell.VisitedCell)
	{
		Neighbors.push_back(RightCell);
	}
	if (BottomCell.Available && !BottomCell.VisitedCell)
	{
		Neighbors.push_back(BottomCell);
	}
	if (LeftCell.Available && !LeftCell.VisitedCell)
	{
		Neighbors.push_back(LeftCell);
	}

	//neighbors array size being more then 0
	if (Neighbors.size() > 0)
	{
		// create a random number to pick the neighboring cell
		srand((unsigned)time(NULL));
		int RandomNumber = (rand() % Neighbors.size());

		//return to random neighboring cell
		return Neighbors[RandomNumber];

	}

	// return current cell
	return *this;

}

void Cell::CellVistedColour(sf::RenderWindow& showWindow)
{
	// SFML function class  to  (position, rotation, scale, outline, colour, texture)
	sf::RectangleShape Rect;
	//outline cell
	Rect.setOutlineThickness(0);
	//set the size of cell
	Rect.setSize(sf::Vector2f(cellSize(), cellSize()));
	//set and fill the colour of the cell
	Rect.setFillColor(sf::Color(255, 255, 255, 255));
	//set the position of the rectangle 
	Rect.setPosition(X*size,Y*size);

	//print the visited cell 
	showWindow.draw(Rect);
}