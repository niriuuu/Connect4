#include <SFML/Graphics.hpp>
#include "Game.h"
#include "Grid.h"
#include "Token.h"

using namespace sf;
using namespace std;

Game::Game()
{
	_gameOver = false;
	_playerTurn = 1;
}

Game::~Game()
{
}

int Game::play(RenderWindow& window)
{
	int winner = 0;
	const int moveDistance = 66;
	int activeColumn = 3;
	int activeRow = 0;
	int lowBound = 500 - 16;

	RectangleShape background;
	Color backgroundColor(Uint8(35), Uint8(75), Uint8(20), Uint8(255));

	Grid grid(500, 500, 150, 50);

	Token token(Color::Blue);
	vector<Token> tokens;

	Clock clock;
	Time time;

	background.setSize(Vector2f(800, 600));
	background.setFillColor(backgroundColor);

	//grid.setSize(Vector2f(500, 500));
	//grid.setPosition(Vector2f((window.getSize().x - grid.getSize().x) / 2, (window.getSize().y - grid.getSize().y) / 2)); //Positionne la grille au centre de la fenetre

	while (window.isOpen() && !_gameOver)
	{
		Event event;
		handleEvent(event, window);

		if (_dir == LEFT)
		{
			if (token.getCircle().getPosition().x > grid.getRectangle().getGlobalBounds().left + token.getCircle().getRadius())
			{
				token.getCircle().move(-moveDistance, 0);
				activeColumn--;
			}
				
			_dir = NONE;
		}
		else if (_dir == RIGHT)
		{
			if (token.getCircle().getPosition().x < grid.getRectangle().getGlobalBounds().left + 500 - 100)
			{
				token.getCircle().move(moveDistance, 0);
				activeColumn++;
			}
				
			_dir = NONE;
		}

		if (_dir == DOWN)
		{
			activeRow = 0;
			while (grid.getSpace(activeRow, activeColumn) != 0)
			{
				activeRow++;
			}
		}

		/*Animation: chaque 10 millisecondes, le jeton se déplace de 10 pixels vers le bas jusqu'à-ce qu'il rencontre le bas de la grille(lowBound), ajusté selon la rangée active.*/

		time = clock.getElapsedTime();

		if (time.asMilliseconds() >= 10) 
		{
			if (_dir == DOWN)
			{
				token.getCircle().move(0, 10);

				if (token.getCircle().getPosition().y + token.getCircle().getRadius() >= lowBound - activeRow * (moveDistance + 9))
				{
					if (_playerTurn == 1)
					{	
						tokens.push_back(token);
						grid.changeSpace(activeRow, activeColumn, 1);
						token.getCircle().setFillColor(Color::Red);
						_playerTurn = 2;
					}
					else
					{
						tokens.push_back(token);
						grid.changeSpace(activeRow, activeColumn, 2);
						token.getCircle().setFillColor(Color::Blue);
						_playerTurn = 1;
					}

					_dir = NONE;
					token.resetPos();
					activeColumn = 3;
					activeRow = 0;

					//validateur
					validateGame(1, grid);
					validateGame(2, grid);

				}
			}


			window.clear(Color::Black);

			window.draw(background);

			window.draw(token.getCircle());

			for (int i = 0; i < tokens.size(); i++)
			{
				window.draw(tokens[i].getCircle());
			}

			window.draw(grid.getRectangle());

			window.display();

			clock.restart();
		}
	}

    return winner;
}

void Game::handleEvent(Event& event, RenderWindow& window)
{
	while (window.pollEvent(event))
	{
		switch (event.type)
		{
		case Event::Closed:
		{
			window.close();
			break;
		}
		case Event::KeyPressed:
		{
			switch (event.key.code)
			{
			case Keyboard::Left:
			{
				if (_dir == NONE)
					_dir = LEFT;
				break;
			}
			case Keyboard::Right:
			{
				if (_dir == NONE)
					_dir = RIGHT;
				break;
			}
			case Keyboard::Down:
			{
				if (_dir == NONE)
					_dir = DOWN;
				break;
			}
			default:
				break;
			}
		}
		default:
			break;
		}
	}
}

void Game::validateGame(int joueur, Grid& grid)
{
	int compteur = 0;

	for (int i = 0; i < 6; i++)
	{
		for (int j = 0; j < 7; j++)
		{
			if (grid.getSpace(i, j) == joueur)
			{
				compteur++;
			}

			else
			{
				compteur = 0;
			}

			if (compteur == 4)
			{
				_gameOver = joueur;
			}
		}
	}

	for (int i = 0; i < 7; i++)
	{
		for (int j = 0; j < 6; j++)
		{
			if (grid.getSpace(j, i) == joueur)
			{
				compteur++;
			}

			else
			{
				compteur = 0;
			}

			if (compteur == 4)
			{
				_gameOver = joueur;
			}
		}
	}
}
