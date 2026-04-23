#include <SFML/Graphics.hpp>
#include "Button.h"

using namespace sf;
using namespace std;

Button::Button(const char* name, sf::Vector2f size, sf::Vector2f pos, sf::Color color)
{
	_color = color;
	Color highlight(30, 30, 30, 0);
	_highlightColor = color + highlight;

	_rectangle.setSize(size);
	_rectangle.setPosition(pos);
	_rectangle.setFillColor(_color);

	if (!_font.loadFromFile("angelina.ttf"))
		exit(1);
	_text.setFont(_font);
	_text.setString(name);
	_text.setCharacterSize(_rectangle.getSize().y / 1.5);
	_text.setFillColor(Color::White);
	_text.setPosition(_rectangle.getPosition().x + (_rectangle.getSize().x - _text.getGlobalBounds().width) / 2, _rectangle.getPosition().y + (_rectangle.getGlobalBounds().height / _text.getCharacterSize()));
}

sf::RectangleShape& Button::getRectangle()
{
	return _rectangle;
}



void Button::highlight()
{
	_rectangle.setFillColor(_highlightColor);
}

void Button::resetColor()
{
	_rectangle.setFillColor(_color);
}

bool Button::isHovered(Vector2f mousePosF)
{
	if(_rectangle.getGlobalBounds().contains(mousePosF))
		return true;
	return false;
}

void Button::draw(sf::RenderWindow& window) const
{
	window.draw(_rectangle);
	window.draw(_text);
}
