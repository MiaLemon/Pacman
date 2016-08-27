#include "stdafx.h"
#include "Pickup.h"


Pickup::Pickup()
{
}

Pickup::Pickup(sf::Texture * texture, sf::IntRect textureBounds, sf::Vector2f position, int pointsIn)
{
	sprite.setTexture(*texture);
	sprite.setTextureRect(textureBounds);
	sprite.setScale(2, 2);
	sprite.setPosition(position);

	points = pointsIn;
}

Pickup::~Pickup()
{
}

void Pickup::Draw(sf::RenderWindow & window)
{
	window.draw(sprite);
}

int Pickup::PickupPoints()
{
	return points;
}

bool Pickup::Intersects(sf::Rect<float> rect)
{
	return sprite.getGlobalBounds().intersects(rect);
}
