#include "GameObject.h"

GameObject::GameObject(int xLocation, int yLocation, Textures &textures) : textures{textures}
{
	location.x = xLocation;
	location.y = yLocation;
	setTexture(textures.wall);
	sprite.setPosition(location);
}

GameObject::~GameObject()
{
}

void GameObject::setTexture(sf::Texture &texture)
{
	sprite.setTexture(texture, true);
}

void GameObject::draw(sf::RenderWindow &window)
{
	window.draw(sprite);
}

sf::FloatRect GameObject::bounds()
{
	return sprite.getGlobalBounds();
}

void GameObject::collided(GameObject *obstacle)
{
	obstacle->setBack();
}

void GameObject::nextLevel()
{
}

void GameObject::move(sf::Time delta)
{
	(void)delta;
}

bool GameObject::isDead()
{
	return false;
}

void GameObject::setBack()
{
}