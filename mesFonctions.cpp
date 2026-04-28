#include <SFML/Graphics.hpp>
#include "mesFonctions.h"

using namespace sf;
using namespace std;

void showStats(sf::RenderWindow& window)
{
	RectangleShape background;
	Color backgroundColor(Uint8(35), Uint8(75), Uint8(20), Uint8(255));

	Text text;
	Font font;

	string content;

	content = string("a") + "b";

	if (!font.loadFromFile("angelina.ttf"))
		exit(1);
	text.setFont(font);
	text.setString(content);
	text.setCharacterSize(30);
	text.setFillColor(Color::White);

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
			default:
				break;
			}

			window.clear(Color::Black);

			window.draw(background);
			window.draw(text);

			window.display();
		}
	}
}

void showSettings(sf::RenderWindow& window)
{
	RectangleShape background;
	Color backgroundColor(Uint8(35), Uint8(75), Uint8(20), Uint8(255));

	Text text;
	Font font;

	string content;

	content = string("a") + "b";

	if (!font.loadFromFile("angelina.ttf"))
		exit(1);
	text.setFont(font);
	text.setString(content);
	text.setCharacterSize(30);
	text.setFillColor(Color::White);

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
			default:
				break;
			}

			window.clear(Color::Black);

			window.draw(background);
			window.draw(text);

			window.display();
		}
	}
}