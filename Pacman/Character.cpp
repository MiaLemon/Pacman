#include "stdafx.h"
#include "Character.h"

Character::Character(sf::Texture & texture)
{
	direction = { 1, 0 };
	speed = 0.04f;

	// set up the animations for all four directions (set spritesheet and push frames)
	walkingAnimationRight.setSpriteSheet(texture);
	walkingAnimationRight.addFrame(sf::IntRect(799, 0, 43, 43));
	walkingAnimationRight.addFrame(sf::IntRect(799, 47, 43, 43));
	walkingAnimationRight.addFrame(sf::IntRect(799, 94, 43, 43));

	walkingAnimationDown.setSpriteSheet(texture);
	walkingAnimationDown.addFrame(sf::IntRect(799, 144, 43, 43));
	walkingAnimationDown.addFrame(sf::IntRect(799, 191, 43, 43));
	walkingAnimationDown.addFrame(sf::IntRect(799, 238, 43, 43));

	walkingAnimationLeft.setSpriteSheet(texture);
	walkingAnimationLeft.addFrame(sf::IntRect(799, 282, 43, 43));
	walkingAnimationLeft.addFrame(sf::IntRect(799, 329, 43, 43));
	walkingAnimationLeft.addFrame(sf::IntRect(799, 376, 43, 43));

	walkingAnimationUp.setSpriteSheet(texture);
	walkingAnimationUp.addFrame(sf::IntRect(799, 425, 43, 43));
	walkingAnimationUp.addFrame(sf::IntRect(799, 472, 43, 43));
	walkingAnimationUp.addFrame(sf::IntRect(799, 519, 43, 43));

	currentAnimation = &walkingAnimationRight;

	// set up AnimatedSprite
	sprite = AnimatedSprite(sf::seconds(0.2f), true, true);
	
	sprite.play(*currentAnimation);

	sf::Rect<float> rect = sprite.getGlobalBounds();
	float width = rect.width;
	float height = rect.height;
	sprite.setOrigin(width / 2.f, height / 2.f);
	//sprite.setScale(1.f, 1.f);
	sprite.setPosition(82, 402);
}

Character::~Character()
{
}

void Character::Draw(sf::RenderWindow & window)
{
	window.draw(sprite);
}

void Character::Update(bool collided, sf::Time frameTime)
{
	if (collided)
		return;

	sf::Vector2f pos = sprite.getPosition();
	pos += (direction*speed);
	sprite.setPosition(pos);

	sprite.update(frameTime);
}

void Character::ChangeDirectionUp()
{
	direction = sf::Vector2f(0,-1);
	currentAnimation = &walkingAnimationUp;
	sprite.play(*currentAnimation);
}

void Character::ChangeDirectionDown()
{
	direction = sf::Vector2f(0, 1);
	currentAnimation = &walkingAnimationDown;
	sprite.play(*currentAnimation);
}

void Character::ChangeDirectionRight()
{
	direction = sf::Vector2f(1, 0);
	
	currentAnimation = &walkingAnimationRight;
	sprite.play(*currentAnimation);
}

void Character::ChangeDirectionLeft()
{
	direction = sf::Vector2f(-1, 0);
	currentAnimation = &walkingAnimationLeft;
	sprite.play(*currentAnimation);
}

AnimatedSprite Character::GetSprite()
{
	return sprite;
}

sf::Vector2f Character::GetDirection()
{
	return direction;
}
