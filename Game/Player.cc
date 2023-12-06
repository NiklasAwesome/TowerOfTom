#include "Player.h"

Player::Player(int x, int y, sf::Texture &texture) : Character(x, y, texture)
{
	size = 31.0f;
	collidable = true;
	speed = 400.0f;

}

Player::~Player()
{
}

void Player::control(sf::Event &event)
{
	bool pressed;
	if (event.type == sf::Event::KeyPressed)
	{
		pressed = true;
	}
	else if (event.type == sf::Event::KeyReleased)
	{
		pressed = false;
	}
	else
	{
		return;
	}
	switch (event.key.code)
	{
	case sf::Keyboard::W:
	case sf::Keyboard::Up:
		up = pressed;
		break;

	case sf::Keyboard::S:
	case sf::Keyboard::Down:
		down = pressed;
		break;

	case sf::Keyboard::A:
	case sf::Keyboard::Left:
		left = pressed;
		break;

	case sf::Keyboard::D:
	case sf::Keyboard::Right:
		right = pressed;
		break;

	default:
		break;
	}
}

void Player::move(sf::Time delta)
{
	prevLocation = location;
	float distance = speed * (delta.asMicroseconds() / 1000000.0f);
	sf::Vector2f direction{0,0};
	if (up)
	{
		direction.y -= 1;
	}
	if (down)
	{
		direction.y += 1;
	}
	if (left)
	{
		direction.x -= 1;
	}
	if (right)
	{
		direction.x += 1;
	}
	

	location.x += direction.x * distance;
	location.y += direction.y * distance;
	sprite.setPosition(location);
}

// void Player::collided(GameObject *obstacle)
// {
// 	if (!obstacle->collidable)
// 	{
// 		sf::Vector2f helper;
// 		helper = prevLocation;
// 		prevLocation = location;
// 		location = helper;
// 		sprite.setPosition(location);
// 	}
// }