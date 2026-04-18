#pragma once
class Game
{
private:
	bool _gameOver;

public:
	Game();
	~Game();

	bool play(sf::RenderWindow& window);

};

