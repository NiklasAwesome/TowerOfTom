#include "Door.h"

Door::Door(int x, int y, Textures &textures) : GameObject(x, y, textures)
{
	setTexture(textures.door);
}

Door::~Door()
{
}

void Door::takeDamage(int damage)
{
	(void)damage;
}

void Door::setLocation(int x, int y)
{
	location.x = x;
	location.y = y;
	sprite.setPosition(x, y);
}