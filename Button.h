#pragma once
class Button
{
private:
	sf::RectangleShape _rectangle;
	sf::Font _font;
	sf::Text _text;

public:
	Button(const char* name, sf::Vector2f size, sf::Vector2f pos, sf::Color color);

	void draw(sf::RenderWindow& window) const;
};

