#pragma once

#include "GameObject.h"

class Wall : public GameObject
{
private:
	
public:
	Wall(int x, int y, Textures &textures);
	~Wall();
	void takeDamage(int damage) override;
};


