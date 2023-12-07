#include "Player.h"

Player::Player(int x, int y, Textures &textures) : Character(x + 16, y + 16, textures), textures(textures)
{
	hitpoints = 20;
	damage = 1;
	size = 31.0f;
	collidable = true;
	speed = 150.0f;
	setTexture(textures.player);
	weapon.setTexture(textures.fork, true);

	sprite.setOrigin(size / 2, size / 2);
	weapon.setOrigin(weapon.getGlobalBounds().width/2, weapon.getGlobalBounds().height/2);
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

	case sf::Keyboard::Space:
		space = pressed;
		break;

	default:
		break;
	}
}

void Player::move(sf::Time delta)
{
	prevLocation = location;
	prevRotation = rotation;
	float distance = speed * (delta.asMicroseconds() / 1000000.0f);
	sf::Vector2f direction{0, 0};
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

	direction = normalize(direction);
	if (direction.x != 0 || direction.y != 0)
	{
		rotation = std::atan2(-direction.x, direction.y);
	}

	location.x += direction.x * distance;
	location.y += direction.y * distance;
	sprite.setPosition(location);
	sprite.setRotation(rotation * (180 / 3.141592654f));
	if (damageable())
	{
		setTexture(textures.player);
	}
	setWeaponLocation();
}

void Player::collided(GameObject *obstacle)
{
	if (!obstacle->collidable)
	{
		sf::Vector2f helper;
		float rotHelper;
		helper = prevLocation;
		prevLocation = location;
		location = helper;

		rotHelper = prevRotation;
		prevRotation = rotation;
		rotation = rotHelper;
		sprite.setPosition(location);
		sprite.setRotation(rotation * (180 / 3.141592654f));
	}
}

void Player::takeDamage(int damage)
{
	if (damageable())
	{
		setTexture(textures.playerHurt);
		timeSinceDamaged.restart();
		hitpoints -= damage;
	}
}



bool Player::damageable()
{
	return timeSinceDamaged.getElapsedTime() > sf::seconds(1.0f);
}

std::string Player::hpString()
{
	return std::to_string(hitpoints);
}

bool Player::attacking()
{
	return space;
}

sf::FloatRect Player::attackPoint()
{
	
	return weapon.getGlobalBounds();
}

void Player::setWeaponLocation()
{
	float attackDistance{32.0f};
	sf::Vector2f point{location.x + (attackDistance * -std::sin(rotation)), location.y + (attackDistance * std::cos(rotation))};
	weapon.setPosition(point);
	weapon.setRotation(rotation * (180 / 3.141592654f) + 180);
}

void Player::draw(sf::RenderWindow &window)
{
	window.draw(sprite);
	if (attacking())
	{
		window.draw(weapon);
	}
}

void Player::setLocation(int x, int y)
{
	location.x = x + 17;
	location.y = y + 17;
	rotation = 0;
	sprite.setPosition(x + 17, y + 17);
}