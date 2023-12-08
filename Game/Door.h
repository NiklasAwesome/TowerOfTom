#pragma once

#include "GameObject.h"

class Door : public GameObject
{
private:

public:
	Door(int x, int y, Textures &textures);
	~Door();
	void takeDamage(int damage) override;
	/**
	 * @brief Set the Location of the door
	 * 
	 * @param x x value of location
	 * @param y y value of location
	 */
	void setLocation(int x, int y);
};


