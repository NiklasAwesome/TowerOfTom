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
private:
	std::vector<GameObject *> propList;
	std::vector<Character *> characterList;
	Textures textures;
	void setOuterWalls();
	void setBasicMaze();
	sf::Font font;
	sf::Text hitpointsText;
	std::vector<std::vector<std::string>> mazeList;
	void readMapFile();
	void setMaze(std::vector<std::string> maze);
	void clearMap();
	int level{0};
	void setWinScreen();
	void setLooseScreen();
public:
	bool won{false};
	Player *player;
	Door *door;
	Map(/* args */);
	~Map();
	void draw(sf::RenderWindow &window);
	void addProp(GameObject *gameObject);
	void addCharacter(Character *character);
	void update(sf::Time delta);
	void collisionCheck();
	bool collided(GameObject *first, GameObject *second);
};
