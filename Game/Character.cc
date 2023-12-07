#include "Character.h"

Character::Character(int x, int y, Textures &textures) : GameObject(x, y, textures), textures(textures)
{
	
}

Character::~Character()
{
}

bool Character::isDead()
{
	return hitpoints <= 0;
}

void Character::move(sf::Time delta)
{
	prevLocation = location;
	float distance = speed * (delta.asMicroseconds() / 1000000.0f);
	sf::Vector2f direction{0,0};
	if (up)
	{
		direction.y -= 1;
	}
	if (down)
	{
		direction.y += 1;
	}
	if (left)
	{
		direction.x -= 1;
	}
	if (right)
	{
		direction.x += 1;
	}
	if(direction.x == 0 && direction.y == 0)
	{
		sprite.rotate(0.2f);
	}

	location.x += direction.x * distance;
	location.y += direction.y * distance;
	sprite.setPosition(location);
}

bool Character::damageable()
{
	return timeSinceDamaged.getElapsedTime() > sf::seconds(1.0f);
}

void Character::takeDamage(int damage)
{
	if (damageable())
	{
		timeSinceDamaged.restart();
		hitpoints -= damage;
	}
}