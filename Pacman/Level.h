#pragma once
#include <SFML/Graphics.hpp>
#include "Tile.h"
#include <iostream>

#include "Pickup.h"
#include "AnimatedSprite.h"
#include "Tile.h"

#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <cstdint>

using namespace std;
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
	int LEVELSIZE;
	int PICKUPSSIZE;
	vector<Tile> tiles;
	vector<Pickup> pickups;

	int pickupsPickedup;

	sf::Texture texture;
	sf::Texture deadend1;
	sf::Texture deadend2;
	sf::Texture deadend3;
	sf::Texture deadend4;
	sf::Texture corner1;
	sf::Texture corner2;
	sf::Texture corner3;
	sf::Texture corner4;
	sf::Texture path1;
	sf::Texture path2;
	sf::Texture threeway1;
	sf::Texture threeway2;
	sf::Texture threeway3;
	sf::Texture threeway4;
	sf::Texture intercross;

	int AddPickUpsToPath2(float x, float y, int pickupIndex);
	int AddPickUpsToPath1(float x, float y, int pickupIndex);

	int AddPickUpsToCorner1(float x, float y, int pickupIndex);
	int AddPickUpsToCorner2(float x, float y, int pickupIndex);
	int AddPickUpsToCorner3(float x, float y, int pickupIndex);
	int AddPickUpsToCorner4(float x, float y, int pickupIndex);

	int AddPickUpsToThreeway1(float x, float y, int pickupIndex);
	int AddPickUpsToThreeway2(float x, float y, int pickupIndex);
	int AddPickUpsToThreeway3(float x, float y, int pickupIndex);
	int AddPickUpsToThreeway4(float x, float y, int pickupIndex);

	void CreateLevelTile(Tile::TileType tileType, float x, float y, int tileIndex);
	int CreatePickupsForTile(Tile::TileType tileType, float x, float y, int pickupIndex);

	void Split(const string &s, char delim, vector<string> &elems);
	vector<string> Split(const string &s, char delim);
};

