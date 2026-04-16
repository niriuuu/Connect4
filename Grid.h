#pragma once
#include <SFML/Graphics.hpp>

using namespace sf;

class Grid
{
private:
	RectangleShape _grid;
	Texture _textureGrid;
public:
	Grid();
	~Grid();

	void inititaliserGrid(int x, int y);

};

