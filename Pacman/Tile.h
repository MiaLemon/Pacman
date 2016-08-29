#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>

class Tile
{
public:
	enum TileType
	{
		              //* * *
		Deadend1 = 0, //*   *
					  //*   *

					  //* * *
		Deadend2 = 1, //    *
					  //* * *

					  //*   *
		Deadend3 = 2, //*   *
					  //* * *

					  //* * *
		Deadend4 = 3, //*   
					  //* * *

					  //*   *
		Path1 = 4,    //*   *
					  //*   *

					  //* * *
		Path2 = 5,	  //
					  //* * *

					  //* * *
		Corner1 = 6,  //*  
					  //*

					  //* * *
		Corner2 = 7,  //    *
					  //    *

					  //    *
		Corner3 = 8,  //    *
					  //* * *

					  //*   
		Corner4 = 9,  //*   
					  //* * *

					  //* * *
		Threeway1 =10,//   
					  //

					  //    *
		Threeway2 =11,//    *
					  //    *

					  //
		Threeway3 =12,//   
					  //* * *

					  //*   
		Threeway4 =13,//*   
					  //*   

					  //
		Intercross =14//
					  //
	};

	Tile();
	Tile(sf::Vector2f position, sf::Texture & texture, TileType type);
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

