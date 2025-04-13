#include "Brick.h"

Brick::Brick()
{
	exist = 1;
	health = 0;
	brick.loadFromFile("E:\\Projects\\Assets\\brick-orange1.png");
	brickTexture.loadFromImage(brick);
	brickSprite.setTexture(brickTexture);
	brickSprite.setPosition(0, 0);
}

Brick::Brick(int xpos, int ypos, int strength)
{
	exist = 1;
	health = strength;
	switch (health)
	{
		case 1:
			brick.loadFromFile("E:\\Projects\\Assets\\tileb.png");
			break;
		case 2:
			brick.loadFromFile("E:\\Projects\\Assets\\tile_bl.png");
			break;
		case 3:
			brick.loadFromFile("E:\\Projects\\Assets\\tile.png");
			break;
		case 4:
			brick.loadFromFile("E:\\Projects\\Assets\\tileg.png");
			break;

	}
	
	brickTexture.loadFromImage(brick);
	brickSprite.setTexture(brickTexture);
	brickSprite.setPosition(xpos, ypos);
	brickSprite.setScale(0.13f, 0.1f);
}


void Brick::drawBricks(sf::RenderWindow& window)
{
	window.draw(brickSprite);
}

int Brick::get_x()
{
	return brickSprite.getPosition().x;
}
int Brick::get_y()
{
	return brickSprite.getPosition().y;
}

int Brick::getLocalBounds_w()
{
	return brickSprite.getLocalBounds().width;
}
int Brick::getLocalBounds_h()
{
	return brickSprite.getLocalBounds().height;
}

bool Brick::getExistence()
{
	return exist;
}

void Brick::setExist(bool e)
{
	exist = e;
}

void Brick::setHealth(int i)
{
	health = i;
}

int Brick::getHealth()
{
	return health;
}

void Brick::changeBrick()
{
switch (health)
	{
	case 1:
		brick.loadFromFile("E:\\Projects\\Assets\\tileb.png");
		break;
	case 2:
		brick.loadFromFile("E:\\Projects\\Assets\\tile_bl.png");
		break;
	case 3:
		brick.loadFromFile("E:\\Projects\\Assets\\tile.png");
		break;
	case 4:
		brick.loadFromFile("E:\\Projects\\Assets\\tileg.png");
		break;

	}

brickTexture.loadFromImage(brick);
brickSprite.setTexture(brickTexture);
//brickSprite.setPosition(xpos, ypos);
brickSprite.setScale(0.13f, 0.1f);
}