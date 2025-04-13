#ifndef BUTTON_H
#define BUTTON_H
#pragma once

#include<SFML/Graphics.hpp>
using namespace std;

class Button
{
	sf::Text text;
	sf::Font font;
	sf::Texture button_texture;
	sf::Sprite button_sprite;
	int X_position;
	int Y_position;


public:

	Button();
	Button(sf::RenderWindow& window, string text, int X_position, int Y_position, int text_size, const sf::Image& image);
	bool MouseInArea(sf::RenderWindow& window);
	int getX_position() const;
	int getY_position() const;

	// Setters
	void setX_position(int x);
	void setY_position(int y);
	void Draw_button(sf::RenderWindow& window);
	void Highlight();
	void Original();
	void shrinkSize(int p,int q);
};
#endif