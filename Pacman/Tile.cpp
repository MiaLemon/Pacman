#include "stdafx.h"
#include "Tile.h"


Tile::Tile()
{
}

Tile::Tile(sf::Vector2f position, sf::Texture * texture, TileType type)
{
	sprite.setTexture(*texture);
	sprite.setScale(2, 2);
	sprite.setPosition(position);

	SetTileType(type);
}

Tile::~Tile()
{
}

void Tile::Draw(sf::RenderWindow & window)
{
	window.draw(sprite);
}

bool Tile::Intersects(sf::Rect<float> rect)
{
	return rect.intersects(sprite.getGlobalBounds());
}

bool Tile::CanTraverse(sf::Vector2f direction, sf::Vector2f position)
{
	sf::Rect<float> rectTile = sprite.getGlobalBounds();
	if (direction.x == 1 && right == 1 && position.x > rectTile.left + 28)//going right
		return false;
	else if (direction.x == -1 && left == 1 && position.x < rectTile.left + 28)//going left
		return false;
	else if (direction.y == -1 && top == 1 && position.y < rectTile.top + 28) //going up
		return false;
	else if (direction.y == 1 && bottom == 1 && position.y > rectTile.top + 28) //going down
		return false;
	else
		return true;
}

void Tile::SetTileType(TileType type)
{
	switch (type)
	{
	case Deadend1:
		top = 1;
		bottom = 0;
		left = 1;
		right = 1;
		break;
	case Deadend2:
		top = 1;
		bottom = 1;
		left = 0;
		right = 1;
		break;
	case Deadend3:
		top = 0;
		bottom = 1;
		left = 1;
		right = 1;
		break;
	case Deadend4:
		top = 1;
		bottom = 1;
		left = 1;
		right = 0;
		break;
	case Path1:
		top = 0;
		bottom = 0;
		left = 1;
		right = 1;
		break;
	case Path2:
		top = 1;
		bottom = 1;
		left = 0;
		right = 0;
		break;
	case Corner1:
		top = 1;
		bottom = 0;
		left = 1;
		right = 0;
		break;
	case Corner2:
		top = 1;
		bottom = 0;
		left = 0;
		right = 1;
		break;
	case Corner3:
		top = 0;
		bottom = 1;
		left = 0;
		right = 1;
		break;
	case Corner4:
		top = 0;
		bottom = 1;
		left = 1;
		right = 0;
		break;
	case Threeway1:
		top = 1;
		bottom = 0;
		left = 0;
		right = 0;
		break;
	case Threeway2:
		top = 0;
		bottom = 0;
		left = 0;
		right = 1;
		break;
	case Threeway3:
		top = 0;
		bottom = 1;
		left = 0;
		right = 0;
		break;
	case Threeway4:
		top = 0;
		bottom = 0;
		left = 1;
		right = 0;
		break;
	case Intercross:
		top = 0;
		bottom = 0;
		left = 0;
		right = 0;
		break;
	default:
		break;
	}
}
