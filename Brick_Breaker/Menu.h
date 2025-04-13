#pragma once

#include "Button.h"
#include<SFML/Graphics.hpp>


class Menu
{
	sf::Text text;
	sf::Text text1;
	sf::Font font;

	sf::Image Button_image;
	sf::Texture Button_texture;
	sf::Sprite Button_sprite;

	Button* mainMenuButtons[6];
	sf::Texture MainMenuBackground_texture;
	sf::Sprite MainMenuBackground_sprite;

	Button* InstructionsButtons[2];
	sf::Texture InstructionsBackground_texture;
	sf::Sprite InstructionsBackground_sprite;

	Button* PausePageButtons[2];
	sf::Texture PausePageBackground_texture;
	sf::Sprite PausePageBackground_sprite;

	Button* GameButtons[2];
	sf::Texture GameButton_texture;
	sf::Sprite GameButton_sprite;

	Button* SettingsButton[6];
	sf::Texture SettingsBackground_texture;
	sf::Sprite SettingsBackground_sprite;

	Button* levelButton[6];
	sf::Texture levelBackground_texture;
	sf::Sprite levelBackground_sprite;

public:
	Menu(sf::RenderWindow& window);

	void drawMainMenu(sf::RenderWindow& window);
	bool MouseOnAnyButtonMainMenu(sf::RenderWindow& window, int i);
	void Highligh_ButtonsMainMenu(int i);
	void original_ButtonsMainMenu(int i);

	void drawInstructions(sf::RenderWindow& window);
	bool MouseOnAnyButtonInstructions(sf::RenderWindow& window, int i);
	void Highligh_ButtonsInstructions(int i);
	void original_ButtonsInstructions(int i);

	void drawPausePage(sf::RenderWindow& window);
	bool MouseOnAnyButtonPausePage(sf::RenderWindow& window, int i);
	void Highligh_ButtonsPausePage(int i);
	void original_ButtonsPausePage(int i);

	void drawGamePage(sf::RenderWindow& window);
	bool MouseOnAnyGameButton(sf::RenderWindow& window, int i);
	void Highligh_GameButton(int i);
	void original_GameButton(int i);


	void drawSettings(sf::RenderWindow& window);
	bool MouseOnAnySettingButton(sf::RenderWindow& window, int i);
	void Highligh_SettingButton(int i);
	void original_SettingButton(int i);

	void drawlevel(sf::RenderWindow& window);
	bool MouseOnAnylevelButton(sf::RenderWindow& window, int i);
	void Highligh_levelButton(int i);
	void original_levelButton(int i);


};
