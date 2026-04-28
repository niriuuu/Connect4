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

	Button button1("Play", Vector2f(300, 75), Vector2f((800 - 300) / 2, 150), Color::Black);
	Button button2("Stats", Vector2f(300, 75), Vector2f((800 - 300) / 2, 250), Color::Black);
	Button button3("Settings", Vector2f(300, 75), Vector2f((800 - 300) / 2, 350), Color::Black);
	Button button4("Quit", Vector2f(300, 75), Vector2f((800 - 300) / 2, 450), Color::Black);
	
	Game game;

	window.setFramerateLimit(60);

	background.setSize(Vector2f(800, 600));
	background.setFillColor(backgroundColor);

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
						game.play(window, collisionSoundBuffer);
					}
					else if (button2.getActive())
					{
						showStats(window);
					}
					else if (button3.getActive())
					{
						
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
		button1.draw(window);
		button2.draw(window);
		button3.draw(window);
		button4.draw(window);

		window.display();
	}

	return 0;
}