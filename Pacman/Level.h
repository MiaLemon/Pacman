#pragma once
#include <SFML/Graphics.hpp>
#include "Tile.h"
#include <iostream>

#include "Pickup.h"
#include "AnimatedSprite.h"

class Level
{
public:
	Level();
	~Level();

	void Draw(sf::RenderWindow & window);
	bool CheckCollision(AnimatedSprite object, sf::Vector2f direction);

private:
	const static int LEVELSIZE = 110;
	Tile tiles[LEVELSIZE];

	const static int PICKUPSSIZE = 6;
	Pickup pickups[PICKUPSSIZE];
};

