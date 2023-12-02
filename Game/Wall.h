#pragma once

#include "GameObject.h"

class Wall : public GameObject
{
private:
	
public:
	Wall(int x, int y);
	~Wall();
	void move(sf::Time delta);
	void collided(GameObject *obstacle);
};


