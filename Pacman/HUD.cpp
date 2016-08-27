#include "stdafx.h"
#include "HUD.h"
#include <sstream>


HUD::HUD()
{
	if (!font.loadFromFile("ARCADECLASSIC.ttf"))
	{
		std::cout << "ERROR loading font";
	}

	textPoints.setFont(font);
	textPoints.setString("Points  0");
	textPoints.setCharacterSize(24);
	//textPoints.setColor(sf::Color::White);
	//textPoints.setStyle(sf::Text::Bold | sf::Text::Underlined);
	textPoints.setPosition(sf::Vector2f(60, 20));
}

HUD::~HUD()
{
}

void HUD::Draw(sf::RenderWindow & window)
{
	window.draw(textPoints);
}

void HUD::Update(int points)
{
	std::string stringPoints = static_cast<std::ostringstream*>(&(std::ostringstream() << points))->str();
	textPoints.setString("Points  " + stringPoints);
}
