#pragma once
class Token
{
private:
	sf::CircleShape _circle;
	sf::Vector2f _defaultPos;
	sf::Texture _textureToken;

public:
	Token(sf::Color color);
	~Token() = default;

	sf::CircleShape& getCircle();
	void resetPos();
};

