#pragma once

#include <iostream>
#include <SFML/Graphics.hpp>

class HUD
{
public:
	HUD();
	~HUD();

	void Draw(sf::RenderWindow & window);
	void Update(int points);

private:
	sf::Font font;

	sf::Text textPoints;
};

