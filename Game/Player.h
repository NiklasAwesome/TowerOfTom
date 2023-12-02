#pragma once

#include "Character.h"

class Player : public Character
{
private:
	

public:
	Player(int x, int y);
	~Player();
	void control(sf::Event &event);
	void move(sf::Time delta);
	// void collided(GameObject *obstacle);
};
