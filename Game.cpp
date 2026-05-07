#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include "Game.h"
#include "Grid.h"
#include "Token.h"
#include "constants.h"

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

int Game::play(RenderWindow& window, SoundBuffer buffer)
{
	Grid grid(GRIDWIDTH, GRIDHEIGHT, (WINDOWWIDTH - GRIDWIDTH) / 2, (WINDOWHEIGHT - GRIDHEIGHT) / 2);

	int winner = 0;
	
	const int horizontalBorder = 8;
	const int verticalBorder = 17;
	const int moveDistance = TOKENSIZE + horizontalBorder;
	const int lowBound = grid.getRectangle().getPosition().y + GRIDHEIGHT;

	int activeColumn = 3;
	int activeRow = 0;
	int compteur = 0;

	_gameOver = false;
	_playerTurn = 1;

	Sound collisionSound;

	RectangleShape background;

	Token token(Color::Blue);
	vector<Token> tokens;

	Clock clock;
	Time time;

	Text winText;
	Font font;
	
	background.setSize(Vector2f(WINDOWWIDTH, WINDOWHEIGHT));

	if (!_textureBackground.loadFromFile("ressources/Background.jpg")) {
		exit(1); // Si incapable de charger, on quitte avec un code d'erreur
	}

	background.setTexture(&_textureBackground); // Applique la texture reellement souhaitee

	if (!font.loadFromFile("angelina.ttf"))
		exit(1);
	winText.setFont(font);
	winText.setCharacterSize(100);
	winText.setFillColor(Color::White);
	winText.setOutlineColor(Color::Black);
	winText.setOutlineThickness(2);

	while (window.isOpen() && !_gameOver)
	{
		Event event;
		handleEvent(event, window);

		switch (_dir)
		{
			case LEFT:
				if (token.getCircle().getPosition().x > grid.getRectangle().getGlobalBounds().left + token.getCircle().getRadius())
				{
					token.getCircle().move(-moveDistance, 0);
					activeColumn--;
				}
				_dir = NONE;
				break;

			case RIGHT:
				if (token.getCircle().getPosition().x < grid.getRectangle().getGlobalBounds().left + 500 - 100)
				{
					token.getCircle().move(moveDistance, 0);
					activeColumn++;
				}
				_dir = NONE;
				break;

			case DOWN:
				activeRow = 0;
				while (grid.getSpace(activeRow, activeColumn) != 0)
				{
					activeRow++;
					if (activeRow == 6)
					{
						_dir = NONE;
						break;
					}
				}
				break;

			default:
				break;
		}

		/*Animation: chaque 10 millisecondes, le jeton se déplace de 10 pixels vers le bas jusqu'à-ce qu'il rencontre le bas de la grille(lowBound), ajusté selon la rangée active.*/
		time = clock.getElapsedTime();

		if (time.asMilliseconds() >= 10) 
		{
			if (_dir == DOWN)
			{
				token.getCircle().move(0, 10);

				if (token.getCircle().getPosition().y >= (lowBound - 1.5 * TOKENSIZE - 5) - (activeRow * (TOKENSIZE + verticalBorder)))
				{
					token.getCircle().setPosition(token.getCircle().getPosition().x, (lowBound - 1.5 * TOKENSIZE - 5) - (activeRow * (TOKENSIZE + verticalBorder)));

					playSound(collisionSound, buffer);

					tokens.push_back(token);
					grid.changeSpace(activeRow, activeColumn, _playerTurn);
					if (_playerTurn == 1)
					{	
						token.getCircle().setFillColor(Color::Red);
						_playerTurn = 2;
					}
					else
					{
						token.getCircle().setFillColor(Color::Blue);
						_playerTurn = 1;
					}

					_dir = NONE;
					token.resetPos();
					activeColumn = 3;
					activeRow = 0;

					//validateur
					if (validateGame(1, grid))
					{
						_gameOver = true;
						winner = 1;
						winText.setString("Player 1 wins!");
					}
					else if (validateGame(2, grid))
					{
						_gameOver = true;
						winner = 2;
						winText.setString("Player 2 wins!");
					}

					compteur++;

					if (compteur == 42)
					{
						_gameOver = true;
						winner = 0;
						winText.setString("Draw!");
					}
				}
			}

			window.clear(Color::Black);

			window.draw(background);

			token.draw(window);

			for (int i = 0; i < tokens.size(); i++)
			{
				tokens[i].draw(window);
			}

			window.draw(grid.getRectangle());

			if (_gameOver)
			{
				winText.setPosition((window.getSize().x - winText.getGlobalBounds().width) / 2, window.getSize().y / 2 - winText.getCharacterSize());
				window.draw(winText);
			}	

			window.display();

			if (_gameOver)
				sleep(seconds(3));

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

bool Game::validateGame(int joueur, Grid& grid)
{
	int compteur = 0;
	int x = 0;
	int y = 0;

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
				return true;
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
				return true;
			}
		}
	}

	for (int i = 0; i < 6; i++)
	{
		for (int j = 0; j < 7; j++)
		{
			compteur = 0;
			int x = i;
			int y = j;

			while (x < 6 && y < 7)
			{
				if (grid.getSpace(x, y) == joueur)
				{
					compteur++;
				}
				else
				{
					compteur = 0;
				}

				if (compteur == 4)
				{
					return true;
				}

				x++;
				y++;
			}
		}
	}

	for (int i = 0; i < 6; i++)
	{
		for (int j = 0; j < 7; j++)
		{
			compteur = 0;
			int x = i;
			int y = j;

			while (x >= 0 && x < 6 && y < 7)
			{
				if (grid.getSpace(x, y) == joueur)
				{
					compteur++;
				}
				else
				{
					compteur = 0;
				}

				if (compteur == 4)
				{
					return true;
				}

				x--;
				y++;
			}
		}
	}

	return false;
}

void Game::playSound(Sound &sound, SoundBuffer &buffer)
{
	sound.setBuffer(buffer); // On applique la musique chargée à l’objet de type "Sound"
	sound.play(); // On fait jouer la musique
}
