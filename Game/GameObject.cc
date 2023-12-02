#include "GameObject.h"

GameObject::GameObject(int xLocation, int yLocation)
{
	size = 32.0f;
	// setTexture("sprites/wall.png");
	location.x = xLocation;
	location.y = yLocation;
	prevLocation = location;
	sprite.setPosition(location);
}

GameObject::~GameObject()
{
}

void GameObject::setTexture(std::string imagePath)
{
	while (!texture.loadFromFile(imagePath))
	{
		/* code */
	}
	
	
	sprite.setTexture(texture);
}

void GameObject::move(sf::Time delta)
{
	if (delta.asSeconds() == 2.0f)
	{
		/* code */
	}
	
}

void GameObject::draw(sf::RenderWindow &window)
{
	window.draw(sprite);
}

void GameObject::collided(GameObject *obstacle)
{
	if (!obstacle->collidable)
	{
		sf::Vector2f helper;
		helper = prevLocation;
		prevLocation = location;
		location = helper;
		sprite.setPosition(location);
	}
}

float GameObject::upBound()
{
	return location.y;
}
float GameObject::downBound()
{
	return location.y + size;
}
float GameObject::leftBound()
{
	return location.x;
}
float GameObject::rightBound()
{
	return location.x + size;
}