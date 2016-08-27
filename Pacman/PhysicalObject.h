#pragma once
#include <SFML/Graphics.hpp>

class PhysicalObject
{
public:
	PhysicalObject(sf::Rect<float> rectIn);
	~PhysicalObject();

protected:
	sf::Rect<float> rect;
};

