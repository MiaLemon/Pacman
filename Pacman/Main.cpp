// Anything after // is a comment not actual C++ code
// Comments are important and I use them to explain things
// Why not read the comments in this code

// These "include" code from the C++ library and SFML too
#include "stdafx.h"
#include <SFML/Graphics.hpp>
#include <iostream>
#include "Character.h"
#include "Level.h"

// This is the main C++ program- Duh!
// It is where our game starts from
int main()
{
	// Make a window that is 800 by 200 pixels
	sf::RenderWindow window(sf::VideoMode(800, 800), "Pacman");

	Level level = Level();

	Character character = Character();

	sf::Clock frameClock;

	int characterPoints = 0;

	while (window.isOpen())
	{
		sf::Time frameTime = frameClock.restart();

		// The next 6 lines of code detect if the window is closed
		// And then shuts down the program
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
			if(event.type == sf::Event::KeyPressed)
			{
				if (event.key.code == sf::Keyboard::W || event.key.code == sf::Keyboard::Up)
					character.ChangeDirectionUp();
				else if (event.key.code == sf::Keyboard::S || event.key.code == sf::Keyboard::Down)
					character.ChangeDirectionDown();
				else if (event.key.code == sf::Keyboard::A || event.key.code == sf::Keyboard::Left)
					character.ChangeDirectionLeft();
				else if (event.key.code == sf::Keyboard::D || event.key.code == sf::Keyboard::Right)
					character.ChangeDirectionRight();
			}
		}

		// Clear everything from the last run of the while loop
		window.clear();

		// Draw our game scene here
		level.Draw(window);
		character.Draw(window);
		
		// Show everything we just drew
		window.display();

		int points = level.CollectPickup(character.GetSprite());
		characterPoints += points;

		if(points > 0)
			std::cout << "Points: " << characterPoints;

		//Check collision
		bool collided = level.CheckCollision(character.GetSprite(), character.GetDirection());

		character.Update(collided, frameTime);
	}

	return 0;
}