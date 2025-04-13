
#include "Button.h"
#include<SFML/Graphics.hpp>
#include<iostream>
//#include "../OOP_Pro/Game.cpp"
//using namespace std;



Button::Button()
{
	/*sf::Text text;
	sf::Image button_pic;
	sf::Texture button_texture;
	sf::Sprite button_sprite;
	int X_position;
	int Y_position;
	int length;
	int width;*/

	text.setString("  ");
	text.setFillColor(sf::Color::Black);
	text.setCharacterSize(10);
	button_sprite.setPosition(50, 50);
	button_texture.loadFromFile("E:\\Uni Content\\Semester_02\\OOP\\OOP_Pro\\Images\\onebutton.png");
	button_sprite.setTexture(button_texture);
	//button_sprite.setTextureRect(sf::IntRect(0, 0, boxPixelsX, boxPixelsY));

}

Button::Button(sf::RenderWindow& window, string text, int X_position, int Y_position, int text_size, const sf::Image& image)
{

	font.loadFromFile("E:\\Uni Content\\Semester_02\\OOP\\OOP_Pro\\Fonts\\Jersey10-Regular.ttf");
	this->text.setString(text);
	button_sprite.setPosition(50, 50);
	button_sprite.setPosition(X_position, Y_position);
	button_texture.loadFromImage(image);
	button_sprite.setTexture(button_texture);
	this->text.setFont(font);
	this->text.setFillColor(sf::Color::Black);
	this->text.setCharacterSize(text_size);
	float textX = X_position + (button_sprite.getLocalBounds().width - this->text.getLocalBounds().width) / 2;
	float textY = Y_position + (button_sprite.getLocalBounds().height - this->text.getLocalBounds().height) / 2 - this->text.getLocalBounds().top;
	this->text.setPosition(textX, textY);

}

int Button::getX_position() const {
	return X_position;
}

int Button::getY_position() const {
	return Y_position;
}

// Setters
void Button::setX_position(int x) {
	X_position = x;
}

void Button::setY_position(int y) {
	Y_position = y;
}

bool Button::MouseInArea(sf::RenderWindow& window)
{
	float posX = sf::Mouse::getPosition(window).x;
	float posY = sf::Mouse::getPosition(window).y;
	//cout << "X	"<<posX << "	Y	"<<posY<<endl;

	float buttonX = button_sprite.getPosition().x;
	float buttonY = button_sprite.getPosition().y;
	//cout << "X	" << buttonX << "	Y	" << buttonY << endl<<endl;
	float buttonLimitX = button_sprite.getPosition().x + button_sprite.getLocalBounds().width;
	float buttonLimitY = button_sprite.getPosition().y + button_sprite.getLocalBounds().height;
	//cout << "X	" << buttonLimitX << "	Y	" << buttonLimitY << endl;
	if (posX < buttonLimitX && posX>buttonX && posY < buttonLimitY && posY > buttonY)
	{
		//cout << "ON BUTTON\n";
		return true;
	}
	return false;
}

void Button::Draw_button(sf::RenderWindow& window)
{
	window.draw(button_sprite);
	window.draw(this->text);
}

void Button::Highlight()
{
	//button_sprite.setScale(1.2f, 1.2f);
	button_sprite.setColor(sf::Color(200, 200, 200));
}

void Button::Original()
{
	//button_sprite.setScale(1.2f, 1.2f);
	button_sprite.setColor(sf::Color::White);
	//button_texture.loadFromFile("E:\\Uni Content\\Semester_02\\OOP\\OOP_Pro\\Images\\button.jpg");
}

void Button::shrinkSize(int p, int q)
{
	button_sprite.setScale(p, q);
}