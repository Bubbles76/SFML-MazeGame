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
//set size of each cell
int cellWidthHeight()
{
	return 40;
}
//set columns
int columns()
{
	return floor(width() / cellWidthHeight());
}
// set rows
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
