#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <vector>
#include "Grid.h"
#include "Game.h"
#include "Button.h"
#include "mesFonctions.h"
#include "constants.h"

using namespace sf;
using namespace std;

int main() {
	RenderWindow window(VideoMode(WINDOWWIDTH, WINDOWHEIGHT), "Connect 4");

	RectangleShape background;
	Color backgroundColor(Uint8(35), Uint8(75), Uint8(20), Uint8(255));

	Text title;
	Font font;

	const Vector2f buttonSize(300, 75);

	Button button1("Play", buttonSize, Vector2f((WINDOWWIDTH - buttonSize.x) / 2, 175), Color::Black);
	Button button2("Stats", buttonSize, Vector2f((WINDOWWIDTH - buttonSize.x) / 2, 275), Color::Black);
	Button button3("Instructions", buttonSize, Vector2f((WINDOWWIDTH - buttonSize.x) / 2, 375), Color::Black);
	Button button4("Quit", buttonSize, Vector2f((WINDOWWIDTH - buttonSize.x) / 2, 475), Color::Black);
	
	Game game;

	map<string, int> stats = { {"gamesPlayed", 0}, {"p1Wins", 0}, {"p2Wins", 0}, {"draws", 0} };

	load(stats);

	window.setFramerateLimit(60);

	background.setSize(Vector2f(WINDOWWIDTH, WINDOWHEIGHT));
	background.setFillColor(backgroundColor);

	if (!font.loadFromFile("angelina.ttf"))
		exit(1);
	title.setFont(font);
	title.setString("CONNECT 4");
	title.setCharacterSize(100);
	title.setFillColor(Color::White);
	title.setPosition((WINDOWWIDTH - title.getGlobalBounds().width) / 2, 10);

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
					save(stats);
					window.close();
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
						stats["gamesPlayed"]++;
					}
					else if (button2.getActive())
					{
						showStats(window, stats);
					}
					else if (button3.getActive())
					{
						showInstructions(window);
					}
					else if (button4.getActive())
					{
						save(stats);
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