#include <SFML/Graphics.hpp>
#include <string>
#include <map>
#include "mesFonctions.h"
#include "Button.h"

using namespace sf;
using namespace std;

void showStats(RenderWindow& window, map<string, int>& stats)
{
	RectangleShape background;
	Color backgroundColor(Uint8(35), Uint8(75), Uint8(20), Uint8(255));

	Button exitButton("X", Vector2f(40, 40), Vector2f(10, 10), Color::Black);

	Text text;
	Font font;

	string content;

	/*int gamesPlayed = 0;
	int p1Wins = 0;
	int p2Wins = 0;
	int draws = 0;*/

	bool goBack = false;

	content = string("Games played: ") + to_string(stats["gamesPlayed"])
		+ "\nPlayer 1 wins: " + to_string(stats["p1Wins"])
		+ "\nPlayer 2 wins: " + to_string(stats["p2Wins"])
		+"\nDraws: " + to_string(stats["draws"]);

	if (!font.loadFromFile("angelina.ttf"))
		exit(1);
	text.setFont(font);
	text.setString(content);
	text.setCharacterSize(30);
	text.setFillColor(Color::White);
	text.setPosition((window.getSize().x - text.getGlobalBounds().width) / 2, (window.getSize().y - text.getGlobalBounds().height) / 2);

	background.setSize(Vector2f(800, 600));
	background.setFillColor(backgroundColor);

	while (window.isOpen() && !goBack)
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
				case Event::MouseMoved:
				{
					Vector2i mousePos = Mouse::getPosition(window);
					sf::Vector2f mousePosF(static_cast<float>(mousePos.x), static_cast<float>(mousePos.y));
					if (exitButton.isHovered(mousePosF))
					{
						exitButton.highlight();
					}
					else
					{
						exitButton.resetColor();
					}
					break;
				}
				case Event::MouseButtonPressed:
				{
					if (exitButton.getActive())
					{
						goBack = true;
					}
					break;
				}
				default:
					break;
				}

				window.clear(Color::Black);

				window.draw(background);
				exitButton.draw(window);
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