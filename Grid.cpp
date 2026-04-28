#include <SFML/Graphics.hpp>
#include <vector>
#include "Grid.h"

using namespace sf;
using namespace std;

Grid::Grid()
{
	_width = 0;
	_height = 0;
	_xPos = 0;
	_yPos = 0;
}

Grid::Grid(int width, int height, int xPos, int yPos)
{
	_width = width;
	_height = height;
	_xPos = xPos;
	_yPos = yPos;

	if (!_textureGrid.loadFromFile("ressources/Grid.png")) {
		exit(1); // Si incapable de charger, on quitte avec un code d'erreur
	}

	_rectangle.setTexture(&_textureGrid); // Applique la texture reellement souhaitee
	_rectangle.setSize(Vector2f(500, 500));
	_rectangle.setPosition(Vector2f(_xPos, _yPos)); //Positionne la grille au centre de la fenetre

	initSpaces();
}

Grid::~Grid()
{
	_width = 0;
	_height = 0;
	_xPos = 0;
	_yPos = 0;
}

sf::RectangleShape& Grid::getRectangle()
{
	return _rectangle;
}

int Grid::getSpace(int row, int col)
{
	return _spaces[row][col];
}

void Grid::initSpaces()
{
	vector<int> row = { 0, 0, 0, 0, 0, 0, 0 };

	for (int i = 0; i < 6; i++)
	{
		_spaces.push_back(row);
	}
}

void Grid::changeSpace(int row, int col, int value)
{
	_spaces[row][col] = value;
}
