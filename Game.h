#pragma once
#include"Grid.h"
class Game
{
private:
	bool _gameOver;
	int _playerTurn;

	const enum Directions { NONE, LEFT, RIGHT, DOWN };
	Directions _dir = NONE;

public:
	Game();
	~Game();

	int play(sf::RenderWindow& window); //Retourne 0 si egalite, 1 si victoire joueur 1 ou 2 si victoire joueur 2
	void handleEvent(sf::Event& event, sf::RenderWindow& window);
	void validateGame(int joueur, Grid& grid);

};

