#include <SFML/Graphics.hpp>
#include"sizes.h"
#include"cell.h"

#include<iostream>


int main()
{
	//vector array
	std::vector<Cell> Grid;
	
	//std::vector<bool> visitedCell = { false};


	// for every row go through every column  
	for (int Y = 0; Y < rows(); Y++)
	{
		for (int X = 0; X < columns(); X++)
		{
			Cell* Cprt = new Cell(X, Y);
			// push Cell x,y on to the stack
			Grid.push_back(Cell(X, Y));
		}
	}

	
	Cell Current = Grid[0];
	

	

	// open a window set height() and width() "name on window" ;
	sf::RenderWindow window(sf::VideoMode(height(), width()), "SFML");

	//while loop to keep window open
	while (window.isOpen())
	{
		// create event
		sf::Event evnt;
		while (window.pollEvent(evnt))
		{
			if (evnt.type == sf::Event::Closed)

				window.close();
		}

		window.clear();

		for (int i = 0; i < Grid.size(); i++)
		{
			//draw out set gridded lines 
			Grid[i].draw(window);
			
			// set grid cell(top left) Visited cell to true to test 
			Grid[0].visitedCell = {true};
		
		}
 
		window.display();
	}


	return 0;
}







