#pragma once

class Grid
{
private:
	sf::RectangleShape _rectangle;
	sf::Texture _textureGrid;
	std::vector<bool> placeDisponible;

	int _width = 0;
	int _height = 0;
	int _x = 0;
	int _y = 0;

public:
	Grid();
	Grid(int _width, int _height, int _x, int _y);
	~Grid();

	void inititaliserGrid(int x, int y); //CC : On pourrait ajouter des variables dans le private pour les dimensions et la position de la grille. Ensuite faire un constructeur avec parametres au lieu de cette methode.
	sf::RectangleShape& getRectangle();
};

