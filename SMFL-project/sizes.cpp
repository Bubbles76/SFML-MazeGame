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
	x;// columns
	y;// rows

	return x + y;
}
