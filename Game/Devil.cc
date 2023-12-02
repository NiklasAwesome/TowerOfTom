#include "Devil.h"


Devil::Devil(int x, int y) : Character(x, y)
{
	setTexture("sprites/devil.png");
	size = 31.0f;
	collidable = true;
	speed = 100.0f;
	down = true;
}

Devil::~Devil()
{
}

void Devil::setRandomDirection()
{
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

void Devil::collided(GameObject *obstacle)
{
	if (!obstacle->collidable)
	{
		sf::Vector2f helper;
		helper = prevLocation;
		prevLocation = location;
		location = helper;
		sprite.setPosition(location);
	}
	setRandomDirection();
}

void Devil::move(sf::Time delta)
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