#include "Game.h"

Game::Game(std::string mazeFile) : map(mazeFile)
{
	// window.setVerticalSyncEnabled(true);
	window.setKeyRepeatEnabled(false);
	// map.mazeFile = mazeFile;
}

Game::~Game()
{
}

void Game::run()
{
	sf::Clock playTime;
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
		if (map.player->isDead())
		{
			endScreen(map.won, playTime.getElapsedTime());
		}
		else
		{
		window.clear(sf::Color(100, 100, 100, 0));
		update(delta);
		}
		
		window.display();
		sf::sleep(sf::milliseconds(5));
	}
}

void Game::update(sf::Time delta)
{
	map.update(delta);
	map.collisionCheck();
	map.draw(window);
}

void Game::endScreen(bool won, sf::Time playTime)
{
	if (finalPlayTime == 0)
	{
		finalPlayTime = playTime.asSeconds();
	}
	
	sf::Font font;
	sf::Text wintext;
	font.loadFromFile("font2.ttf");
	wintext.setFont(font);
	wintext.setCharacterSize(50);
	wintext.setStyle(sf::Text::Regular);
	wintext.setFillColor(sf::Color::White);
	wintext.setOutlineColor(sf::Color::Black);
	wintext.setOutlineThickness(2.0f);
	if (won)
	{
		wintext.setString("You won :D\nAnd in only " + std::to_string(finalPlayTime) + " seconds!");
	}
	else
	{
		wintext.setString("You lose");
	}
	wintext.setOrigin(wintext.getGlobalBounds().width / 2, wintext.getGlobalBounds().height/2);
	wintext.setPosition(1024/2, 576/2);

	window.clear();
	window.draw(wintext);
}