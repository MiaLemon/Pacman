#pragma once

#include <SFML/Graphics.hpp>
#include <iostream>

#include "Animation.h"
#include "AnimatedSprite.h"

class Character
{
public:
	Character(sf::Texture & texture);
	~Character();
	void Draw(sf::RenderWindow & window);
	void Update(bool collided, sf::Time frameTime);

	void ChangeDirectionUp();
	void ChangeDirectionDown();
	void ChangeDirectionRight();
	void ChangeDirectionLeft();

	AnimatedSprite GetSprite();
	sf::Vector2f GetDirection();

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

