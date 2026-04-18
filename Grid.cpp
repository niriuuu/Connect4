#include <SFML/Graphics.hpp>
#include <vector>
#include "Grid.h"

using namespace sf;
using namespace std;

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
