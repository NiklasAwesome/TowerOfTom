#pragma once
#include "Character.h"

class Minion : public Character
{
private:
	sf::Clock timeSinceRandom;
	void setRandomDirection();
public:
	Minion(int x, int y, Textures &textures);
	~Minion();
	void collided(GameObject *obstacle);
	void move(sf::Time delta);
	void takeDamage(int damage);
};

