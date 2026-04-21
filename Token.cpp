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
}

CircleShape& Token::getCircle()
{
	return _circle;
}

void Token::resetPos()
{
	_circle.setPosition(_defaultPos);
}
