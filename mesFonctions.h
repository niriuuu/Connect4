#pragma once

void showStats(sf::RenderWindow& window, std::map<std::string, int>& stats);

void resetStats(std::map<std::string, int>& stats);

void setText(sf::Text& text, sf::Font& font, std::string content, int charSize, sf::Color color, sf::Vector2f pos);

void updateContent(std::string& content, std::map<std::string, int>& stats);

void showInstructions(sf::RenderWindow& window);

void save(std::map<std::string, int>& stats);

void load(std::map<std::string, int>& stats);
