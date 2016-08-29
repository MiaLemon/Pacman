#pragma once

#include <SFML/Graphics.hpp>

class Pickup
{
public:
	Pickup();
	Pickup(sf::Texture & texture, sf::IntRect textureBounds, sf::Vector2f position, int pointsIn);
	~Pickup();

	void Draw(sf::RenderWindow & window);

	int PickupPoints();
	bool Intersects(sf::Rect<float> rect);
	void PickupPickup();
	bool IsPickedUp();

private:
	sf::Sprite sprite;
	int points;
	bool isPickedUp = true;

	sf::Rect<float> rect;
};

