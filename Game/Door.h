#pragma once

#include "GameObject.h"

class Door : public GameObject
{
private:
	/* data */
public:
	Door(int x, int y, Textures &textures);
	~Door();
	void move(sf::Time delta);
	void collided(GameObject *obstacle);
	void setLocation(int x, int y);
};


