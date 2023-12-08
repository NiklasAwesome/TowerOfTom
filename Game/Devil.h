#pragma once

#include "Player.h"
#include "Character.h"
#include <cstdlib>

class Devil : public Character
{
private:
	/**
	 * @brief Sets a random direction to be moved in
	 * 
	 */
	void setRandomDirection();
public:
	Devil(int x, int y, Textures &textures);
	~Devil();
	void collided(GameObject *obstacle) override;
	void move(sf::Time delta) override;
	void takeDamage(int damage) override;
};
