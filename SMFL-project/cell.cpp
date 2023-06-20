#include <SFML/Graphics.hpp>
#include"sizes.h"
#include"cell.h"

#include<cmath>

void Cell::draw(sf::RenderWindow& showWindow)
{
	int i = this->X * cellWidthHeight();

	int j = this->Y * cellWidthHeight();

	
	// bool array top, right,bottom,left, NESW 
	std::vector<bool> walls = { true,true,true,true };

	//std::vector<bool> visitedCell = { false };
	
	

	sf::VertexArray lines(sf::Lines, 8);


	if (walls[0])
	{
		// clockwise NESW
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
		//bottom left corner 
		lines[4].position = sf::Vector2f(i + cellWidthHeight(), j + cellWidthHeight());
		lines[5].position = sf::Vector2f(i, j + cellWidthHeight());
	}

	if (walls[3])
	{
		//bottom right corner
		lines[6].position = sf::Vector2f(i, j + cellWidthHeight());
		lines[7].position = sf::Vector2f(i, j);
	}

	if (visitedCell == true)
	{
		sf::RectangleShape Rect;
		Rect.setOutlineThickness(0);
		Rect.setSize(sf::Vector2f(cellWidthHeight(), cellWidthHeight()));
		Rect.setFillColor(sf::Color(255, 0, 255, 100));
		Rect.setPosition(i, j);

		showWindow.draw(Rect);
		
	}

	//prints out the cells
	showWindow.draw(lines);


}


