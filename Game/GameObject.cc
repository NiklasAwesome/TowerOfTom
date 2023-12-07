#include "GameObject.h"

GameObject::GameObject(int xLocation, int yLocation, Textures &textures)
{
	size = 32.0f;
	location.x = xLocation;
	location.y = yLocation;
	prevLocation = location;
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

void GameObject::takeDamage(int damage)
{
	if (damage == 10000)
	{
		/* code */
	}
}

sf::Vector2f GameObject::normalize(sf::Vector2f &v)
{
	float len = std::sqrt(v.x * v.x + v.y * v.y);
	if (len <= 0.0f)
		return sf::Vector2f{0, 0};
	else
		return v * (1.0f / len);
}

sf::FloatRect GameObject::bounds()
{
	return sprite.getGlobalBounds();
}
