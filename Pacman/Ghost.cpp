#include "stdafx.h"
#include "Ghost.h"


Ghost::Ghost(sf::Texture & texture)
{
	direction = { 1, 0 };
	speed = 0.04f;

	// set up the animations for all four directions (set spritesheet and push frames)
	walkingAnimationRight.setSpriteSheet(texture);
	walkingAnimationRight.addFrame(sf::IntRect(608, 0, 43, 43));
	walkingAnimationRight.addFrame(sf::IntRect(608, 47, 43, 43));

	walkingAnimationDown.setSpriteSheet(texture);
	walkingAnimationDown.addFrame(sf::IntRect(608, 94, 43, 43));
	walkingAnimationDown.addFrame(sf::IntRect(608, 144, 43, 43));

	walkingAnimationLeft.setSpriteSheet(texture);
	walkingAnimationLeft.addFrame(sf::IntRect(608, 191, 43, 43));
	walkingAnimationLeft.addFrame(sf::IntRect(608, 238, 43, 43));

	walkingAnimationUp.setSpriteSheet(texture);
	walkingAnimationUp.addFrame(sf::IntRect(608, 285, 43, 43));
	walkingAnimationUp.addFrame(sf::IntRect(608, 332, 43, 43));

	currentAnimation = &walkingAnimationRight;

	// set up AnimatedSprite
	sprite = AnimatedSprite(sf::seconds(0.2f), true, true);

	sprite.play(*currentAnimation);

	sf::Rect<float> rect = sprite.getGlobalBounds();
	float width = rect.width;
	float height = rect.height;
	sprite.setOrigin(width / 2.f, height / 2.f);
	sprite.setPosition(384, 402);
}


Ghost::~Ghost()
{
}

void Ghost::Draw(sf::RenderWindow & window)
{
	window.draw(sprite);
}

void Ghost::Update(bool collided, sf::Time frameTime)
{
	if (collided)
		return;

	sf::Vector2f pos = sprite.getPosition();
	pos += (direction*speed);
	sprite.setPosition(pos);

	sprite.update(frameTime);
}
