#pragma once
#include "Character.h"

class Minion : public Character
{
private:
	/**
	 * @brief time since setRandomDirection was called
	 * 
	 */
	sf::Clock timeSinceRandom;
	/**
	 * @brief Sets a random direction to be moved in
	 * 
	 */
	void setRandomDirection();
public:
	Minion(int x, int y, Textures &textures);
	~Minion();
	void collided(GameObject *obstacle) override;
	void move(sf::Time delta) override;
	void takeDamage(int damage) override;
	void setBack() override;
	void nextLevel() override;
};

