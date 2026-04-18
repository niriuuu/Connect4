#pragma once
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

	bool play(sf::RenderWindow& window);
	void handleEvent(sf::Event& event, sf::RenderWindow& window);

};

