#pragma once

#include "Character.h"

class Player : public Character
{
// Attributes
private:
	/**
	 * @brief To see if spacebar is pressed
	 * 
	 */
	bool space{false};
	/**
	 * @brief the sprite representing the players weapon
	 * 
	 */
	sf::Sprite weapon;
public:
	bool newLevel;

// Members
private:
	/**
	 * @brief Set the Weapons location based on players location
	 * 
	 */
	void setWeaponLocation();

public:
	void move(sf::Time delta) override;
	void collided(GameObject *obstacle) override;
	void takeDamage(int damage) override;
	void draw(sf::RenderWindow &window) override;
	void nextLevel() override;
	
	Player(int x, int y, Textures &textures);
	~Player();
	/**
	 * @brief handles keyboard input
	 * 
	 * @param event event containing keyboard input
	 */
	void control(sf::Event &event);
	/**
	 * @brief Gets the players hitpoints as a string
	 * 
	 * @return std::string players hitpoints
	 */
	std::string hpString();
	/**
	 * @brief If the player is attacking or not
	 * 
	 * @return true player is attacking
	 * @return false player is not attacking
	 */
	bool attacking();
	/**
	 * @brief returns the hitbox of the players weapon
	 * 
	 * @return sf::FloatRect the weapons hitbox
	 */
	sf::FloatRect attackPoint();
	/**
	 * @brief Set the Location of the player
	 * 
	 * @param x x value of location
	 * @param y y value of location
	 */
	void setLocation(int x, int y);

	void setBack() override;
};
