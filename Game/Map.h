#pragma once

#include <vector>
#include "GameObject.h"
#include "Player.h"
#include "Devil.h"
#include "Wall.h"

struct Textures
{
	sf::Texture player;
	sf::Texture devil;
	sf::Texture wall;
};

class Map
{
private:
	std::vector<GameObject *> objectList;
	sf::CircleShape collisionDetector{30};
	Textures textures;
	void setOuterWalls();
	void setBasicMaze();

public:
	Player *player;
	Map(/* args */);
	~Map();
	void draw(sf::RenderWindow &window);
	void addObject(GameObject *gameObject);
	void update(sf::Time delta);
	void collisionCheck();
	bool collided(GameObject *first, GameObject *second);
};
