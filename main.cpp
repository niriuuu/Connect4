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

	RectangleShape button1;
	RectangleShape button2;
	RectangleShape button3;
	RectangleShape button4;
	
	Game game;

	window.setFramerateLimit(60);

	background.setSize(Vector2f(800, 600));
	background.setFillColor(backgroundColor);

	button1.setSize(Vector2f(300, 75));
	button1.setPosition(Vector2f((800-300)/2, 150));

	button2.setSize(Vector2f(300, 75));
	button2.setPosition(Vector2f((800 - 300) / 2, 250));

	button3.setSize(Vector2f(300, 75));
	button3.setPosition(Vector2f((800 - 300) / 2, 350));

	button4.setSize(Vector2f(300, 75));
	button4.setPosition(Vector2f((800 - 300) / 2, 450));

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
		window.draw(button1);
		window.draw(button2);
		window.draw(button3);
		window.draw(button4);

		window.display();
	}

	return 0;
}