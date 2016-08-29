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
	sf::Texture * texture;

	int LEVELSIZE;
	Tile * pTiles;

	int PICKUPSSIZE;
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

	int AddPickUpsToPath2(int x, int y, int pickupIndex, sf::Texture * texture);
	int AddPickUpsToPath1(int x, int y, int pickupIndex, sf::Texture * texture);

	int AddPickUpsToCorner1(int x, int y, int pickupIndex, sf::Texture * texture);
	int AddPickUpsToCorner2(int x, int y, int pickupIndex, sf::Texture * texture);
	int AddPickUpsToCorner3(int x, int y, int pickupIndex, sf::Texture * texture);
	int AddPickUpsToCorner4(int x, int y, int pickupIndex, sf::Texture * texture);

	int AddPickUpsToThreeway1(int x, int y, int pickupIndex, sf::Texture * texture);
	int AddPickUpsToThreeway2(int x, int y, int pickupIndex, sf::Texture * texture);
	int AddPickUpsToThreeway3(int x, int y, int pickupIndex, sf::Texture * texture);
	int AddPickUpsToThreeway4(int x, int y, int pickupIndex, sf::Texture * texture);

	void CreateLevelTile(Tile::TileType tileType, int x, int y, int tileIndex);
	int CreatePickupsForTile(Tile::TileType tileType, int x, int y, int pickupIndex);

	void Split(const string &s, char delim, vector<string> &elems);
	vector<string> Split(const string &s, char delim);
};

