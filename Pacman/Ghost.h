#pragma once

#include <SFML/Graphics.hpp>
#include <iostream>

#include "Animation.h"
#include "AnimatedSprite.h"

class Ghost
{
public:
	Ghost(sf::Texture & texture);
	~Ghost();

	void Draw(sf::RenderWindow & window);
	void Update(bool collided, sf::Time frameTime);

private:
	AnimatedSprite sprite;
	sf::Vector2f direction;
	float speed;

	Animation walkingAnimationRight;
	Animation walkingAnimationLeft;
	Animation walkingAnimationUp;
	Animation walkingAnimationDown;
	Animation* currentAnimation;
};

