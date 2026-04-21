#pragma once
class Token
{
private:
	sf::CircleShape _circle;
	sf::Vector2f _defaultPos;

public:
	Token(sf::Color color);
	~Token() = default;

	sf::CircleShape& getCircle();
	void resetPos();
};

