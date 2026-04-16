#include <SFML/Graphics.hpp>
#include "Game.h"

using namespace sf;
using namespace std;

int main() {
	RenderWindow window(VideoMode(800, 600), "My window");

	RectangleShape background;
	Color backgroundColor(Uint8(35), Uint8(75), Uint8(20), Uint8(255));

	window.setFramerateLimit(60);
	
	background.setSize(Vector2f(800, 700));
	background.setFillColor(backgroundColor);

	Game game;

	while (window.isOpen())
	{
		Event event;
		while (window.pollEvent(event))
		{
			if (event.type == Event::Closed)
				window.close();
			else if (event.type == Event::KeyPressed)
			{
				if (Keyboard::isKeyPressed(Keyboard::Key::Enter))
				{
					window.close();
					game.play();
				}
			}
		}

		window.clear(Color::Black);

		window.draw(background);

		window.display();
	}

	return 0;
}