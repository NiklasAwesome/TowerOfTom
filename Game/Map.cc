#include "Map.h"

Map::Map(/* args */)
{
	collisionDetector.setPosition(900, 0);
	collisionDetector.setFillColor(sf::Color::Green);
	addObject(new Devil(500, 300));
	setOuterWalls();
}

Map::~Map()
{
}

void Map::draw(sf::RenderWindow &window)
{
	window.draw(collisionDetector);
	player->draw(window);
	if (objectList.size() > 0)
	{
		for (size_t i = 0; i < objectList.size(); i++)
		{
			objectList[i]->draw(window);
		}
	}
}

void Map::addObject(GameObject *gameObject)
{
	objectList.push_back(gameObject);
}

void Map::update(sf::Time delta)
{
	player->move(delta);
	if (objectList.size() > 0)
	{
		for (size_t i = 0; i < objectList.size(); i++)
		{
			objectList[i]->move(delta);
		}
	}

}

void Map::collisionCheck()
{
	bool collidedThisTurn = false;
	for (size_t i = 0; i < objectList.size(); i++)
	{
		for (size_t j = 0; j < objectList.size(); j++)
		{
			if (collided(objectList[i], objectList[j]))
			{
				collisionDetector.setFillColor(sf::Color::Red);
				objectList[i]->collided(objectList[j]);
				objectList[j]->collided(objectList[i]);
				collidedThisTurn = true;
			}
		}
		if (collided(player, objectList[i]))
		{
			collisionDetector.setFillColor(sf::Color::Red);
			player->collided(objectList[i]);
			objectList[i]->collided(player);
			collidedThisTurn = true;
		}
	}
	if (!collidedThisTurn)
	{
		collisionDetector.setFillColor(sf::Color::Green);
	}
}

bool Map::collided(GameObject *first, GameObject *second)
{
	if (!first->collidable && !second->collidable)
	{
		return false;
	}

	if (first == second)
	{
		return false;
	}

	if (first->leftBound() >= second->rightBound() || second->leftBound() >= first->rightBound())
	{
		return false;
	}
	if (first->upBound() >= second->downBound() || second->upBound() >= first->downBound())
	{
		return false;
	}
	return true;
}

void Map::setOuterWalls()
{
	for (int i = 0; i < 18; i++)
	{
		addObject(new Wall{0, 32*i});
		addObject(new Wall{992, 32*i});
	}
	for (int i = 1; i < 31; i++)
	{
		addObject(new Wall{32*i, 0});
		addObject(new Wall{32*i, 544});
	}
	
	
}