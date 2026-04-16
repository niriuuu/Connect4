#include <SFML/Graphics.hpp>

using namespace sf;
using namespace std;

int main() {
	RenderWindow window(VideoMode(800, 600), "My window");

	RectangleShape background;
	Color backgroundColor(Uint8(35), Uint8(75), Uint8(20), Uint8(255));

	RectangleShape grid;

	CircleShape token;
	int tokenSize = 64;

	int dir = 0;

	Clock clock;
	Time time;

	Texture textureGrid;

	if (!textureGrid.loadFromFile("Grid.png")) {
		exit(1); // Si incapable de charger, on quitte avec un code d�erreur
	}

	grid.setTexture(&textureGrid); // Applique la texture � l��l�ment souhait�

	window.setFramerateLimit(60);
	
	background.setSize(Vector2f(800, 700));
	background.setFillColor(backgroundColor);

	grid.setSize(Vector2f(tokenSize * 7, tokenSize * 6));
	grid.setPosition(Vector2f((window.getSize().x - grid.getSize().x) / 2, (window.getSize().y - grid.getSize().y) / 2)); //Positionne la grille au centre de la fenetre

	token.setRadius(tokenSize / 2);
	token.setPosition(Vector2f(400 - 32, 32));
	token.setFillColor(Color::Blue);
	token.setOutlineColor(Color::Black);
	token.setOutlineThickness(2);

	while (window.isOpen())
	{
		Event event;
		while (window.pollEvent(event))
		{
			if (event.type == Event::Closed)
				window.close();
			else if (event.type == Event::KeyPressed)
			{
				if (Keyboard::isKeyPressed(Keyboard::Key::Left))
				{
					dir = 1;
				}
				else if (Keyboard::isKeyPressed(Keyboard::Key::Right))
				{
					dir = 2;
				}
				else if (Keyboard::isKeyPressed(Keyboard::Key::Down))
				{
					dir = 3;
				}
			}
		}

		if (dir == 1)
		{
			token.move(-64, 0);
			dir = 0;
		}
		else if (dir == 2)
		{
			token.move(64, 0);
			dir = 0;
		}

		time = clock.getElapsedTime();

		if (time.asMilliseconds() >= 50)
		{
			if (dir == 3)
			{
				token.move(0, 10);
			}

			window.clear(Color::Black);

			window.draw(background);
			window.draw(grid);
			window.draw(token);

			window.display();

			clock.restart();
		}
	}

	return 0;
}