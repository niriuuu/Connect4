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

	void inititaliserGrid(int x, int y); //CC : On pourrait ajouter des variables dans le private pour les dimensions et la position de la grille. Ensuite faire un constructeur avec parametres au lieu de cette methode.

};

