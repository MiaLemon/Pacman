#include "stdafx.h"
#include "Level.h"


Level::Level()
{
	pickupsPickedup = 0;

	texture = new sf::Texture();
	if (!texture->loadFromFile("Textures/spriteAtlas.png"))
	{
		std::cout << "Failed to load player spritesheet!" << std::endl;
	}

	deadend1 = new sf::Texture();
	if (!deadend1->loadFromFile("Textures/Deadend1.png"))
		std::cout << "Failed to load" << "Deadend1.png";

	deadend2 = new sf::Texture();
	if (!deadend2->loadFromFile("Textures/Deadend2.png"))
		std::cout << "Failed to load" << "Deadend2.png";

	deadend3 = new sf::Texture();
	if (!deadend3->loadFromFile("Textures/Deadend3.png"))
		std::cout << "Failed to load" << "Deadend3.png";

	deadend4 = new sf::Texture();
	if (!deadend4->loadFromFile("Textures/Deadend4.png"))
		std::cout << "Failed to load" << "Deadend4.png";

	corner1 = new sf::Texture();
	if (!corner1->loadFromFile("Textures/Corner1.png"))
		std::cout << "Failed to load" << "Corner1.png";

	corner2 = new sf::Texture();
	if (!corner2->loadFromFile("Textures/Corner2.png"))
		std::cout << "Failed to load" << "Corner2.png";

	corner3 = new sf::Texture();
	if (!corner3->loadFromFile("Textures/Corner3.png"))
		std::cout << "Failed to load" << "Corner3.png";

	corner4 = new sf::Texture();
	if (!corner4->loadFromFile("Textures/Corner4.png"))
		std::cout << "Failed to load" << "Corner4.png";

	path1 = new sf::Texture();
	if (!path1->loadFromFile("Textures/Path1.png"))
		std::cout << "Failed to load" << "Path1.png";

	path2 = new sf::Texture();
	if (!path2->loadFromFile("Textures/Path2.png"))
		std::cout << "Failed to load" << "Path2.png";

	threeway1 = new sf::Texture();
	if (!threeway1->loadFromFile("Textures/Threeway1.png"))
		std::cout << "Failed to load" << "Threeway1.png";

	threeway2 = new sf::Texture();
	if (!threeway2->loadFromFile("Textures/Threeway2.png"))
		std::cout << "Failed to load" << "Threeway2.png";

	threeway3 = new sf::Texture();
	if (!threeway3->loadFromFile("Textures/Threeway3.png"))
		std::cout << "Failed to load" << "Threeway3.png";

	threeway4 = new sf::Texture();
	if (!threeway4->loadFromFile("Textures/Threeway4.png"))
		std::cout << "Failed to load" << "Threeway4.png";

	intercross = new sf::Texture();
	if (!intercross->loadFromFile("Textures/Intercross.png"))
		std::cout << "Failed to load" << "Intercross.png";

	//Read Level1.txt and extract size of tiles and size of pickups
	//go through the file and create the level
	std::ifstream infile("Level1.txt");
	string line;
	
	getline(infile, line); //size of level
	vector<string> size = Split(line, 'x');
	int width;
	istringstream(size[0]) >> width;
	int height;
	istringstream(size[1]) >> height;
	LEVELSIZE = width * height;

	getline(infile, line); //num of pickups
	istringstream(line) >> PICKUPSSIZE;

	pTiles = new Tile[LEVELSIZE];
	pPickups = new Pickup[PICKUPSSIZE];

	int pickupIndex = 0;
	int tileIndex = 0;

	int yStartValue = 50;
	int xStartValue = 50;
	int x = xStartValue, y = yStartValue;

	while (getline(infile, line))
	{
		vector<string> rowElements = Split(line, ':');

		for (int i = 0; i < width; i++)
		{
			int tileTypeIndex;
			istringstream(rowElements[i]) >> tileTypeIndex;
			Tile::TileType type = static_cast<Tile::TileType>(tileTypeIndex);
			CreateLevelTile(type, x, y, tileIndex);
			if (pickupIndex < PICKUPSSIZE)
			{
				int pickupsCreated = CreatePickupsForTile(type, x, y, pickupIndex);
				pickupIndex += pickupsCreated;
			}
			tileIndex++;
			x += 64;
		}
		x = xStartValue;
		y += 64;
	}
}


Level::~Level()
{
	texture->~Texture();
	deadend1->~Texture();
	deadend2->~Texture();
	deadend3->~Texture();
	deadend4->~Texture();
	corner1->~Texture();
	corner2->~Texture();
	corner3->~Texture();
	corner4->~Texture();
	path1->~Texture();
	path2->~Texture();
	threeway1->~Texture();
	threeway2->~Texture();
	threeway3->~Texture();
	threeway4->~Texture();
	intercross->~Texture();
}

void Level::Draw(sf::RenderWindow & window)
{
	for (int i = 0; i < LEVELSIZE; i++)
	{
		(*(pTiles + i)).Draw(window);
	}

	for (int i = 0; i < PICKUPSSIZE; i++)
	{
		(*(pPickups + i)).Draw(window);
	}
}

bool Level::CheckCollision(AnimatedSprite object, sf::Vector2f direction)
{
	sf::Rect<float> rectObject = object.getGlobalBounds();
	sf::Vector2f rectPosition = object.getPosition();
	//find tile
	for (int i = 0; i < LEVELSIZE; i++)
	{
		if ((*(pTiles + i)).Intersects(rectObject) &&
			!(*(pTiles + i)).CanTraverse(direction, rectPosition))
			return true;
	}

	return false;
}

int Level::CollectPickup(AnimatedSprite object)
{
	sf::Rect<float> rectObject = object.getGlobalBounds();
	for (int i = 0; i < PICKUPSSIZE; i++)
	{
		if ((*(pPickups + i)).Intersects(rectObject) && !(*(pPickups + i)).IsPickedUp())
		{
			int points = (*(pPickups + i)).PickupPoints();
			(*(pPickups + i)).PickupPickup();
			pickupsPickedup++;

			return points;
		}
	}

	return 0;
}

bool Level::LevelCompleted()
{
	return pickupsPickedup == PICKUPSSIZE;
}

int Level::AddPickUpsToPath2(int x, int y, int pickupIndex, sf::Texture * texture)
{
	//* * *
	//
	//* * *
	*(pPickups + pickupIndex) = Pickup(texture, sf::IntRect(387, 196, 12, 12), sf::Vector2f(x, y + 20), 10);
	pickupIndex++;
	*(pPickups + pickupIndex) = Pickup(texture, sf::IntRect(387, 196, 12, 12), sf::Vector2f(x + 21, y + 20), 10);
	pickupIndex++;
	*(pPickups + pickupIndex) = Pickup(texture, sf::IntRect(387, 196, 12, 12), sf::Vector2f(x + 42, y + 20), 10);
	pickupIndex++;

	return 3;
}

int Level::AddPickUpsToPath1(int x, int y, int pickupIndex, sf::Texture * texture)
{
	//*  *
	//*  *
	//*  *
	*(pPickups + pickupIndex) = Pickup(texture, sf::IntRect(387, 196, 12, 12), sf::Vector2f(x + 20, y), 10);
	pickupIndex++;
	*(pPickups + pickupIndex) = Pickup(texture, sf::IntRect(387, 196, 12, 12), sf::Vector2f(x + 20, y + 21), 10);
	pickupIndex++;
	*(pPickups + pickupIndex) = Pickup(texture, sf::IntRect(387, 196, 12, 12), sf::Vector2f(x + 20, y + 42), 10);
	pickupIndex++;

	return 3;
}

int Level::AddPickUpsToCorner1(int x, int y, int pickupIndex, sf::Texture * texture)
{
	//* * *
	//*
	//*
	*(pPickups + pickupIndex) = Pickup(texture, sf::IntRect(387, 196, 12, 12), sf::Vector2f(x + 42, y + 20), 10);
	pickupIndex++;
	*(pPickups + pickupIndex) = Pickup(texture, sf::IntRect(387, 196, 12, 12), sf::Vector2f(x + 20, y + 20), 10);
	pickupIndex++;
	*(pPickups + pickupIndex) = Pickup(texture, sf::IntRect(387, 196, 12, 12), sf::Vector2f(x + 20, y + 42), 10);
	pickupIndex++;

	return 3;
}

int Level::AddPickUpsToCorner2(int x, int y, int pickupIndex, sf::Texture * texture)
{
	//* * *
	//    *
	//    *
	*(pPickups + pickupIndex) = Pickup(texture, sf::IntRect(387, 196, 12, 12), sf::Vector2f(x, y + 20), 10);
	pickupIndex++;
	*(pPickups + pickupIndex) = Pickup(texture, sf::IntRect(387, 196, 12, 12), sf::Vector2f(x + 20, y + 20), 10);
	pickupIndex++;
	*(pPickups + pickupIndex) = Pickup(texture, sf::IntRect(387, 196, 12, 12), sf::Vector2f(x + 20, y + 42), 10);
	pickupIndex++;

	return 3;
}

int Level::AddPickUpsToCorner3(int x, int y, int pickupIndex, sf::Texture * texture)
{
	//    *
	//    *
	//* * *
	*(pPickups + pickupIndex) = Pickup(texture, sf::IntRect(387, 196, 12, 12), sf::Vector2f(x + 21, y), 10);
	pickupIndex++;
	*(pPickups + pickupIndex) = Pickup(texture, sf::IntRect(387, 196, 12, 12), sf::Vector2f(x + 20, y + 20), 10);
	pickupIndex++;
	*(pPickups + pickupIndex) = Pickup(texture, sf::IntRect(387, 196, 12, 12), sf::Vector2f(x, y + 20), 10);
	pickupIndex++;

	return 3;
}

int Level::AddPickUpsToCorner4(int x, int y, int pickupIndex, sf::Texture * texture)
{
	//*
	//*
	//* * *
	*(pPickups + pickupIndex) = Pickup(texture, sf::IntRect(387, 196, 12, 12), sf::Vector2f(x + 20, y), 10);
	pickupIndex++;
	*(pPickups + pickupIndex) = Pickup(texture, sf::IntRect(387, 196, 12, 12), sf::Vector2f(x + 20, y + 20), 10);
	pickupIndex++;
	*(pPickups + pickupIndex) = Pickup(texture, sf::IntRect(387, 196, 12, 12), sf::Vector2f(x + 42, y + 20), 10);
	pickupIndex++;

	return 3;
}

int Level::AddPickUpsToThreeway1(int x, int y, int pickupIndex, sf::Texture * texture)
{
	return 0;
}

int Level::AddPickUpsToThreeway2(int x, int y, int pickupIndex, sf::Texture * texture)
{
	return 0;
}

int Level::AddPickUpsToThreeway3(int x, int y, int pickupIndex, sf::Texture * texture)
{
	return 0;
}

int Level::AddPickUpsToThreeway4(int x, int y, int pickupIndex, sf::Texture * texture)
{
	return 0;
}

void Level::CreateLevelTile(Tile::TileType tileType, int x, int y, int tileIndex)
{
		switch (tileType)
		{
		case Tile::TileType::Deadend1:
			*(pTiles + tileIndex) = Tile(sf::Vector2f(x, y), deadend1, tileType);
			break;
		case Tile::TileType::Deadend2:
			*(pTiles + tileIndex) = Tile(sf::Vector2f(x, y), deadend2, tileType);
			break;
		case Tile::TileType::Deadend3:
			*(pTiles + tileIndex) = Tile(sf::Vector2f(x, y), deadend3, tileType);
			break;
		case Tile::TileType::Deadend4:
			*(pTiles + tileIndex) = Tile(sf::Vector2f(x, y), deadend4, tileType);
			break;
		case Tile::TileType::Path1:
			*(pTiles + tileIndex) = Tile(sf::Vector2f(x, y), path1, tileType);
			break;
		case Tile::TileType::Path2:
			*(pTiles + tileIndex) = Tile(sf::Vector2f(x, y), path2, tileType);
			break;
		case Tile::TileType::Corner1:
			*(pTiles + tileIndex) = Tile(sf::Vector2f(x, y), corner1, tileType);
			break;
		case Tile::TileType::Corner2:
			*(pTiles + tileIndex) = Tile(sf::Vector2f(x, y), corner2, tileType);
			break;
		case Tile::TileType::Corner3:
			*(pTiles + tileIndex) = Tile(sf::Vector2f(x, y), corner3, tileType);
			break;
		case Tile::TileType::Corner4:
			*(pTiles + tileIndex) = Tile(sf::Vector2f(x, y), corner4, tileType);
			break;
		case Tile::TileType::Threeway1:
			*(pTiles + tileIndex) = Tile(sf::Vector2f(x, y), threeway1, tileType);
			break;
		case Tile::TileType::Threeway2:
			*(pTiles + tileIndex) = Tile(sf::Vector2f(x, y), threeway2, tileType);
			break;
		case Tile::TileType::Threeway3:
			*(pTiles + tileIndex) = Tile(sf::Vector2f(x, y), threeway3, tileType);
			break;
		case Tile::TileType::Threeway4:
			*(pTiles + tileIndex) = Tile(sf::Vector2f(x, y), threeway4, tileType);
			break;
		case Tile::TileType::Intercross:
			*(pTiles + tileIndex) = Tile(sf::Vector2f(x, y), intercross, tileType);
			break;
		default:
			break;
		}
}

int Level::CreatePickupsForTile(Tile::TileType tileType, int x, int y, int pickupIndex)
{
	switch (tileType)
	{
	case Tile::TileType::Deadend1:
	case Tile::TileType::Deadend2:
	case Tile::TileType::Deadend3:
	case Tile::TileType::Deadend4:
		return 0;
		break;
	case Tile::TileType::Path1:
		return AddPickUpsToPath1(x, y, pickupIndex, texture);
		break;
	case Tile::TileType::Path2:
		return AddPickUpsToPath2(x, y, pickupIndex, texture);
		break;
	case Tile::TileType::Corner1:
		return AddPickUpsToCorner1(x, y, pickupIndex, texture);
		break;
	case Tile::TileType::Corner2:
		return AddPickUpsToCorner2(x, y, pickupIndex, texture);
		break;
	case Tile::TileType::Corner3:
		return AddPickUpsToCorner3(x, y, pickupIndex, texture);
		break;
	case Tile::TileType::Corner4:
		return AddPickUpsToCorner4(x, y, pickupIndex, texture);
		break;
	case Tile::TileType::Threeway1:
		return AddPickUpsToThreeway1(x, y, pickupIndex, texture);
		break;
	case Tile::TileType::Threeway2:
		return AddPickUpsToThreeway2(x, y, pickupIndex, texture);
		break;
	case Tile::TileType::Threeway3:
		return AddPickUpsToThreeway3(x, y, pickupIndex, texture);
		break;
	case Tile::TileType::Threeway4:
		return AddPickUpsToThreeway4(x, y, pickupIndex, texture);
		break;
	case Tile::TileType::Intercross:
		//return AddPickUpsToIntercross(*x, *y, pickupIndex, texture);
		return 0;
		break;
	default:
		return 0;
		break;
	}
}

void Level::Split(const string & s, char delim, vector<string>& elems)
{
	stringstream ss(s);
	string item;
	while (getline(ss, item, delim))
	{
		elems.push_back(item);
	}
}

vector<string> Level::Split(const string & s, char delim)
{
	vector<string> elems;
	Split(s, delim, elems);
	return elems;
}
