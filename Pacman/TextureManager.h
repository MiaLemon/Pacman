#pragma once

#include <SFML/Graphics.hpp>
#include <map>
#include <string>
#include <iostream>

using namespace std;

class TextureManager
{
public:
	TextureManager();
	~TextureManager();

	sf::Texture & GetLevelTexture(string path);

	void UnloadLevelTextures();

private:
	map<string, sf::Texture> levelTextures;
};

