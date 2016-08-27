#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>

class Tile
{
public:
	enum TileType
	{
		Deadend1,
		Deadend2,
		Deadend3,
		Deadend4,
		Path1,
		Path2,
		Corner1,
		Corner2,
		Corner3,
		Corner4,
		Threeway1,
		Threeway2,
		Threeway3,
		Threeway4,
		Intercross
	};

	Tile();
	Tile(sf::Vector2f position, sf::Texture * texture, TileType type);
	~Tile();

	void Draw(sf::RenderWindow & window);
	bool Intersects(sf::Rect<float> rect);
	bool CanTraverse(sf::Vector2f direction, sf::Vector2f position);

private:
	sf::Sprite sprite;
	sf::Rect<float> rect;
	int top;
	int bottom;
	int left;
	int right;

	void SetTileType(TileType type);
};

