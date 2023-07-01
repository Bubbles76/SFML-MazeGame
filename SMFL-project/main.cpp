#include <SFML/Graphics.hpp>
#include"sizes.h"
#include"cell.h"
#include <memory>
#include<iostream>




int main()
{
	//vector array x and y 
	std::vector<Cell> Grid;

	// for every row go through every column and create each cell
	for (int X = 0; X < rows(); X++)
	{
		for (int Y = 0; Y < columns(); Y++)
		{
			// smart pointer 
			std::unique_ptr<Cell> Cprt (new Cell(X, Y));
			// push Cell x,y on to the stack (insert elements at the end of the vector.)
			Grid.push_back(Cell(X, Y));
		}
	}

	//Cell Current = Grid[0];
	
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
			Grid[3].visitedCell = {true};
			Cell CheckNeigborCells();
		
		}
 
		window.display();
	}

	

	return 0;
}







