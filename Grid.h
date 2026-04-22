#pragma once

class Grid
{
private:
	sf::RectangleShape _rectangle;
	sf::Texture _textureGrid;
	std::vector<std::vector<int>> _spaces;

	int _width;
	int _height;
	int _xPos;
	int _yPos;

public:
	Grid();
	Grid(int width, int height, int xPos, int yPos);
	~Grid();

	sf::RectangleShape& getRectangle();
	int getSpace(int row, int col);

	void initSpaces();

	void changeSpace(int row, int col, int value);
};

