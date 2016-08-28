#pragma once
#include <SFML/Graphics.hpp>
#include "Tile.h"
#include <iostream>

#include "Pickup.h"
#include "AnimatedSprite.h"
#include "Tile.h"

class Level
{
public:
	Level();
	~Level();

	void Draw(sf::RenderWindow & window);
	bool CheckCollision(AnimatedSprite object, sf::Vector2f direction);

	int CollectPickup(AnimatedSprite object);

	bool LevelCompleted();

private:
	sf::Texture * texture;

	const int LEVELSIZE = 110;
	Tile * pTiles;

	const int PICKUPSSIZE = 180;
	Pickup * pPickups;

	int pickupsPickedup;

	sf::Texture * deadend1;
	sf::Texture * deadend2;
	sf::Texture * deadend3;
	sf::Texture * deadend4;
	sf::Texture * corner1;
	sf::Texture * corner2;
	sf::Texture * corner3;
	sf::Texture * corner4;
	sf::Texture * path1;
	sf::Texture * path2;
	sf::Texture * threeway1;
	sf::Texture * threeway2;
	sf::Texture * threeway3;
	sf::Texture * threeway4;
	sf::Texture * intercross;

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

	void CreateLevelTile(Tile::TileType tile, int * x, int * y, int * tileIndex, int * pickupIndex);
};

