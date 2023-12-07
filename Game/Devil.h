#pragma once

#include "Player.h"
#include "Character.h"
#include <cstdlib>

class Devil : public Character
{
private:
	void setRandomDirection();
public:
	Devil(int x, int y, Textures &textures);
	~Devil();
	void collided(GameObject *obstacle);
	void move(sf::Time delta);
	void takeDamage(int damage);
};
