#include <SFML/Graphics.hpp>
#include <vector>
#include "Grid.h"
#include "Game.h"

using namespace sf;
using namespace std;

int main() {
	RenderWindow window(VideoMode(800, 600), "My window");

	RectangleShape background;
	Color backgroundColor(Uint8(35), Uint8(75), Uint8(20), Uint8(255));
	
	Game game;

	window.setFramerateLimit(60);

	background.setSize(Vector2f(800, 600));
	background.setFillColor(backgroundColor);

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
						case Keyboard::Enter:
						{
							game.play(window);
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

		window.clear(Color::Black);

		window.draw(background);

		window.display();
	}

	return 0;
}