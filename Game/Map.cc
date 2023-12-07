#include "Map.h"

Map::Map(/* args */)
{
	font.loadFromFile("font2.ttf");
	hitpointsText.setFont(font);
	hitpointsText.setPosition(0, 0);
	hitpointsText.setCharacterSize(30);
	hitpointsText.setStyle(sf::Text::Regular);
	hitpointsText.setFillColor(sf::Color::White);
	hitpointsText.setOutlineColor(sf::Color::Black);
	hitpointsText.setOutlineThickness(2.0f);
	hitpointsText.setString("");

	player = new Player(40, 40, textures);
	door = new Door(100, 100, textures);
	readMapFile();
	setMaze(mazeList[0]);
}

Map::~Map()
{
	delete player;
	for (size_t i = 0; i < propList.size(); i++)
	{
		delete propList[i];
	}
	for (size_t i = 0; i < characterList.size(); i++)
	{
		delete characterList[i];
	}
}

void Map::draw(sf::RenderWindow &window)
{
	player->draw(window);
	door->draw(window);
	if (propList.size() > 0)
	{
		for (size_t i = 0; i < propList.size(); i++)
		{
			propList[i]->draw(window);
		}
	}
	if (characterList.size() > 0)
	{
		for (size_t i = 0; i < characterList.size(); i++)
		{
			characterList[i]->draw(window);
		}
	}
	window.draw(hitpointsText);
}

void Map::addProp(GameObject *gameObject)
{
	propList.push_back(gameObject);
}

void Map::addCharacter(Character *character)
{
	characterList.push_back(character);
}

void Map::update(sf::Time delta)
{
	hitpointsText.setString(player->hpString());
	player->move(delta);
	if (characterList.size() > 0)
	{
		for (size_t i = 0; i < characterList.size(); i++)
		{
			characterList[i]->move(delta);
		}
	}
	if (player->attacking())
	{
		for (size_t i = 0; i < characterList.size(); i++)
		{
			if (characterList[i]->bounds().intersects(player->attackPoint()))
			{
				characterList[i]->takeDamage(player->damage);
				if (characterList[i]->isDead())
				{
					characterList.erase(characterList.begin() + i);
				}

				break;
			}
		}
	}
}

void Map::collisionCheck()
{
	for (size_t i = 0; i < characterList.size(); i++)
	{
		for (size_t j = 0; j < propList.size(); j++)
		{
			if (collided(characterList[i], propList[j]))
			{
				characterList[i]->collided(propList[j]);
			}
		}
		if (collided(player, characterList[i]))
		{
			player->collided(characterList[i]);
			characterList[i]->collided(player);
		}
	}
	for (size_t i = 0; i < propList.size(); i++)
	{
		if (collided(player, propList[i]))
		{
			player->collided(propList[i]);
		}
	}
	if (collided(player, door))
	{
		level++;
		if (level < (int)mazeList.size())
		{
			setMaze(mazeList[level]);
		}
		else
		{
			won = true;
			player->takeDamage(10000);
		}
	}
}

bool Map::collided(GameObject *first, GameObject *second)
{
	return first->bounds().intersects(second->bounds());
}

void Map::setOuterWalls()
{
	for (int i = 0; i < 18; i++)
	{
		addProp(new Wall{0, 32 * i, textures});
		addProp(new Wall{992, 32 * i, textures});
	}
	for (int i = 1; i < 31; i++)
	{
		addProp(new Wall{32 * i, 0, textures});
		addProp(new Wall{32 * i, 544, textures});
	}
}

void Map::setBasicMaze()
{
	std::vector<std::string> maze;

	maze.push_back("0P0000000000000");
	maze.push_back("000000000000000");
	maze.push_back("000000000000000");
	maze.push_back("000000000000000");
	maze.push_back("0000000W0000000");
	maze.push_back("000000000000000");
	maze.push_back("00000000000000E");
	maze.push_back("000MM00000000D0");

	setMaze(maze);
}

void Map::readMapFile()
{
	std::vector<std::string> maze;
	std::ifstream myfile("mapfile.txt");
	if (myfile.is_open())
	{
		std::string line;
		while (std::getline(myfile, line))
		{
			if (line[0] == '.')
			{
				break;
			}
			
			if (line[0] == '#')
			{
				mazeList.push_back(maze);
				maze.clear();
			}
			else
			{
				maze.push_back(line);
			}
		}
		myfile.close();
	}
}

void Map::setMaze(std::vector<std::string> maze)
{
	clearMap();
	setOuterWalls();
	for (size_t i = 0; i < maze.size() && i < 8; i++)
	{
		for (size_t c = 0; c < maze[i].size() && c < 15; c++)
		{
			if (maze[i][c] == 'W')
			{
				addProp(new Wall{32 + 64 * (int)c, 32 + 64 * (int)i, textures});
				addProp(new Wall{32 + 64 * (int)c + 32, 32 + 64 * (int)i, textures});
				addProp(new Wall{32 + 64 * (int)c, 32 + 64 * (int)i + 32, textures});
				addProp(new Wall{32 + 64 * (int)c + 32, 32 + 64 * (int)i + 32, textures});
			}
			if (maze[i][c] == 'D')
			{
				addCharacter(new Devil{32 + 64 * (int)c, 32 + 64 * (int)i, textures});
			}
			if (maze[i][c] == 'M')
			{
				addCharacter(new Minion{32 + 64 * (int)c, 32 + 64 * (int)i, textures});
			}
			if (maze[i][c] == 'E')
			{
				door->setLocation(32 + 64 * (int)c, 32 + 64 * (int)i);
			}
			if (maze[i][c] == 'P')
			{
				player->setLocation(32 + 64 * (int)c, 32 + 64 * (int)i);
			}
		}
	}
}

void Map::clearMap()
{
	propList.clear();
	characterList.clear();
}

void Map::setWinScreen()
{

}