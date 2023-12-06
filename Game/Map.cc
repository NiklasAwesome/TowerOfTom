#include "Map.h"

Map::Map(/* args */)
{
	textures.devil.loadFromFile("sprites/devil.png");
	textures.player.loadFromFile("sprites/protagonist.png");
	textures.wall.loadFromFile("sprites/wall.png");
	collisionDetector.setPosition(900, 0);
	collisionDetector.setFillColor(sf::Color::Green);
	player = new Player(32,32,textures.player);
	setOuterWalls();
	setBasicMaze();
}

Map::~Map()
{
	delete player;
	for (size_t i = 0; i < objectList.size(); i++)
	{
		delete objectList[i];
	}
	
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
		addObject(new Wall{0, 32*i, textures.wall});
		addObject(new Wall{992, 32*i, textures.wall});
	}
	for (int i = 1; i < 31; i++)
	{
		addObject(new Wall{32*i, 0, textures.wall});
		addObject(new Wall{32*i, 544, textures.wall});
	}
	
	
}

// void Map::setBasicMaze()
// {
// 	std::vector<std::string> maze;
// 	maze.push_back("010001000001000000000000000000");
// 	maze.push_back("010101001001000000000000000000");
// 	maze.push_back("010101001001011111111111111100");
// 	maze.push_back("010101001000010000000011000000");
// 	maze.push_back("010101001111110000000011000000");
// 	maze.push_back("010101001000000000000011000000");
// 	maze.push_back("010101001000000000000011000000");
// 	maze.push_back("010101001000000000000011000000");
// 	maze.push_back("010101001000000000000011000000");
// 	maze.push_back("010101001000000000000011000000");
// 	maze.push_back("010101001000000000000011000000");
// 	maze.push_back("010101001000000000000011000000");
// 	maze.push_back("010101001000000000000011000000");
// 	maze.push_back("010101001000000000000011000000");
// 	maze.push_back("010101001000000000000011000000");
// 	maze.push_back("000100001000000000000011000000");

	
// 	for (size_t i = 0; i < maze.size(); i++)
// 	{
// 		for (size_t c = 0; c < maze[i].size(); c++)
// 		{
// 			if (maze[i][c] == '1')
// 			{
// 				addObject(new Wall{32*((int)c + 1), 32*((int)i+1), textures.wall});
// 			}
// 		}
// 	}
	
// }

void Map::setBasicMaze()
{
	std::vector<std::string> maze;
	maze.push_back("010001000001000");
	maze.push_back("010101001001000");
	maze.push_back("010101001001011");
	maze.push_back("010101001000000");
	maze.push_back("010101001101110");
	maze.push_back("010101001222222");
	maze.push_back("010101001222222");
	maze.push_back("000100001222222");

	
	for (size_t i = 0; i < maze.size(); i++)
	{
		for (size_t c = 0; c < maze[i].size(); c++)
		{
			if (maze[i][c] == '1')
			{
				addObject(new Wall{32 + 64*(int)c, 32 + 64*(int)i, textures.wall});
				addObject(new Wall{32 + 64*(int)c + 32, 32 + 64*(int)i, textures.wall});
				addObject(new Wall{32 + 64*(int)c, 32 + 64*(int)i + 32, textures.wall});
				addObject(new Wall{32 + 64*(int)c + 32, 32 + 64*(int)i + 32, textures.wall});
			}
			if (maze[i][c] == '2')
			{
				addObject(new Devil{32 + 64*(int)c, 32 + 64*(int)i, textures.devil});
			}
			
		}
	}
	
}