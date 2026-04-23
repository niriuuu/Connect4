#include <SFML/Graphics.hpp>
#include "Token.h"

using namespace sf;
using namespace std;

Token::Token(Color color)
{
	_defaultPos.x = 370;
	_defaultPos.y = 30;

	_circle.setRadius(30);
	_circle.setPosition(_defaultPos);
	_circle.setFillColor(color);
	_circle.setOutlineColor(Color::Black);
	_circle.setOutlineThickness(2);

	if (!_textureToken.loadFromFile("Token.png")) {
		exit(1); // Si incapable de charger, on quitte avec un code d'erreur
	}

	_circle.setTexture(&_textureToken); // Applique la texture reellement souhaitee
}

CircleShape& Token::getCircle()
{
	return _circle;
}

void Token::resetPos()
{
	_circle.setPosition(_defaultPos);
}
