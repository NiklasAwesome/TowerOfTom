#pragma once

#include "GameObject.h"

class Character : public GameObject
{
protected:
	float speed;
	int hitpoints{1};
	sf::Vector2f direction{0,0};
	bool up{false};
	bool down{false};
	bool left{false};
	bool right{false};
	sf::Clock timeSinceDamaged;
	bool damageable();
	Textures & textures;


public:
	int damage;
	Character(int x, int y, Textures &textures);
	virtual ~Character();
	void move(sf::Time delta);
	bool isDead();
	virtual void takeDamage(int damage);
};


