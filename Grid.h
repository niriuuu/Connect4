#pragma once

class Grid
{
private:
	sf::RectangleShape _grid;
	sf::Texture _textureGrid;
	std::vector<bool> placeDisponible;

public:
	Grid();
	~Grid();

	void inititaliserGrid(int x, int y); //CC : On pourrait ajouter des variables dans le private pour les dimensions et la position de la grille. Ensuite faire un constructeur avec parametres au lieu de cette methode.

};

