#include <SFML/Graphics.hpp>
#include "Button.h"

using namespace sf;
using namespace std;

Button::Button(const char* name, sf::Vector2f size, sf::Vector2f pos, sf::Color color)
{
	_active = false;
	_color = color;
	Color highlight(30, 30, 30, 0);
	_highlightColor = color + highlight;

	_rectangle.setSize(size);
	_rectangle.setOrigin(size.x / 2, size.y / 2);
	_rectangle.setPosition(pos);
	_rectangle.setFillColor(_color);

	if (!_font.loadFromFile("angelina.ttf"))
		exit(1);

	_text.setFont(_font);
	_text.setString(name);
	_text.setCharacterSize(_rectangle.getSize().y / 1.5f);
	_text.setFillColor(Color::White);
	_text.setOrigin(_text.getGlobalBounds().width / 2.0f, _text.getCharacterSize() / 1.3f);
	_text.setPosition(_rectangle.getPosition().x, _rectangle.getPosition().y);
}

sf::RectangleShape& Button::getRectangle()
{
	return _rectangle;
}

bool Button::getActive() const
{
	return _active;
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
	if (_rectangle.getGlobalBounds().contains(mousePosF))
	{
		_active = true;
		return true;
	}

	_active = false;
	return false;
}

void Button::draw(sf::RenderWindow& window) const
{
	window.draw(_rectangle);
	window.draw(_text);
}
