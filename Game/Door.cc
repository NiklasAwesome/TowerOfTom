#include "Door.h"

Door::Door(int x, int y, Textures &textures) : GameObject(x, y, textures)
{
	setTexture(textures.door);
}

Door::~Door()
{
}

void Door::move(sf::Time delta)
{
	if (delta.asSeconds() == 100000000.0f)
	{
		/* code */
	}
	
}

void Door::collided(GameObject *obstacle)
{
	if (!obstacle->collidable)
	{
		
	}
}

void Door::setLocation(int x, int y)
{
	location.x = x;
	location.y = y;
	sprite.setPosition(x, y);
}