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

	int CollectPickup(AnimatedSprite object);

private:
	sf::Texture * texture;

	const static int LEVELSIZE = 110;
	Tile tiles[LEVELSIZE];

	const static int PICKUPSSIZE = 183;
	Pickup pickups[PICKUPSSIZE];

	void AddPickUpsToPath2(int x, int y, int * pickupIndex, sf::Texture * texture);
	void AddPickUpsToPath1(int x, int y, int * pickupIndex, sf::Texture * texture);

	void AddPickUpsToCorner1(int x, int y, int * pickupIndex, sf::Texture * texture);
	void AddPickUpsToCorner2(int x, int y, int * pickupIndex, sf::Texture * texture);
	void AddPickUpsToCorner3(int x, int y, int * pickupIndex, sf::Texture * texture);
	void AddPickUpsToCorner4(int x, int y, int * pickupIndex, sf::Texture * texture);

	void AddPickUpsToThreeway1(int x, int y, int * pickupIndex, sf::Texture * texture);
	void AddPickUpsToThreeway2(int x, int y, int * pickupIndex, sf::Texture * texture);
	void AddPickUpsToThreeway3(int x, int y, int * pickupIndex, sf::Texture * texture);
	void AddPickUpsToThreeway4(int x, int y, int * pickupIndex, sf::Texture * texture);
};

