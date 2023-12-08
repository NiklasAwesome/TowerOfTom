#include "Wall.h"

Wall::Wall(int x, int y, Textures &textures) : GameObject(x, y, textures)
{
	setTexture(textures.wall);
}

Wall::~Wall()
{
}

void Wall::takeDamage(int damage)
{
	(void)damage;
}