#include "Wall.h"

Wall::Wall(int x, int y) : GameObject(x, y)
{
	setTexture("sprites/wall.png");
}

Wall::~Wall()
{
}

void Wall::move(sf::Time delta)
{
	if (delta.asSeconds() == 100000000.0f)
	{
		/* code */
	}
	
}

void Wall::collided(GameObject *obstacle)
{
	if (!obstacle->collidable)
	{
		
	}
}