#pragma once
#include <SFML/Graphics.hpp>

class Textures
{
public:
	sf::Texture player;
	sf::Texture devil;
	sf::Texture devilHurt;
	sf::Texture wall;
	sf::Texture playerHurt;
	sf::Texture minion;
	sf::Texture minionHurt;
	sf::Texture door;
	sf::Texture dagger;
	sf::Texture fork;
	Textures();
	~Textures();
};