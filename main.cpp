#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <vector>
#include "Grid.h"
#include "Game.h"
#include "Button.h"
#include "mesFonctions.h"

using namespace sf;
using namespace std;

int main() {
	RenderWindow window(VideoMode(800, 600), "My window");

	RectangleShape background;
	Color backgroundColor(Uint8(35), Uint8(75), Uint8(20), Uint8(255));

	Text title;
	Font font;

	Button button1("Play", Vector2f(300, 75), Vector2f((800 - 300) / 2, 175), Color::Black);
	Button button2("Stats", Vector2f(300, 75), Vector2f((800 - 300) / 2, 275), Color::Black);
	Button button3("Settings", Vector2f(300, 75), Vector2f((800 - 300) / 2, 375), Color::Black);
	Button button4("Quit", Vector2f(300, 75), Vector2f((800 - 300) / 2, 475), Color::Black);
	
	Game game;

	/*int gamesPlayed = 0;
	int p1Wins = 0;
	int p2Wins = 0;
	int draws = 0;*/

	map<string, int> stats;
	stats.emplace("gamesPlayed", 0);
	stats.emplace("p1Wins", 0);
	stats.emplace("p2Wins", 0);
	stats.emplace("draws", 0);

	window.setFramerateLimit(60);

	background.setSize(Vector2f(800, 600));
	background.setFillColor(backgroundColor);

	if (!font.loadFromFile("angelina.ttf"))
		exit(1);
	title.setFont(font);
	title.setString("CONNECT 4");
	title.setCharacterSize(100);
	title.setFillColor(Color::White);
	title.setPosition((window.getSize().x - title.getGlobalBounds().width) / 2, 10);

	SoundBuffer collisionSoundBuffer;

	if (!collisionSoundBuffer.loadFromFile("ressources/collisionSound.wav")) // On charge la musique du jeu
		exit(1);

	SoundBuffer mainMusicBuffer;
	Sound mainMusic;

	if (!mainMusicBuffer.loadFromFile("ressources/mainMusic.wav"))
		return 1;

	mainMusic.setBuffer(mainMusicBuffer); // On applique la musique charg�e � l�objet de type "Sound"
	mainMusic.setLoop(true); // La musique jouera en boucle
	mainMusic.play(); // On fait jouer la musique

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
							game.play(window, collisionSoundBuffer);
							break;
						}
						default:
							break;
					}
					break;
				}
				case Event::MouseMoved:
				{
					Vector2i mousePos = Mouse::getPosition(window);
					sf::Vector2f mousePosF(static_cast<float>(mousePos.x), static_cast<float>(mousePos.y));
					if (button1.isHovered(mousePosF))
					{
						button1.highlight();
					}
					else if (button2.isHovered(mousePosF))
					{
						button2.highlight();
					}
					else if (button3.isHovered(mousePosF))
					{
						button3.highlight();
					}
					else if (button4.isHovered(mousePosF))
					{
						button4.highlight();
					}
					else
					{
						button1.resetColor();
						button2.resetColor();
						button3.resetColor();
						button4.resetColor();
					}
					break;
				}
				case Event::MouseButtonPressed:
				{
					if (button1.getActive())
					{
						switch (game.play(window, collisionSoundBuffer))
						{
						case 0:
							stats["draws"]++;
							break;
						case 1:
							stats["p1Wins"]++;
							break;
						case 2:
							stats["p2Wins"]++;
							break;
						default:
							break;
						}
						;
					}
					else if (button2.getActive())
					{
						showStats(window, stats);
					}
					else if (button3.getActive())
					{
						showSettings(window);
					}
					else if (button4.getActive())
					{
						exit(0);
					}
					break;
				}
				default:
					break;
			}
		}

		window.clear(Color::Black);

		window.draw(background);
		window.draw(title);
		button1.draw(window);
		button2.draw(window);
		button3.draw(window);
		button4.draw(window);

		window.display();
	}

	return 0;
}