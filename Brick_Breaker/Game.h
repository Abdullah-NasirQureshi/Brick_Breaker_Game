#pragma once
#include <SFML/Graphics.hpp>
#include<SFML/Audio.hpp>
#include<fstream>
#include<sstream>
#include <iomanip>

#include"../Brick_Breaker/Button.h"
#include "../Brick_Breaker/Menu.h"
#include "../Brick_Breaker/Brick.h"
#include <iostream>
class Game
{
	sf::Event event;
	sf::RenderWindow window;
	sf::Image background;
	sf::Texture backgroundTexture;
	sf::Sprite backgroundSprite;
	sf::Image paddle;
	sf::Texture paddleTexture;
	sf::Sprite paddleSprite;

	sf::Image GAMEOVER;
	sf::Texture GAMEOVERTexture;
	sf::Sprite GAMEOVERSprite;
	
	sf::Image DONE;
	sf::Texture DONETexture;
	sf::Sprite DONESprite;

	/*Button* button[2];
	sf::Image Button_image;*/

	Brick* b[50];
	Menu* TheMenu;

	sf::Color Spritecolor;
	sf::SoundBuffer soundBuffer;
	sf::Sound sound;
	sf::Image ball;
	sf::Texture ballTexture;
	sf::Sprite ballSprite;
	sf::Clock clock;
	sf::Vector2f position; // position of ball
	sf::Text text;
	sf::Text text1;
	sf::Text text2;
	sf::Font font;


	std::stringstream ss;

	int level;
	bool isMuted;
	int lives;
	bool fallen; // used to check if th eball has fallen
	bool gameOver; // checks if the game is over
	bool hitPaddle;
	float velocityX;
	float velocityY;
	int i; // iterator
	bool hitside;
	bool hitup;
	float posX; //position of mouse
	//float posY; //position of mouse
	int GameState;
	bool saved;//tells if saved game is being executed
	int paddlePartLength;// there are 7 parts of paddle and the angle with which the ball reflects depends upon the part... it is like -60 degrees, -45 degrees, -30 degrees and 0 degrees and 30, 45 and 60 
	int lastHit; // it is used to check the last part of paddle that was hit by the ball, 1 for -60 degrees, 2 for -45 degrees, 3 for -30 degrees, 4 for 0 degrees, 5 for 30 degrees, 6 for 45 degrees and 7 for 60 degrees
	float angle; //angle of ball
	float angleRad; // angle converted to radians
	float speed; //speed pf ball
	std::string formattedSpeed;
	bool BrickBroken;//used in CheckBricks funtion
	

	public:
	Game();
	~Game();
	void SaveGame();
	void RetriveOldData(sf::RenderWindow& window);
	void updateGame(sf::RenderWindow& window, sf::Clock& clock);
	void moveBall(sf::Clock& clock);
	void SetUpAssets();
	void runGame();
	void checkBricks();//checks if all bricks are broken and calls level up function
	void levelUp(int l);
	/*void reflectFromSides(int& angle);*/
};

