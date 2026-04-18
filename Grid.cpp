#include "Grid.h"

using namespace std;

vector<bool>placeDisponible;

Grid::Grid()
{
}

Grid::~Grid()
{
}

void Grid::inititaliserGrid(int x, int y)
{
	_grid.setSize(Vector2f(x, y));
}
