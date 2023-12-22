#pragma once

#include "Textures.h"
#include <SFML/Graphics.hpp>
#include <string>
#include <cmath>

class GameObject
{
// Attributes
protected:
	/**
	 * @brief Refrence to Map::textures
	 * 
	 */
	Textures & textures;
	/**
	 * @brief Sprite representing object
	 * 
	 */
	sf::Sprite sprite;
	/**
	 * @brief the objects location on the map
	 * 
	 */
	sf::Vector2f location{0,0};
	
public:	


// Members
protected:
	/**
	 * @brief Set the Texture of the Sprite
	 * 
	 * @param texture SFML texture
	 */
	void setTexture(sf::Texture &texture);

public:
	GameObject(int xLocation, int yLocation, Textures &textures);
	virtual ~GameObject();
	/**
	 * @brief Renders the object on the screen
	 * 
	 * @param window Refrence to the game window
	 */
	virtual void draw(sf::RenderWindow &window);
	/**
	 * @brief Lowers the hitpoints of the object
	 * 
	 * @param damage amount of hitpoints to deduct
	 */
	virtual void takeDamage(int damage) = 0;
	/**
	 * @brief returns the objects hitbox
	 * 
	 * @return sf::FloatRect SMFL hitbox used for collision detection
	 */
	sf::FloatRect bounds();
	virtual void move(sf::Time delta);
	virtual void collided(GameObject *obstacle);
	virtual void nextLevel();
	virtual bool isDead();
	virtual void setBack();
};
