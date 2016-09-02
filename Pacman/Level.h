#pragma once
#include <SFML/Graphics.hpp>
#include "Tile.h"
#include <iostream>

#include "Pickup.h"
#include "AnimatedSprite.h"
#include "Tile.h"
#include "TextureManager.h"

#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <cstdint>

using namespace std;
class Level
{
public:
	Level(TextureManager & textureManager);
	~Level();

	void Draw(sf::RenderWindow & window);
	bool CheckCollision(AnimatedSprite object, sf::Vector2f direction);

	int CollectPickup(AnimatedSprite object);

	bool LevelCompleted();

private:
	int LEVELSIZE;
	int PICKUPSSIZE;
	vector<Tile> tiles;
	vector<Pickup> pickups;

	int pickupsPickedup;

	int AddPickUpsToPath2(sf::Texture & texture, float x, float y, int pickupIndex);
	int AddPickUpsToPath1(sf::Texture & texture, float x, float y, int pickupIndex);

	int AddPickUpsToCorner1(sf::Texture & texture, float x, float y, int pickupIndex);
	int AddPickUpsToCorner2(sf::Texture & texture, float x, float y, int pickupIndex);
	int AddPickUpsToCorner3(sf::Texture & texture, float x, float y, int pickupIndex);
	int AddPickUpsToCorner4(sf::Texture & texture, float x, float y, int pickupIndex);

	int AddPickUpsToThreeway1(sf::Texture & texture, float x, float y, int pickupIndex);
	int AddPickUpsToThreeway2(sf::Texture & texture, float x, float y, int pickupIndex);
	int AddPickUpsToThreeway3(sf::Texture & texture, float x, float y, int pickupIndex);
	int AddPickUpsToThreeway4(sf::Texture & texture, float x, float y, int pickupIndex);

	void CreateLevelTile(TextureManager & textureManager, Tile::TileType tileType, float x, float y, int tileIndex);
	int CreatePickupsForTile(sf::Texture & texture, Tile::TileType tileType, float x, float y, int pickupIndex);

	void Split(const string &s, char delim, vector<string> &elems);
	vector<string> Split(const string &s, char delim);
};

