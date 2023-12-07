#pragma once

#include "Character.h"

class Player : public Character
{
private:
	sf::Clock timeSinceDamaged;
	Textures & textures;
	bool damageable();
	bool space{false};
	sf::Sprite weapon;
	void setWeaponLocation();

public:
	void takeDamage(int damage);
	Player(int x, int y, Textures &textures);
	~Player();
	void control(sf::Event &event);
	void move(sf::Time delta);
	void collided(GameObject *obstacle);
	std::string hpString();
	bool attacking();
	sf::FloatRect attackPoint();
	void draw(sf::RenderWindow &window);
	void setLocation(int x, int y);
};
