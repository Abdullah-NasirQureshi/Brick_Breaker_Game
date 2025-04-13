#pragma once
#include <SFML/Graphics.hpp>
#include<SFML/Audio.hpp>


class Brick
{
	bool exist;
	int health;
	
	sf::Image brick;
	sf::Texture brickTexture;
	sf::Sprite brickSprite;

public:
	bool change;
	Brick();
	Brick(int xpos, int ypos, int strength);
	void drawBricks(sf::RenderWindow& window);
	int get_x();
	int get_y();
	int getLocalBounds_w();
	int getLocalBounds_h();
	bool getExistence();
	void setExist(bool e);
	int getHealth();
	void setHealth(int i);
	void changeBrick();
};

