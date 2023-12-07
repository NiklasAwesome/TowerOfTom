#include "Textures.h"

Textures::Textures()
{
	devil.loadFromFile("sprites/devil.png");
	devilHurt.loadFromFile("sprites/devil_hurt.png");
	player.loadFromFile("sprites/protagonist.png");
	playerHurt.loadFromFile("sprites/protagonist_hurt.png");
	wall.loadFromFile("sprites/wall.png");
	minion.loadFromFile("sprites/minion.png");
	minionHurt.loadFromFile("sprites/minion_hurt.png");
	door.loadFromFile("sprites/door.png");
	dagger.loadFromFile("sprites/dagger.png");
	fork.loadFromFile("sprites/fork.png");
}

Textures::~Textures(){}