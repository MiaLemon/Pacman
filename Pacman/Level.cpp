#include "stdafx.h"
#include "Level.h"


Level::Level()
{
	texture = new sf::Texture();
	if (!texture->loadFromFile("Textures/spriteAtlas.png"))
	{
		std::cout << "Failed to load player spritesheet!" << std::endl;
	}

	sf::Texture * deadend1 = new sf::Texture();
	if (!deadend1->loadFromFile("Textures/Deadend1.png"))
		std::cout << "Failed to load" << "Deadend1.png";

	sf::Texture * deadend2 = new sf::Texture();
	if (!deadend2->loadFromFile("Textures/Deadend2.png"))
		std::cout << "Failed to load" << "Deadend2.png";

	sf::Texture * deadend3 = new sf::Texture();
	if (!deadend3->loadFromFile("Textures/Deadend3.png"))
		std::cout << "Failed to load" << "Deadend3.png";

	sf::Texture * deadend4 = new sf::Texture();
	if (!deadend4->loadFromFile("Textures/Deadend4.png"))
		std::cout << "Failed to load" << "Deadend4.png";

	sf::Texture * corner1 = new sf::Texture();
	if (!corner1->loadFromFile("Textures/Corner1.png"))
		std::cout << "Failed to load" << "Corner1.png";

	sf::Texture * corner2 = new sf::Texture();
	if (!corner2->loadFromFile("Textures/Corner2.png"))
		std::cout << "Failed to load" << "Corner2.png";

	sf::Texture * corner3 = new sf::Texture();
	if (!corner3->loadFromFile("Textures/Corner3.png"))
		std::cout << "Failed to load" << "Corner3.png";

	sf::Texture * corner4 = new sf::Texture();
	if (!corner4->loadFromFile("Textures/Corner4.png"))
		std::cout << "Failed to load" << "Corner4.png";

	sf::Texture * path1 = new sf::Texture();
	if (!path1->loadFromFile("Textures/Path1.png"))
		std::cout << "Failed to load" << "Path1.png";

	sf::Texture * path2 = new sf::Texture();
	if (!path2->loadFromFile("Textures/Path2.png"))
		std::cout << "Failed to load" << "Path2.png";

	sf::Texture * threeway1 = new sf::Texture();
	if (!threeway1->loadFromFile("Textures/Threeway1.png"))
		std::cout << "Failed to load" << "Threeway1.png";

	sf::Texture * threeway2 = new sf::Texture();
	if (!threeway2->loadFromFile("Textures/Threeway2.png"))
		std::cout << "Failed to load" << "Threeway2.png";

	sf::Texture * threeway3 = new sf::Texture();
	if (!threeway3->loadFromFile("Textures/Threeway3.png"))
		std::cout << "Failed to load" << "Threeway3.png";

	sf::Texture * threeway4 = new sf::Texture();
	if (!threeway4->loadFromFile("Textures/Threeway4.png"))
		std::cout << "Failed to load" << "Threeway4.png";

	sf::Texture * intercross = new sf::Texture();
	if (!intercross->loadFromFile("Textures/Intercross.png"))
		std::cout << "Failed to load" << "Intercross.png";

	int pickupIndex = 0;
	int * pPickupIndex = &pickupIndex;

	float x = 0, y = 0;
	tiles[0] = Tile(sf::Vector2f(x, y), corner1, Tile::TileType::Corner1);
	AddPickUpsToCorner1(x, y, pPickupIndex, texture);
	y += 64;
	tiles[1] = Tile(sf::Vector2f(x, y), path1, Tile::TileType::Path1);
	AddPickUpsToPath1(x, y, pPickupIndex, texture);
	y += 64;
	tiles[2] = Tile(sf::Vector2f(x, y), threeway4, Tile::TileType::Threeway4);
	y += 64;
	tiles[3] = Tile(sf::Vector2f(x, y), corner4, Tile::TileType::Corner4);
	AddPickUpsToCorner4(x, y, pPickupIndex, texture);
	y += 64;
	tiles[4] = Tile(sf::Vector2f(x, y), deadend4, Tile::TileType::Deadend4);
	y += 64;
	tiles[5] = Tile(sf::Vector2f(x, y), deadend4, Tile::TileType::Deadend4);
	y += 64;
	tiles[6] = Tile(sf::Vector2f(x, y), deadend4, Tile::TileType::Deadend4);
	y += 64;
	tiles[7] = Tile(sf::Vector2f(x, y), corner1, Tile::TileType::Corner1);
	AddPickUpsToCorner1(x, y, pPickupIndex, texture);
	y += 64;
	tiles[8] = Tile(sf::Vector2f(x, y), corner4, Tile::TileType::Corner4);
	AddPickUpsToCorner4(x, y, pPickupIndex, texture);
	y += 64;
	tiles[9] = Tile(sf::Vector2f(x, y), corner1, Tile::TileType::Corner1);
	AddPickUpsToCorner1(x, y, pPickupIndex, texture);
	y += 64;
	tiles[10] = Tile(sf::Vector2f(x, y), corner4, Tile::TileType::Corner4);
	AddPickUpsToCorner4(x, y, pPickupIndex, texture);

	x += 64;
	y = 0;
	tiles[11] = Tile(sf::Vector2f(x, y), path2, Tile::TileType::Path2);
	AddPickUpsToPath2(x, y, pPickupIndex, texture);

	y += 64;
	tiles[12] = Tile(sf::Vector2f(x, y), intercross, Tile::TileType::Intercross);
	y += 64;
	tiles[13] = Tile(sf::Vector2f(x, y), path2, Tile::TileType::Path2);
	AddPickUpsToPath2(x, y, pPickupIndex, texture);

	y += 64;
	tiles[14] = Tile(sf::Vector2f(x, y), path2, Tile::TileType::Path2);
	AddPickUpsToPath2(x, y, pPickupIndex, texture);

	y += 64;
	tiles[15] = Tile(sf::Vector2f(x, y), deadend2, Tile::TileType::Deadend2);
	y += 64;
	tiles[16] = Tile(sf::Vector2f(x, y), path2, Tile::TileType::Path2);
	AddPickUpsToPath2(x, y, pPickupIndex, texture);

	y += 64;
	tiles[17] = Tile(sf::Vector2f(x, y), deadend2, Tile::TileType::Deadend2);
	y += 64;
	tiles[18] = Tile(sf::Vector2f(x, y), path2, Tile::TileType::Path2);
	AddPickUpsToPath2(x, y, pPickupIndex, texture);

	y += 64;
	tiles[19] = Tile(sf::Vector2f(x, y), corner2, Tile::TileType::Corner2);
	AddPickUpsToCorner2(x, y, pPickupIndex, texture);
	y += 64;
	tiles[20] = Tile(sf::Vector2f(x, y), threeway3, Tile::TileType::Threeway3);
	y += 64;
	tiles[21] = Tile(sf::Vector2f(x, y), path2, Tile::TileType::Path2);
	AddPickUpsToPath2(x, y, pPickupIndex, texture);

	x += 64;
	y = 0;
	tiles[22] = Tile(sf::Vector2f(x, y), threeway1, Tile::TileType::Threeway1);
	y += 64;
	tiles[23] = Tile(sf::Vector2f(x, y), path1, Tile::TileType::Path1);
	AddPickUpsToPath1(x, y, pPickupIndex, texture);
	y += 64;
	tiles[24] = Tile(sf::Vector2f(x, y), intercross, Tile::TileType::Intercross);
	y += 64;
	tiles[25] = Tile(sf::Vector2f(x, y), threeway2, Tile::TileType::Threeway2);
	y += 64;
	tiles[26] = Tile(sf::Vector2f(x, y), path1, Tile::TileType::Path1);
	AddPickUpsToPath1(x, y, pPickupIndex, texture);
	y += 64;
	tiles[27] = Tile(sf::Vector2f(x, y), intercross, Tile::TileType::Intercross);
	y += 64;
	tiles[28] = Tile(sf::Vector2f(x, y), path1, Tile::TileType::Path1);
	y += 64;
	tiles[29] = Tile(sf::Vector2f(x, y), intercross, Tile::TileType::Intercross);
	y += 64;
	tiles[30] = Tile(sf::Vector2f(x, y), threeway4, Tile::TileType::Threeway4);
	y += 64;
	tiles[31] = Tile(sf::Vector2f(x, y), corner3, Tile::TileType::Corner3);
	AddPickUpsToCorner3(x, y, pPickupIndex, texture);
	y += 64;
	tiles[32] = Tile(sf::Vector2f(x, y), path2, Tile::TileType::Path2);
	AddPickUpsToPath2(x, y, pPickupIndex, texture);

	x += 64;
	y = 0;
	tiles[33] = Tile(sf::Vector2f(x, y), path2, Tile::TileType::Path2);
	AddPickUpsToPath2(x, y, pPickupIndex, texture);

	y += 64;
	tiles[34] = Tile(sf::Vector2f(x, y), intercross, Tile::TileType::Intercross);
	y += 64;
	tiles[35] = Tile(sf::Vector2f(x, y), threeway1, Tile::TileType::Threeway1);
	y += 64;
	tiles[36] = Tile(sf::Vector2f(x, y), corner4, Tile::TileType::Corner4);
	AddPickUpsToCorner4(x, y, pPickupIndex, texture);
	y += 64;
	tiles[37] = Tile(sf::Vector2f(x, y), corner1, Tile::TileType::Corner1);
	AddPickUpsToCorner1(x, y, pPickupIndex, texture);
	y += 64;
	tiles[38] = Tile(sf::Vector2f(x, y), threeway2, Tile::TileType::Threeway2);
	y += 64;
	tiles[39] = Tile(sf::Vector2f(x, y), threeway4, Tile::TileType::Threeway4);
	y += 64;
	tiles[40] = Tile(sf::Vector2f(x, y), threeway3, Tile::TileType::Threeway3);
	y += 64;
	tiles[41] = Tile(sf::Vector2f(x, y), threeway1, Tile::TileType::Threeway1);
	y += 64;
	tiles[42] = Tile(sf::Vector2f(x, y), corner4, Tile::TileType::Corner4);
	AddPickUpsToCorner4(x, y, pPickupIndex, texture);
	y += 64;
	tiles[43] = Tile(sf::Vector2f(x, y), path2, Tile::TileType::Path2);
	AddPickUpsToPath2(x, y, pPickupIndex, texture);

	x += 64;
	y = 0;
	tiles[44] = Tile(sf::Vector2f(x, y), corner2, Tile::TileType::Corner2);
	AddPickUpsToCorner2(x, y, pPickupIndex, texture);
	y += 64;
	tiles[45] = Tile(sf::Vector2f(x, y), path1, Tile::TileType::Path1);
	AddPickUpsToPath1(x, y, pPickupIndex, texture);
	y += 64;
	tiles[46] = Tile(sf::Vector2f(x, y), threeway3, Tile::TileType::Threeway3);
	y += 64;
	tiles[47] = Tile(sf::Vector2f(x, y), corner2, Tile::TileType::Corner2);
	AddPickUpsToCorner2(x, y, pPickupIndex, texture);
	y += 64;
	tiles[48] = Tile(sf::Vector2f(x, y), corner3, Tile::TileType::Corner3);
	AddPickUpsToCorner3(x, y, pPickupIndex, texture);
	y += 64;
	tiles[49] = Tile(sf::Vector2f(x, y), deadend4, Tile::TileType::Deadend4);
	y += 64;
	tiles[50] = Tile(sf::Vector2f(x, y), path2, Tile::TileType::Path2);
	AddPickUpsToPath2(x, y, pPickupIndex, texture);

	y += 64;
	tiles[51] = Tile(sf::Vector2f(x, y), corner2, Tile::TileType::Corner2);
	AddPickUpsToCorner2(x, y, pPickupIndex, texture);
	y += 64;
	tiles[52] = Tile(sf::Vector2f(x, y), threeway3, Tile::TileType::Threeway3);
	y += 64;
	tiles[53] = Tile(sf::Vector2f(x, y), corner2, Tile::TileType::Corner2);
	AddPickUpsToCorner2(x, y, pPickupIndex, texture);
	y += 64;
	tiles[54] = Tile(sf::Vector2f(x, y), threeway3, Tile::TileType::Threeway3);

	x += 64;
	y = 0;
	tiles[55] = Tile(sf::Vector2f(x, y), corner1, Tile::TileType::Corner1);
	AddPickUpsToCorner1(x, y, pPickupIndex, texture);
	y += 64;
	tiles[56] = Tile(sf::Vector2f(x, y), path1, Tile::TileType::Path1);
	AddPickUpsToPath1(x, y, pPickupIndex, texture);
	y += 64;
	tiles[57] = Tile(sf::Vector2f(x, y), threeway3, Tile::TileType::Threeway3);
	y += 64;
	tiles[58] = Tile(sf::Vector2f(x, y), corner1, Tile::TileType::Corner1);
	AddPickUpsToCorner1(x, y, pPickupIndex, texture);
	y += 64;
	tiles[59] = Tile(sf::Vector2f(x, y), corner4, Tile::TileType::Corner4);
	AddPickUpsToCorner4(x, y, pPickupIndex, texture);
	y += 64;
	tiles[60] = Tile(sf::Vector2f(x, y), deadend2, Tile::TileType::Deadend2);
	y += 64;
	tiles[61] = Tile(sf::Vector2f(x, y), path2, Tile::TileType::Path2);
	AddPickUpsToPath2(x, y, pPickupIndex, texture);

	y += 64;
	tiles[62] = Tile(sf::Vector2f(x, y), corner1, Tile::TileType::Corner1);
	AddPickUpsToCorner1(x, y, pPickupIndex, texture);
	y += 64;
	tiles[63] = Tile(sf::Vector2f(x, y), threeway3, Tile::TileType::Threeway3);
	y += 64;
	tiles[64] = Tile(sf::Vector2f(x, y), corner1, Tile::TileType::Corner1);
	AddPickUpsToCorner1(x, y, pPickupIndex, texture);
	y += 64;
	tiles[65] = Tile(sf::Vector2f(x, y), threeway3, Tile::TileType::Threeway3);

	x += 64;
	y = 0;
	tiles[66] = Tile(sf::Vector2f(x, y), path2, Tile::TileType::Path2);
	AddPickUpsToPath2(x, y, pPickupIndex, texture);

	y += 64;
	tiles[67] = Tile(sf::Vector2f(x, y), intercross, Tile::TileType::Intercross);
	y += 64;
	tiles[68] = Tile(sf::Vector2f(x, y), threeway1, Tile::TileType::Threeway1);
	y += 64;
	tiles[69] = Tile(sf::Vector2f(x, y), corner3, Tile::TileType::Corner3);
	AddPickUpsToCorner3(x, y, pPickupIndex, texture);
	y += 64;
	tiles[70] = Tile(sf::Vector2f(x, y), corner2, Tile::TileType::Corner2);
	AddPickUpsToCorner2(x, y, pPickupIndex, texture);
	y += 64;
	tiles[71] = Tile(sf::Vector2f(x, y), threeway4, Tile::TileType::Threeway4);
	y += 64;
	tiles[72] = Tile(sf::Vector2f(x, y), threeway2, Tile::TileType::Threeway2);
	y += 64;
	tiles[73] = Tile(sf::Vector2f(x, y), threeway3, Tile::TileType::Threeway3);
	y += 64;
	tiles[74] = Tile(sf::Vector2f(x, y), threeway1, Tile::TileType::Threeway1);
	y += 64;
	tiles[75] = Tile(sf::Vector2f(x, y), corner3, Tile::TileType::Corner3);
	AddPickUpsToCorner3(x, y, pPickupIndex, texture);
	y += 64;
	tiles[76] = Tile(sf::Vector2f(x, y), path2, Tile::TileType::Path2);
	AddPickUpsToPath2(x, y, pPickupIndex, texture);

	x += 64;
	y = 0;
	tiles[77] = Tile(sf::Vector2f(x, y), threeway1, Tile::TileType::Threeway1);
	y += 64;
	tiles[78] = Tile(sf::Vector2f(x, y), path1, Tile::TileType::Path1);
	AddPickUpsToPath1(x, y, pPickupIndex, texture);
	y += 64;
	tiles[79] = Tile(sf::Vector2f(x, y), intercross, Tile::TileType::Intercross);
	y += 64;
	tiles[80] = Tile(sf::Vector2f(x, y), threeway4, Tile::TileType::Threeway4);
	y += 64;
	tiles[81] = Tile(sf::Vector2f(x, y), path1, Tile::TileType::Path1);
	AddPickUpsToPath1(x, y, pPickupIndex, texture);
	y += 64;
	tiles[82] = Tile(sf::Vector2f(x, y), intercross, Tile::TileType::Intercross);
	y += 64;
	tiles[83] = Tile(sf::Vector2f(x, y), path1, Tile::TileType::Path1);
	y += 64;
	tiles[84] = Tile(sf::Vector2f(x, y), intercross, Tile::TileType::Intercross);
	y += 64;
	tiles[85] = Tile(sf::Vector2f(x, y), threeway2, Tile::TileType::Threeway2);
	y += 64;
	tiles[86] = Tile(sf::Vector2f(x, y), corner4, Tile::TileType::Corner4);
	AddPickUpsToCorner4(x, y, pPickupIndex, texture);
	y += 64;
	tiles[87] = Tile(sf::Vector2f(x, y), path2, Tile::TileType::Path2);
	AddPickUpsToPath2(x, y, pPickupIndex, texture);

	x += 64;
	y = 0;
	tiles[88] = Tile(sf::Vector2f(x, y), path2, Tile::TileType::Path2);
	AddPickUpsToPath2(x, y, pPickupIndex, texture);

	y += 64;
	tiles[89] = Tile(sf::Vector2f(x, y), intercross, Tile::TileType::Intercross);
	y += 64;
	tiles[90] = Tile(sf::Vector2f(x, y), path2, Tile::TileType::Path2);
	AddPickUpsToPath2(x, y, pPickupIndex, texture);

	y += 64;
	tiles[91] = Tile(sf::Vector2f(x, y), path2, Tile::TileType::Path2);
	AddPickUpsToPath2(x, y, pPickupIndex, texture);

	y += 64;
	tiles[92] = Tile(sf::Vector2f(x, y), deadend4, Tile::TileType::Deadend4);
	y += 64;
	tiles[93] = Tile(sf::Vector2f(x, y), path2, Tile::TileType::Path2);
	AddPickUpsToPath2(x, y, pPickupIndex, texture);

	y += 64;
	tiles[94] = Tile(sf::Vector2f(x, y), deadend4, Tile::TileType::Deadend4);
	y += 64;
	tiles[95] = Tile(sf::Vector2f(x, y), path2, Tile::TileType::Path2);
	AddPickUpsToPath2(x, y, pPickupIndex, texture);

	y += 64;
	tiles[96] = Tile(sf::Vector2f(x, y), corner1, Tile::TileType::Corner1);
	AddPickUpsToCorner1(x, y, pPickupIndex, texture);
	y += 64;
	tiles[97] = Tile(sf::Vector2f(x, y), threeway3, Tile::TileType::Threeway3);
	y += 64;
	tiles[98] = Tile(sf::Vector2f(x, y), path2, Tile::TileType::Path2);
	AddPickUpsToPath2(x, y, pPickupIndex, texture);

	x += 64;
	y = 0;
	tiles[99] = Tile(sf::Vector2f(x, y), corner2, Tile::TileType::Corner2);
	AddPickUpsToCorner2(x, y, pPickupIndex, texture);
	y += 64;
	tiles[100] = Tile(sf::Vector2f(x, y), path1, Tile::TileType::Path1);
	AddPickUpsToPath1(x, y, pPickupIndex, texture);
	y += 64;
	tiles[101] = Tile(sf::Vector2f(x, y), threeway2, Tile::TileType::Threeway2);
	y += 64;
	tiles[102] = Tile(sf::Vector2f(x, y), corner3, Tile::TileType::Corner3);
	AddPickUpsToCorner3(x, y, pPickupIndex, texture);
	y += 64;
	tiles[103] = Tile(sf::Vector2f(x, y), deadend2, Tile::TileType::Deadend2);
	y += 64;
	tiles[104] = Tile(sf::Vector2f(x, y), deadend2, Tile::TileType::Deadend2);
	y += 64;
	tiles[105] = Tile(sf::Vector2f(x, y), deadend2, Tile::TileType::Deadend2);
	y += 64;
	tiles[106] = Tile(sf::Vector2f(x, y), corner2, Tile::TileType::Corner2);
	AddPickUpsToCorner2(x, y, pPickupIndex, texture);
	y += 64;
	tiles[107] = Tile(sf::Vector2f(x, y), corner3, Tile::TileType::Corner3);
	AddPickUpsToCorner3(x, y, pPickupIndex, texture);
	y += 64;
	tiles[108] = Tile(sf::Vector2f(x, y), corner2, Tile::TileType::Corner2);
	AddPickUpsToCorner2(x, y, pPickupIndex, texture);
	y += 64;
	tiles[109] = Tile(sf::Vector2f(x, y), corner3, Tile::TileType::Corner3);
	AddPickUpsToCorner3(x, y, pPickupIndex, texture);
}


Level::~Level()
{
}

void Level::Draw(sf::RenderWindow & window)
{
	for (int i = 0; i < LEVELSIZE; i++)
	{
		tiles[i].Draw(window);
	}

	for (int i = 0; i < PICKUPSSIZE; i++)
	{
		pickups[i].Draw(window);
	}
}

bool Level::CheckCollision(AnimatedSprite object, sf::Vector2f direction)
{
	//find tile
	for (int i = 0; i < LEVELSIZE; i++)
	{
		if (tiles[i].Intersects(object.getGlobalBounds()) &&
			!tiles[i].CanTraverse(direction, object.getPosition()))
		{
			return true;
		}
	}

	return false;
}

int Level::CollectPickup(AnimatedSprite object)
{
	for (int i = 0; i < PICKUPSSIZE; i++)
	{
		if (pickups[i].Intersects(object.getGlobalBounds()) && !pickups[i].IsPickedUp())
		{
			int points = pickups[i].PickupPoints();
			pickups[i].PickupPickup();

			return points;
		}
	}

	return 0;
}

void Level::AddPickUpsToPath2(int x, int y, int * pickupIndex, sf::Texture * texture)
{
	//* * *
	//
	//* * *
	pickups[*pickupIndex] = Pickup(texture, sf::IntRect(387, 196, 12, 12), sf::Vector2f(x, y + 20), 10);
	(*pickupIndex)++;
	pickups[*pickupIndex] = Pickup(texture, sf::IntRect(387, 196, 12, 12), sf::Vector2f(x + 21, y + 20), 10);
	(*pickupIndex)++;
	pickups[*pickupIndex] = Pickup(texture, sf::IntRect(387, 196, 12, 12), sf::Vector2f(x + 42, y + 20), 10);
	(*pickupIndex)++;
}

void Level::AddPickUpsToPath1(int x, int y, int * pickupIndex, sf::Texture * texture)
{
	//*  *
	//*  *
	//*  *
	pickups[*pickupIndex] = Pickup(texture, sf::IntRect(387, 196, 12, 12), sf::Vector2f(x + 20, y), 10);
	(*pickupIndex)++;
	pickups[*pickupIndex] = Pickup(texture, sf::IntRect(387, 196, 12, 12), sf::Vector2f(x + 20, y + 21), 10);
	(*pickupIndex)++;
	pickups[*pickupIndex] = Pickup(texture, sf::IntRect(387, 196, 12, 12), sf::Vector2f(x + 20, y + 42), 10);
	(*pickupIndex)++;
}

void Level::AddPickUpsToCorner1(int x, int y, int * pickupIndex, sf::Texture * texture)
{
	//* * *
	//*
	//*
	pickups[*pickupIndex] = Pickup(texture, sf::IntRect(387, 196, 12, 12), sf::Vector2f(x + 42, y + 20), 10);
	(*pickupIndex)++;
	pickups[*pickupIndex] = Pickup(texture, sf::IntRect(387, 196, 12, 12), sf::Vector2f(x + 20, y + 20), 10);
	(*pickupIndex)++;
	pickups[*pickupIndex] = Pickup(texture, sf::IntRect(387, 196, 12, 12), sf::Vector2f(x + 20, y + 42), 10);
	(*pickupIndex)++;
}

void Level::AddPickUpsToCorner2(int x, int y, int * pickupIndex, sf::Texture * texture)
{
	//* * *
	//    *
	//    *
	pickups[*pickupIndex] = Pickup(texture, sf::IntRect(387, 196, 12, 12), sf::Vector2f(x, y + 20), 10);
	(*pickupIndex)++;
	pickups[*pickupIndex] = Pickup(texture, sf::IntRect(387, 196, 12, 12), sf::Vector2f(x + 20, y + 20), 10);
	(*pickupIndex)++;
	pickups[*pickupIndex] = Pickup(texture, sf::IntRect(387, 196, 12, 12), sf::Vector2f(x + 20, y + 42), 10);
	(*pickupIndex)++;
}

void Level::AddPickUpsToCorner3(int x, int y, int * pickupIndex, sf::Texture * texture)
{
	//    *
	//    *
	//* * *
	pickups[*pickupIndex] = Pickup(texture, sf::IntRect(387, 196, 12, 12), sf::Vector2f(x + 21, y), 10);
	(*pickupIndex)++;
	pickups[*pickupIndex] = Pickup(texture, sf::IntRect(387, 196, 12, 12), sf::Vector2f(x + 20, y + 20), 10);
	(*pickupIndex)++;
	pickups[*pickupIndex] = Pickup(texture, sf::IntRect(387, 196, 12, 12), sf::Vector2f(x, y + 20), 10);
	(*pickupIndex)++;
}

void Level::AddPickUpsToCorner4(int x, int y, int * pickupIndex, sf::Texture * texture)
{
	//*
	//*
	//* * *
	pickups[*pickupIndex] = Pickup(texture, sf::IntRect(387, 196, 12, 12), sf::Vector2f(x + 20, y), 10);
	(*pickupIndex)++;
	pickups[*pickupIndex] = Pickup(texture, sf::IntRect(387, 196, 12, 12), sf::Vector2f(x + 20, y + 20), 10);
	(*pickupIndex)++;
	pickups[*pickupIndex] = Pickup(texture, sf::IntRect(387, 196, 12, 12), sf::Vector2f(x + 42, y + 20), 10);
	(*pickupIndex)++;
}

void Level::AddPickUpsToThreeway1(int x, int y, int * pickupIndex, sf::Texture * texture)
{
}

void Level::AddPickUpsToThreeway2(int x, int y, int * pickupIndex, sf::Texture * texture)
{
}

void Level::AddPickUpsToThreeway3(int x, int y, int * pickupIndex, sf::Texture * texture)
{
}

void Level::AddPickUpsToThreeway4(int x, int y, int * pickupIndex, sf::Texture * texture)
{
}
