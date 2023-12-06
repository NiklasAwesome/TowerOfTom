#pragma once

#include "GameObject.h"

class Wall : public GameObject
{
private:
	
public:
	Wall(int x, int y, sf::Texture &texture);
	~Wall();
	void move(sf::Time delta);
	void collided(GameObject *obstacle);
};


