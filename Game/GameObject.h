#pragma once

#include "Textures.h"
#include <SFML/Graphics.hpp>
#include <string>
#include <cmath>

class GameObject
{
protected:
	float size;
	sf::Sprite sprite;
	sf::Vector2f prevLocation{0,0};
	sf::Vector2f location{0,0};
	float prevRotation{0};
	float rotation{0};
	void setTexture(sf::Texture &texture);
	sf::Vector2f normalize(sf::Vector2f &v);
public:
	bool collidable{false};
	GameObject(int xLocation, int yLocation, Textures &textures);
	virtual ~GameObject();
	virtual void move(sf::Time delta) = 0;
	void draw(sf::RenderWindow &window);
	virtual void collided(GameObject *obstacle);
	virtual void takeDamage(int);
	sf::FloatRect bounds();
};
