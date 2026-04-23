#pragma once
class Button
{
private:
	sf::RectangleShape _rectangle;
	sf::Font _font;
	sf::Text _text;
	sf::Color _color;
	sf::Color _highlightColor;

public:
	Button(const char* name, sf::Vector2f size, sf::Vector2f pos, sf::Color color);

	sf::RectangleShape& getRectangle();

	void highlight();

	void resetColor();

	bool isHovered(sf::Vector2f mousePosF);

	void draw(sf::RenderWindow& window) const;
};

