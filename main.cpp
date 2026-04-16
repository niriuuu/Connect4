#include <SFML/Graphics.hpp>

using namespace sf; // Namespace pour les objets de la librairie SFML
using namespace std; // Namespace pour les objets de la librairie standard en C++

int main() {
	RenderWindow window(VideoMode(800, 600), "My window");

	RectangleShape background;
	Color backgroundColor(Uint8(35), Uint8(75), Uint8(20), Uint8(255));

	RectangleShape grid;

	CircleShape token;
	int tokenSize = 64;

	

	window.setFramerateLimit(60);
	
	background.setSize(Vector2f(800, 600));
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
		}
		window.clear(Color::Black);

		Texture textureGrid;

		if (!textureGrid.loadFromFile("Grid.png")) {
			exit(1); // Si incapable de charger, on quitte avec un code d’erreur
		}

		grid.setTexture(&textureGrid); // Applique la texture à l’élément souhaité

		window.draw(background);
		window.draw(grid);
		window.draw(token);

		window.display();
	}

	return 0;
}