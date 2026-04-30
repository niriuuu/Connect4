#pragma once

void showStats(sf::RenderWindow& window, std::map<std::string, int>& stats);

void showInstructions(sf::RenderWindow& window);

void save(std::map<std::string, int>& stats);

void load(std::map<std::string, int>& stats);