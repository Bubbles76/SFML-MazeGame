#include"sizes.h"
#include<cmath>

//set width of window
int width()
{
	return 400;
}
//set height of window
int height()
{
	return 400;
}
//set size of each cell within the maze
int cellWidthHeight()
{
	return 40;
}
//calculate and set column sizes
int columns()
{
	return floor(width() / cellWidthHeight());
}
// calculate and set row sizes
int rows()
{
	return floor(height() / cellWidthHeight());
}

//
int index(int x, int y)
{
	x;// rows
	y;// columns

	//(x has to be between 0 and columns -1)
	//(y has to be between 0 and rows -1) 

	// all the option are invalid 	
	if (x < 0 || y < 0 || x > columns() - 1 || y > rows() - 1)
	{
		return 0;
	}
	return x + y *columns();
}
