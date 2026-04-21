#pragma once

class Grid
{
private:
	sf::RectangleShape _rectangle;
	sf::Texture _textureGrid;
	std::vector<std::vector<int>> _spaces;

	int _width = 0;
	int _height = 0;
	int _x = 0;
	int _y = 0;

public:
	Grid();
	Grid(int _width, int _height, int _x, int _y);
	~Grid();

	sf::RectangleShape& getRectangle();
};

