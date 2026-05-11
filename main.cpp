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
	sf::Texture _textureBackground;

	Text title;
	Font font;

	const Vector2f buttonSize(300, 75);

	Button button1("Play", buttonSize, Vector2f(WINDOWWIDTH / 2, 320), BUTTONCOLOR);
	Button button2("Stats", buttonSize, Vector2f(WINDOWWIDTH / 2, button1.getRectangle().getPosition().y + 1.5f * buttonSize.y), BUTTONCOLOR);
	Button button3("Rules", buttonSize, Vector2f(WINDOWWIDTH / 2, button2.getRectangle().getPosition().y + 1.5f * buttonSize.y), BUTTONCOLOR);
	Button button4("Quit", buttonSize, Vector2f(WINDOWWIDTH / 2, button3.getRectangle().getPosition().y + 1.5f * buttonSize.y), BUTTONCOLOR);
	
	Game game;

	SoundBuffer collisionSoundBuffer;
	SoundBuffer mainMusicBuffer;
	Sound mainMusic;

	map<string, int> stats = { {"gamesPlayed", 0}, {"p1Wins", 0}, {"p2Wins", 0}, {"draws", 0} };

	load(stats);

	window.setFramerateLimit(60);

	if (!_textureBackground.loadFromFile("ressources/Background.png")) {
		exit(1);
	}
	background.setSize(Vector2f(WINDOWWIDTH, WINDOWHEIGHT));
	background.setTexture(&_textureBackground);

	if (!font.loadFromFile("ressources/Margarine-Regular.ttf"))
		exit(1);
	setText(title, font, "CONNECT 4", 100, Color::White, Vector2f(WINDOWWIDTH / 2.0f, 120));

	if (!collisionSoundBuffer.loadFromFile("ressources/TokenSound.ogg"))
		exit(1);

	if (!mainMusicBuffer.loadFromFile("ressources/mainMusic.wav"))
		return 1;
	mainMusic.setBuffer(mainMusicBuffer);
	mainMusic.setLoop(true);
	mainMusic.play();

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