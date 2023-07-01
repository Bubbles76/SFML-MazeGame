#include <SFML/Graphics.hpp>
#include"sizes.h"
#include"cell.h"
#include<iostream>

#include<cmath>

void Cell::draw(sf::RenderWindow& showWindow)
{
	//int i = this->X * cellWidthHeight();
	//int j = this->Y * cellWidthHeight();

	Cell::walls;
	Cell::visitedCell;

	sf::VertexArray lines(sf::Lines, 8);

	if (walls[0])
	{
		// clockwise N,E,S,W 
		//top left corner
		lines[0].position = sf::Vector2f(i, j);
		lines[1].position = sf::Vector2f(i + cellWidthHeight(), j);
	}

	if (walls[1])
	{
		//top right corner
		lines[2].position = sf::Vector2f(i + cellWidthHeight(), j);
		lines[3].position = sf::Vector2f(i + cellWidthHeight(), j + cellWidthHeight());
	}

	if (walls[2])
	{
		//bottom right corner 
		lines[4].position = sf::Vector2f(i + cellWidthHeight(), j + cellWidthHeight());
		lines[5].position = sf::Vector2f(i, j + cellWidthHeight());
	}

	if (walls[3])
	{
		//bottom left corner
		lines[6].position = sf::Vector2f(i, j + cellWidthHeight());
		lines[7].position = sf::Vector2f(i, j);
	}

	//visited cell too equal true 
	if (visitedCell[0] == true)
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
		Rect.setPosition(i, j);

		showWindow.draw(Rect);


	}

	//prints out the cells
	showWindow.draw(lines);

}
void Cell::CheckNeigborCells(std::vector<Cell>& Grid)
{
	std::vector<Cell> Neighbors;
	
	Cell top = Grid[index(i, j - 1)];

	Cell right = Grid[index(i + 1, j)];

	Cell bottom = Grid[index(i, j + 1)];

	Cell left = Grid[index(i - 1, j)];



	//if (top.real && !top.visitedCell)
	//{
	//	Neighbors.push_back(top);
	//}

	//if (right.real && !right.visitedCell)
	//{
	//	Neighbors.push_back(right);
	//}

	//if (bottom.real && !bottom.visitedCell)
	//{
	//	Neighbors.push_back(bottom);
	//}

	//if (left.real && !left.visitedCell)
	//{
	//	Neighbors.push_back(left);
	//}



}

