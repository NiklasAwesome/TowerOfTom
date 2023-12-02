#include "Game.h"

Game::Game(/* args */)
{
	// window.setVerticalSyncEnabled(true);
	window.setKeyRepeatEnabled(false);
}

Game::~Game()
{
}

void Game::run()
{
	sf::Clock clock;
	sf::Event event;
	while (true)
	{
		sf::Time delta = clock.restart();
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
			{
				return;
			}

			if (event.type == sf::Event::KeyPressed || event.type == sf::Event::KeyReleased)
			{
				map.player->control(event);
			}
		}
		window.clear(sf::Color(100,100,100,0));
		update(delta);
		window.display();
		sf::sleep(sf::milliseconds(10));
	}
}

void Game::update(sf::Time delta)
{
	map.update(delta);
	map.collisionCheck();
	map.draw(window);
}

