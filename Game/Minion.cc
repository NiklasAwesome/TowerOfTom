#include "Minion.h"

Minion::Minion(int x, int y, Textures &textures) : Character(x, y, textures)
{
	hitpoints = 2;
	damage = 1;
	collidable = true;
	speed = 200.0f;
	down = true;
	setTexture(textures.minion);
}

Minion::~Minion()
{
}

void Minion::setRandomDirection()
{
	timeSinceRandom.restart();
	up = false;
	down = false;
	left = false;
	right = false;

	int dirNum = std::rand() % 4;
	switch (dirNum)
	{
	case 0:
		up = true;
		break;
	case 1:
		down = true;
		break;
	case 2:
		left = true;
		break;
	case 3:
		right = true;
		break;
	
	default:
		break;
	}
}

void Minion::collided(GameObject *obstacle)
{
	if (!obstacle->collidable)
	{
		sf::Vector2f helper;
		helper = prevLocation;
		prevLocation = location;
		location = helper;
		sprite.setPosition(location);
	}
	else
	{
		obstacle->takeDamage(damage);
	}
	
	
	setRandomDirection();
}

void Minion::move(sf::Time delta)
{
	if (timeSinceRandom.getElapsedTime() > sf::seconds(1))
	{
		setRandomDirection();
	}
	
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
	if (damageable())
	{
		setTexture(textures.minion);
	}
}

void Minion::takeDamage(int damage)
{
	if (damageable())
	{
		setTexture(textures.minionHurt);
		timeSinceDamaged.restart();
		hitpoints -= damage;
	}
	setRandomDirection();
	
}