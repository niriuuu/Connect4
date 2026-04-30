#include <SFML/Graphics.hpp>
#include <string>
#include <map>
#include <fstream>
#include "mesFonctions.h"
#include "Button.h"

using namespace sf;
using namespace std;

void showStats(RenderWindow& window, map<string, int>& stats)
{
	RectangleShape background;
	Color backgroundColor(Uint8(35), Uint8(75), Uint8(20), Uint8(255));

	Button exitButton("X", Vector2f(40, 40), Vector2f(10, 10), Color::Black);
	Button resetButton("Reset data", Vector2f(300, 75), Vector2f((window.getSize().x - 300) / 2, window.getSize().y - 130), Color::Black);

	Text text;
	Text title;
	Font font;

	string content;

	bool goBack = false;

	content = string("Games played: ") + "  " + to_string(stats["gamesPlayed"])
		+ "\n\nPlayer 1 wins: " + "  " + to_string(stats["p1Wins"])
		+ "\n\nPlayer 2 wins: " + " " + to_string(stats["p2Wins"])
		+"\n\nDraws: " + "           " + to_string(stats["draws"]);
	/*content = string("Games played:\t") + to_string(stats["gamesPlayed"])
		+ "\n\nPlayer 1 wins:\t" + to_string(stats["p1Wins"])
		+ "\n\nPlayer 2 wins:\t" + to_string(stats["p2Wins"])
		+ "\n\nDraws:\t\t\t" + to_string(stats["draws"]);*/

	if (!font.loadFromFile("angelina.ttf"))
		exit(1);
	text.setFont(font);
	text.setString(content);
	text.setCharacterSize(30);
	text.setFillColor(Color::White);
	text.setPosition((window.getSize().x - text.getGlobalBounds().width) / 2, (window.getSize().y - text.getGlobalBounds().height) / 2);

	title.setFont(font);
	title.setString("Stats");
	title.setCharacterSize(100);
	title.setFillColor(Color::White);
	title.setPosition((window.getSize().x - title.getGlobalBounds().width) / 2, 10);

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
				resetButton.draw(window);
				window.draw(title);
				window.draw(text);

				window.display();
		}
	}
}

void showInstructions(sf::RenderWindow& window)
{
	RectangleShape background;
	Color backgroundColor(Uint8(35), Uint8(75), Uint8(20), Uint8(255));

	Button exitButton("X", Vector2f(40, 40), Vector2f(10, 10), Color::Black);

	Text text;
	Font font;

	string content;

	bool goBack = false;

	Text title;

	content = string("The rules :\nPlayers take turns dropping one token at a time into the grid.\nThe token will slide down to the lowest available space in a column.\nThe goal is to be the first player to connect four of your tokens in a row :\n(Horizontally, vertically or Diagonally).\nThe first player to connect four tokens in a row wins the game.\nIf the grid is filled and no player has connected four, the game is a draw.\n\nControls :\n Use The Left and Right arrow keys to position your token\n Use the Down arrow keys to drop token down a column");
	if (!font.loadFromFile("angelina.ttf"))
		exit(1);
	text.setFont(font);
	text.setString(content);
	text.setCharacterSize(30);
	text.setFillColor(Color::White);
	text.setPosition((window.getSize().x - text.getGlobalBounds().width) / 2, (window.getSize().y - text.getGlobalBounds().height) / 2);

	if (!font.loadFromFile("angelina.ttf"))
		exit(1);
	title.setFont(font);
	title.setString("Instructions");
	title.setCharacterSize(100);
	title.setFillColor(Color::White);
	title.setPosition((window.getSize().x - title.getGlobalBounds().width) / 2, 10);

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
			window.draw(title);

			window.display();
		}
	}
}

void save(std::map<std::string, int>& stats)
{
	ofstream save("save.txt");

	if (!save)
	{
		exit(1);
	}

	save << stats["gamesPlayed"] << " " << stats["p1Wins"] << " " << stats["p2Wins"] << " " << stats["draws"];

	save.close();
}

void load(std::map<std::string, int>& stats)
{
	ifstream load("save.txt");

	int gamesPlayed = 0;
	int p1Wins = 0;
	int p2Wins = 0;
	int draws = 0;

	if (!save)
	{
		exit(1);
	}

	load >> gamesPlayed >> p1Wins >> p2Wins >> draws;

	stats["gamesPlayed"] = gamesPlayed;
	stats["p1Wins"] = p1Wins;
	stats["p2Wins"] = p2Wins;
	stats["draws"] = draws;

	load.close();
}
