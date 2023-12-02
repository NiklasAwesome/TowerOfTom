#pragma once

#include <vector>
#include "GameObject.h"
#include "Player.h"
#include "Devil.h"
#include "Wall.h"


class Map
{
private:
	std::vector<GameObject*> objectList;
	sf::CircleShape collisionDetector{30};
	void setOuterWalls();
public:
	Player *player = new Player(32,32);
	Map(/* args */);
	~Map();
	void draw(sf::RenderWindow &window);
	void addObject(GameObject *gameObject);
	void update(sf::Time delta);
	void collisionCheck();
	bool collided(GameObject *first, GameObject *second);
};

