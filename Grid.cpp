#include <SFML/Graphics.hpp>
#include <vector>
#include "Grid.h"

using namespace sf;
using namespace std;

Grid::Grid()
{
	_width = 0;
	_height = 0;
	_x = 0;
	_y = 0;
}

Grid::Grid(int width, int height, int x, int y)
{
	_width = width;
	_height = height;
	_x = x;
	_y = y;

	

	if (!_textureGrid.loadFromFile("Grid.png")) {
		exit(1); // Si incapable de charger, on quitte avec un code d'erreur
	}

	_rectangle.setTexture(&_textureGrid); // Applique la texture reellement souhaitee
	_rectangle.setSize(Vector2f(500, 500));
	_rectangle.setPosition(Vector2f(_x, _y)); //Positionne la grille au centre de la fenetre
}

Grid::~Grid()
{
	int _width = 0;
	int _height = 0;
	int _x = 0;
	int _y = 0;
}

void Grid::inititaliserGrid(int x, int y)
{
	/*_grid.setSize(Vector2f(x, y));*/
}

sf::RectangleShape& Grid::getRectangle()
{
	return _rectangle;
}