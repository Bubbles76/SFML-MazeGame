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

	// boolean array 
	if (Walls[0])
	{
		// clockwise N,E,S,W 
		//top left corner
		lines[0].position = sf::Vector2f(i, j);
		lines[1].position = sf::Vector2f(i + cellWidthHeight(), j);
	}

	if (Walls[1])
	{
		//top right corner
		lines[2].position = sf::Vector2f(i + cellWidthHeight(), j);
		lines[3].position = sf::Vector2f(i + cellWidthHeight(), j + cellWidthHeight());
	}

	if (Walls[2])
	{
		//bottom right corner 
		lines[4].position = sf::Vector2f(i + cellWidthHeight(), j + cellWidthHeight());
		lines[5].position = sf::Vector2f(i, j + cellWidthHeight());
	}

	if (Walls[3])
	{
		//bottom left corner
		lines[6].position = sf::Vector2f(i, j + cellWidthHeight());
		lines[7].position = sf::Vector2f(i, j);
	}


	//visited cell too equal true 
	if (VisitedCell)
	{
		// SFML function class  to  (position, rotation, scale, outline, colour, texture)
		sf::RectangleShape Rect;
		//outline cell
		Rect.setOutlineThickness(0);
		//set the size of cell
		Rect.setSize(sf::Vector2f(cellWidthHeight(), cellWidthHeight()));
		//set and fill the colour of the cell
		Rect.setFillColor(sf::Color(255, 0, 255, 100));
		//set the position of the rectangle 
		Rect.setPosition(i,j);

		//print the visited cell 
		showWindow.draw(Rect);

	}
	//prints out the Grid lines to create the cells
	showWindow.draw(lines);
}

Cell Cell::CheckNeigborCells(std::vector<Cell>& Grid)
{
	// location of neighboring cells
	// above the main cell
	Cell TopCell = Grid[index(i, j - 1)];
	// right side of the main cell
	Cell RightCell = Grid[index(i + 1, j)];
	// below of the main cell
	Cell BottomCell = Grid[index(i, j + 1)];
	//left side of the main cell
	Cell LeftCell = Grid[index(i - 1, j)];

	// check that the cell location exists and if the cell has NOT been visited
	if (TopCell.Available && !TopCell.VisitedCell)
	{
		// add cell to the neighbors array
		Neighbors.push_back(TopCell);
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
		srand(time(NULL));
		int RandomNumber = (rand() % Neighbors.size());
		//return to random neighboring cell
		return Neighbors[RandomNumber];
	}
}

