#include "stdafx.h"
#include "Level.h"


Level::Level(TextureManager & textureManager)
{
	pickupsPickedup = 0;

	sf::Texture & texture = textureManager.GetLevelTexture("Textures/spriteAtlas.png");	

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

	tiles.resize(LEVELSIZE);
	pickups.resize(PICKUPSSIZE);

	int pickupIndex = 0;
	int tileIndex = 0;

	float yStartValue = 50;
	float xStartValue = 50;
	float x = xStartValue, y = yStartValue;

	while (getline(infile, line))
	{
		vector<string> rowElements = Split(line, ':');

		for (int i = 0; i < width; i++)
		{
			int tileTypeIndex;
			istringstream(rowElements[i]) >> tileTypeIndex;
			Tile::TileType type = static_cast<Tile::TileType>(tileTypeIndex);
			CreateLevelTile(textureManager, type, x, y, tileIndex);
			int pickupsCreated = CreatePickupsForTile(texture, type, x, y, pickupIndex);
			pickupIndex += pickupsCreated;

			tileIndex++;
			x += 64;
		}
		x = xStartValue;
		y += 64;
	}
}


Level::~Level()
{
}

void Level::Draw(sf::RenderWindow & window)
{
	for (unsigned int i = 0; i < tiles.size(); i++)
	{
		tiles[i].Draw(window);
	}
	
	for (unsigned int i = 0; i < pickups.size(); i++)
	{
		pickups[i].Draw(window);
	}
}

bool Level::CheckCollision(AnimatedSprite object, sf::Vector2f direction)
{
	sf::Rect<float> rectObject = object.getGlobalBounds();
	sf::Vector2f rectPosition = object.getPosition();
	//find tile
	for (unsigned int i = 0; i < tiles.size(); i++)
	{
		if (tiles[i].Intersects(rectObject) &&
			!tiles[i].CanTraverse(direction, rectPosition))
			return true;
	}

	return false;
}

int Level::CollectPickup(AnimatedSprite object)
{
	sf::Rect<float> rectObject = object.getGlobalBounds();
	for (unsigned int i = 0; i < tiles.size(); i++)
	{
		if (pickups[i].Intersects(rectObject) && !pickups[i].IsPickedUp())
		{
			int points = pickups[i].PickupPoints();
			pickups[i].PickupPickup();
			pickupsPickedup++;

			return points;
		}
	}

	return 0;
}

bool Level::LevelCompleted()
{
	return pickupsPickedup == pickups.size();
}

int Level::AddPickUpsToPath2(sf::Texture & texture, float x, float y, int pickupIndex)
{
	//* * *
	//
	//* * *
	pickups[pickupIndex] = Pickup(texture, sf::IntRect(387, 196, 12, 12), sf::Vector2f(x, y + 20), 10);
	pickupIndex++;
	pickups[pickupIndex] = Pickup(texture, sf::IntRect(387, 196, 12, 12), sf::Vector2f(x + 21, y + 20), 10);
	pickupIndex++;
	pickups[pickupIndex] = Pickup(texture, sf::IntRect(387, 196, 12, 12), sf::Vector2f(x + 42, y + 20), 10);
	pickupIndex++;

	return 3;
}

int Level::AddPickUpsToPath1(sf::Texture & texture, float x, float y, int pickupIndex)
{
	//*  *
	//*  *
	//*  *
	pickups[pickupIndex] = Pickup(texture, sf::IntRect(387, 196, 12, 12), sf::Vector2f(x + 20, y), 10);
	pickupIndex++;
	pickups[pickupIndex] = Pickup(texture, sf::IntRect(387, 196, 12, 12), sf::Vector2f(x + 20, y + 21), 10);
	pickupIndex++;
	pickups[pickupIndex] = Pickup(texture, sf::IntRect(387, 196, 12, 12), sf::Vector2f(x + 20, y + 42), 10);
	pickupIndex++;

	return 3;
}

int Level::AddPickUpsToCorner1(sf::Texture & texture, float x, float y, int pickupIndex)
{
	//* * *
	//*
	//*
	pickups[pickupIndex] = Pickup(texture, sf::IntRect(387, 196, 12, 12), sf::Vector2f(x + 42, y + 20), 10);
	pickupIndex++;
	pickups[pickupIndex] = Pickup(texture, sf::IntRect(387, 196, 12, 12), sf::Vector2f(x + 20, y + 20), 10);
	pickupIndex++;
	pickups[pickupIndex] = Pickup(texture, sf::IntRect(387, 196, 12, 12), sf::Vector2f(x + 20, y + 42), 10);
	pickupIndex++;

	return 3;
}

int Level::AddPickUpsToCorner2(sf::Texture & texture, float x, float y, int pickupIndex)
{
	//* * *
	//    *
	//    *
	pickups[pickupIndex] = Pickup(texture, sf::IntRect(387, 196, 12, 12), sf::Vector2f(x, y + 20), 10);
	pickupIndex++;
	pickups[pickupIndex] = Pickup(texture, sf::IntRect(387, 196, 12, 12), sf::Vector2f(x + 20, y + 20), 10);
	pickupIndex++;
	pickups[pickupIndex] = Pickup(texture, sf::IntRect(387, 196, 12, 12), sf::Vector2f(x + 20, y + 42), 10);
	pickupIndex++;

	return 3;
}

int Level::AddPickUpsToCorner3(sf::Texture & texture, float x, float y, int pickupIndex)
{
	//    *
	//    *
	//* * *
	pickups[pickupIndex] = Pickup(texture, sf::IntRect(387, 196, 12, 12), sf::Vector2f(x + 21, y), 10);
	pickupIndex++;
	pickups[pickupIndex] = Pickup(texture, sf::IntRect(387, 196, 12, 12), sf::Vector2f(x + 20, y + 20), 10);
	pickupIndex++;
	pickups[pickupIndex] = Pickup(texture, sf::IntRect(387, 196, 12, 12), sf::Vector2f(x, y + 20), 10);
	pickupIndex++;

	return 3;
}

int Level::AddPickUpsToCorner4(sf::Texture & texture, float x, float y, int pickupIndex)
{
	//*
	//*
	//* * *
	pickups[pickupIndex] = Pickup(texture, sf::IntRect(387, 196, 12, 12), sf::Vector2f(x + 20, y), 10);
	pickupIndex++;
	pickups[pickupIndex] = Pickup(texture, sf::IntRect(387, 196, 12, 12), sf::Vector2f(x + 20, y + 20), 10);
	pickupIndex++;
	pickups[pickupIndex] = Pickup(texture, sf::IntRect(387, 196, 12, 12), sf::Vector2f(x + 42, y + 20), 10);
	pickupIndex++;

	return 3;
}

int Level::AddPickUpsToThreeway1(sf::Texture & texture, float x, float y, int pickupIndex)
{
	return 0;
}

int Level::AddPickUpsToThreeway2(sf::Texture & texture, float x, float y, int pickupIndex)
{
	return 0;
}

int Level::AddPickUpsToThreeway3(sf::Texture & texture, float x, float y, int pickupIndex)
{
	return 0;
}

int Level::AddPickUpsToThreeway4(sf::Texture & texture, float x, float y, int pickupIndex)
{
	return 0;
}

void Level::CreateLevelTile(TextureManager & textureManager, Tile::TileType tileType, float x, float y, int tileIndex)
{
	string path;
		switch (tileType)
		{
		case Tile::TileType::Deadend1:
			path = "Textures/Deadend1.png";
			break;
		case Tile::TileType::Deadend2:
			path = "Textures/Deadend2.png";
			break;
		case Tile::TileType::Deadend3:
			path = "Textures/Deadend3.png";
			break;
		case Tile::TileType::Deadend4:
			path = "Textures/Deadend4.png";
			break;
		case Tile::TileType::Path1:
			path = "Textures/Path1.png";
			break;
		case Tile::TileType::Path2:
			path = "Textures/Path2.png";
			break;
		case Tile::TileType::Corner1:
			path = "Textures/Corner1.png";
			break;
		case Tile::TileType::Corner2:
			path = "Textures/Corner2.png";
			break;
		case Tile::TileType::Corner3:
			path = "Textures/Corner3.png";
			break;
		case Tile::TileType::Corner4:
			path = "Textures/Corner4.png";
			break;
		case Tile::TileType::Threeway1:
			path = "Textures/Threeway1.png";
			break;
		case Tile::TileType::Threeway2:
			path = "Textures/Threeway2.png";
			break;
		case Tile::TileType::Threeway3:
			path = "Textures/Threeway3.png";
			break;
		case Tile::TileType::Threeway4:
			path = "Textures/Threeway4.png";
			break;
		case Tile::TileType::Intercross:
			path = "Textures/Intercross.png";
			break;
		default:
			break;
		}
		sf::Texture & texture = textureManager.GetLevelTexture(path);
		tiles[tileIndex] = Tile(sf::Vector2f(x, y), texture, tileType);
}

int Level::CreatePickupsForTile(sf::Texture & texture, Tile::TileType tileType, float x, float y, int pickupIndex)
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
		return AddPickUpsToPath1(texture, x, y, pickupIndex);
		break;
	case Tile::TileType::Path2:
		return AddPickUpsToPath2(texture, x, y, pickupIndex);
		break;
	case Tile::TileType::Corner1:
		return AddPickUpsToCorner1(texture, x, y, pickupIndex);
		break;
	case Tile::TileType::Corner2:
		return AddPickUpsToCorner2(texture, x, y, pickupIndex);
		break;
	case Tile::TileType::Corner3:
		return AddPickUpsToCorner3(texture, x, y, pickupIndex);
		break;
	case Tile::TileType::Corner4:
		return AddPickUpsToCorner4(texture, x, y, pickupIndex);
		break;
	case Tile::TileType::Threeway1:
		return AddPickUpsToThreeway1(texture, x, y, pickupIndex);
		break;
	case Tile::TileType::Threeway2:
		return AddPickUpsToThreeway2(texture, x, y, pickupIndex);
		break;
	case Tile::TileType::Threeway3:
		return AddPickUpsToThreeway3(texture, x, y, pickupIndex);
		break;
	case Tile::TileType::Threeway4:
		return AddPickUpsToThreeway4(texture, x, y, pickupIndex);
		break;
	case Tile::TileType::Intercross:
		//return AddPickUpsToIntercross(texture, x, y, pickupIndex);
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
