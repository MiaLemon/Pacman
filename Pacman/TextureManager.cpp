#include "stdafx.h"
#include "TextureManager.h"

TextureManager::TextureManager()
{
}

TextureManager::~TextureManager()
{
	UnloadLevelTextures();
}

sf::Texture & TextureManager::GetLevelTexture(string path)
{
	if (levelTextures.find(path) == levelTextures.end())
	{
		sf::Texture & tex = levelTextures[path];
		if (!tex.loadFromFile(path))
			std::cout << "Failed to load texture at path: " << path;

		return tex;
	}
	else
		return levelTextures[path];
}

void TextureManager::UnloadLevelTextures()
{
	for (auto iterator = levelTextures.begin(); iterator != levelTextures.end(); iterator++)
	{
		iterator->second.~Texture();
	}
}
