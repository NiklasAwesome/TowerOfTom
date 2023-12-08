#pragma once

#include "GameObject.h"

class Character : public GameObject
{
// Attributes
protected:
	/**
	 * @brief movment speed of the character in pixels per second
	 * 
	 */
	float speed;
	/**
	 * @brief number of hitpoints of the character
	 * 
	 */
	int hitpoints{1};
	/**
	 * @brief the direction the character is moving in
	 * 
	 */
	sf::Vector2f direction{0,0};
	/**
	 * @brief helping attribute for direction of movement
	 * 
	 */
	bool up{false};
	/**
	 * @brief helping attribute for direction of movement
	 * 
	 */
	bool down{false};
	/**
	 * @brief helping attribute for direction of movement
	 * 
	 */
	bool left{false};
	/**
	 * @brief helping attribute for direction of movement
	 * 
	 */
	bool right{false};
	/**
	 * @brief The time since the character took any damage
	 * 
	 */
	sf::Clock timeSinceDamaged;
	/**
	 * @brief the previous rotation before the current one
	 * 
	 */
	float prevRotation{0};
	/**
	 * @brief the previous location before the current one
	 * 
	 */
	sf::Vector2f prevLocation{0,0};
	/**
	 * @brief the angular rotation of the character
	 * 
	 */
	float rotation{0};
public:
	/**
	 * @brief the amount of damage the character does when attacking
	 * 
	 */
	int damage;
// Members
protected:
	/**
	 * @brief Normalizes the direction so the character doesn't move faster diagonally
	 * 
	 * @param v the currect direction
	 * @return sf::Vector2f the normalized direction
	 */
	sf::Vector2f normalize(sf::Vector2f &v);
	/**
	 * @brief if the character can be damaged or not
	 * 
	 * @return true can be damaged
	 * @return false can not be damaged
	 */
	bool damageable();
public:
	Character(int x, int y, Textures &textures);
	virtual ~Character();
	/**
	 * @brief Moves the character based on speed in the direction that is set
	 * 
	 * @param delta time since last gameloop
	 */
	virtual void move(sf::Time delta);
	/**
	 * @brief If the character is dead or alive
	 * 
	 * @return true Character is dead
	 * @return false Character is alive
	 */
	bool isDead();
	/**
	 * @brief sets what happens when the character collides with another object
	 * 
	 * @param obstacle the object that the character has collided with
	 */
	virtual void collided(GameObject *obstacle);
	virtual void takeDamage(int damage) override;
};


