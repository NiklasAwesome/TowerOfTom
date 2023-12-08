#pragma once

#include <vector>
#include <fstream>
#include "GameObject.h"
#include "Player.h"
#include "Devil.h"
#include "Minion.h"
#include "Wall.h"
#include "Door.h"



class Map
{
// Attributes
private:
	/**
	 * @brief The map level
	 * 
	 */
	int level{0};
	/**
	 * @brief vector of all non-Character gameobjects
	 * 
	 */
	std::vector<GameObject *> propList;
	/**
	 * @brief vector of all non-Player characters
	 * 
	 */
	std::vector<Character *> characterList;
	/**
	 * @brief Object that handles SFML Textures
	 * 
	 */
	Textures textures;
	/**
	 * @brief The font for the HP-Text
	 * 
	 */
	sf::Font font;
	/**
	 * @brief SFML Text for shoeing the players hitpoints
	 * 
	 */
	sf::Text hitpointsText;
	/**
	 * @brief Object for holding all levels of the game
	 * 
	 */
	std::vector<std::vector<std::string>> mazeList;
	/**
	 * @brief Refrence to the exit/next level door
	 * 
	 */
	Door *door;
	/**
	 * @brief The path to the file of levels
	 * 
	 */
	std::string mazeFile;
public:
	/**
	 * @brief When the game ends this bool determines if we won or lost
	 * 
	 */
	bool won{false};
	/**
	 * @brief Reference to the player
	 * 
	 */
	Player *player;
// Members
private:
	/**
	 * @brief Setup the Hit Point Text object
	 * 
	 */
	void setHitPointText();
	/**
	 * @brief Reads data from the map file
	 * 
	 */
	void readMapFile();
	/**
	 * @brief Setup the Maze/level
	 * 
	 * @param maze the maze as read from file
	 */
	void setMaze(std::vector<std::string> maze);
	/**
	 * @brief clears the map of all objects
	 * 
	 */
	void clearMap();
	/**
	 * @brief Set the Outer Walls along window edges
	 * 
	 */
	void setOuterWalls();
	/**
	 * @brief Checks if two objects have collided
	 * 
	 * @param first any game object
	 * @param second any game object
	 * @return true The object have collided
	 * @return false The object have not collided
	 */
	bool collided(GameObject *first, GameObject *second);
	/**
	 * @brief adds a gameobject to propList vector
	 * 
	 * @param gameObject any game object
	 */
	void addProp(GameObject *gameObject);
	/**
	 * @brief Adds a charatect to characterList vector
	 * 
	 * @param character any character
	 */
	void addCharacter(Character *character);
public:
	Map(std::string mazeFile);
	~Map();
	/**
	 * @brief Checks if any object has collided with any other object
	 * 
	 */
	void collisionCheck();
	/**
	 * @brief Renders all objects to the screen
	 * 
	 * @param window Refrence to the game window
	 */
	void draw(sf::RenderWindow &window);
	/**
	 * @brief updates all objects and thier attributes
	 * 
	 * @param delta time diffrence between each gameloop
	 */
	void update(sf::Time delta);
};
