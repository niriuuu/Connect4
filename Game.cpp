#include <SFML/Graphics.hpp>
#include "Game.h"
#include "Grid.h"
#include "Token.h"

using namespace sf;
using namespace std;

Game::Game()
{
	_gameOver = false;
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

	CircleShape token;
	int tokenSize = 60;

	//int dir = 0;

	const enum Directions { NONE, LEFT, RIGHT, DOWN };
	Directions dir = NONE;

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

	token.setRadius(tokenSize / 2);
	token.setPosition(Vector2f(400 - 30, 30));
	token.setFillColor(Color::Blue);
	token.setOutlineColor(Color::Black);
	token.setOutlineThickness(2);

	while (window.isOpen())
	{
		Event event;
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
							dir = LEFT;
							break;
						}
						case Keyboard::Right:
						{
							dir = RIGHT;
							break;
						}
						case Keyboard::Down:
						{
							dir = DOWN;
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

		if (dir == LEFT)
		{
			token.move(-66, 0);
			dir = NONE;
		}
		else if (dir == RIGHT)
		{
			token.move(66, 0);
			dir = NONE;
		}

		time = clock.getElapsedTime();

		if (time.asMilliseconds() >= 10)
		{
			if (dir == DOWN)
			{
				token.move(0, 10);
			}

			window.clear(Color::Black);

			window.draw(background);
			window.draw(token);
			window.draw(grid);

			window.display();

			clock.restart();
		}
	}

    return false;
}
