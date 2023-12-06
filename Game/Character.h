#pragma once

#include "GameObject.h"

class Character : public GameObject
{
protected:
	float speed;
	sf::Vector2f direction{0,0};
	bool up{false};
	bool down{false};
	bool left{false};
	bool right{false};

public:
	Character(int x, int y, sf::Texture &texture);
	virtual ~Character();
	void move(sf::Time delta);
};


