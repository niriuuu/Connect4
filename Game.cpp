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

bool Game::play(RenderWindow& window)
{
	/*RenderWindow window(VideoMode(800, 600), "My window");*/

	RectangleShape background;
	Color backgroundColor(Uint8(35), Uint8(75), Uint8(20), Uint8(255));

	RectangleShape grid;

	Grid grid2;

	Token token(Color::Blue);

	Clock clock;
	Time time;

	Texture textureGrid;

	if (!textureGrid.loadFromFile("Grid.png")) {
		exit(1); // Si incapable de charger, on quitte avec un code d'erreur
	}

	grid.setTexture(&textureGrid); // Applique la texture reellement souhaitee

	background.setSize(Vector2f(800, 600));
	background.setFillColor(backgroundColor);

	grid.setSize(Vector2f(500, 500));
	grid2.inititaliserGrid(500, 500);
	grid.setPosition(Vector2f((window.getSize().x - grid.getSize().x) / 2, (window.getSize().y - grid.getSize().y) / 2)); //Positionne la grille au centre de la fenetre

	while (window.isOpen())
	{
		Event event;
		handleEvent(event, window);

		if (_dir == LEFT)
		{
			token.getCircle().move(-66, 0);
			_dir = NONE;
		}
		else if (_dir == RIGHT)
		{
			token.getCircle().move(66, 0);
			_dir = NONE;
		}

		time = clock.getElapsedTime();

		if (time.asMilliseconds() >= 10)
		{
			if (_dir == DOWN)
			{
				token.getCircle().move(0, 10);

				if (token.getCircle().getPosition().y == 470)
				{
					_dir = NONE;
					token.getCircle().setPosition(370, 30);

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
				}
			}

			window.clear(Color::Black);

			window.draw(background);
			window.draw(token.getCircle());
			window.draw(grid);

			window.display();

			clock.restart();
		}
	}

    return false;
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
				_dir = LEFT;
				break;
			}
			case Keyboard::Right:
			{
				_dir = RIGHT;
				break;
			}
			case Keyboard::Down:
			{
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
