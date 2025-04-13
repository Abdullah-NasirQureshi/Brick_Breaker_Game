#include "../Brick_Breaker/Menu.h"
#include<SFML/Graphics.hpp>
#include<iostream>



Menu::Menu(sf::RenderWindow& window)
{
	Button_image.loadFromFile("E:\\Projects\\Assets\\button.png");
	Button_sprite.setTexture(MainMenuBackground_texture);
	MainMenuBackground_sprite.setPosition(-20, -30);
	MainMenuBackground_sprite.setScale(0.7f, 0.8f);

	MainMenuBackground_texture.loadFromFile("E:\\Projects\\Assets\\gamebg.jpg");
	MainMenuBackground_sprite.setTexture(MainMenuBackground_texture);
	MainMenuBackground_sprite.setPosition(-20, -30);
	MainMenuBackground_sprite.setScale(0.7f, 0.8f);
	mainMenuButtons[0] = new Button(window, "PLAY GAME", 90, 140, 90, Button_image);
	mainMenuButtons[1] = new Button(window, "SAVED GAME", 515, 140, 80, Button_image);
	mainMenuButtons[2] = new Button(window, "INSTRUCTIONS", 90, 320, 70, Button_image);
	mainMenuButtons[3] = new Button(window, "LEVELS", 515, 320, 90, Button_image);
	mainMenuButtons[4] = new Button(window, "SETTIGS", 90, 500, 90, Button_image);
	mainMenuButtons[5] = new Button(window, "EXIT", 515, 500, 100, Button_image);


	InstructionsBackground_texture.loadFromFile("E:\\Projects\\Assets\\Instructions.png");
	InstructionsBackground_sprite.setTexture(InstructionsBackground_texture);
	InstructionsBackground_sprite.setPosition(-35, 0);
	InstructionsBackground_sprite.setScale(0.9, 0.8);
	InstructionsButtons[0] = new Button(window, "BACK", 30, 560, 100, Button_image);
	InstructionsButtons[1] = new Button(window, "GO TO GAME", 555, 560, 80, Button_image);

	PausePageBackground_texture.loadFromFile("E:\\Projects\\Assets\\gg.jpg");
	PausePageBackground_sprite.setTexture(PausePageBackground_texture);
	PausePageBackground_sprite.setPosition(-5, 0);
	PausePageBackground_sprite.setScale(1.3, 1.2);
	PausePageButtons[0] = new Button(window, "RESUME", 310, 250, 80, Button_image);
	PausePageButtons[1] = new Button(window, "MAIN MENU", 310, 450, 90, Button_image);


	levelBackground_texture.loadFromFile("E:\\Projects\\Assets\\gg.jpg");
	levelBackground_sprite.setTexture(levelBackground_texture);
	levelBackground_sprite.setPosition(-5, 0);
	levelBackground_sprite.setScale(1.3, 1.2);
	levelButton[0] = new Button(window, "LEVEL 01", 170, 100, 80, Button_image);
	levelButton[1] = new Button(window, "LEVEL 02", 480, 200, 80, Button_image);
	levelButton[2] = new Button(window, "LEVEL 03", 170, 300, 80, Button_image);
	levelButton[3] = new Button(window, "LEVEL 04", 480, 400, 80, Button_image);
	levelButton[4] = new Button(window, "LEVEL 05", 170, 500, 80, Button_image);
	levelButton[5] = new Button(window, "BACK", 610, 650, 80, Button_image);
	


	Button_image.loadFromFile("E:\\Projects\\Assets\\buttonsmall.png");
	
	GameButton_texture.loadFromFile("E:\\Projects\\Assets\\buttonsmall.png");
	GameButton_sprite.setTexture(GameButton_texture);
	GameButton_sprite.setScale(0.5, 0.5);
	GameButtons[0] = new Button(window, "PAUSE", 25, 15, 50, Button_image);
	GameButtons[1] = new Button(window, "SAVE & EXIT",770,15, 40, Button_image);

	Button_image.loadFromFile("E:\\Projects\\Assets\\up.png");
	SettingsBackground_texture.loadFromFile("E:\\Projects\\Assets\\bg.jpg");
	SettingsBackground_sprite.setTexture(SettingsBackground_texture);
	SettingsBackground_sprite.setPosition(-5, 0);
	SettingsBackground_sprite.setScale(2.3, 1.9);
	SettingsButton[0]= new Button(window, "", 625, 240, 0, Button_image);

	Button_image.loadFromFile("E:\\Projects\\Assets\\down.png");
	SettingsButton[1]= new Button(window, "", 625, 385, 0, Button_image);

	Button_image.loadFromFile("E:\\Projects\\Assets\\unmute1.png");
	SettingsButton[2]= new Button(window, "", 545, 510, 0, Button_image);

	Button_image.loadFromFile("E:\\Projects\\Assets\\mute1.png");
	SettingsButton[3]= new Button(window, "", 700, 510, 0, Button_image);

	Button_image.loadFromFile("E:\\Projects\\Assets\\settings.png");
	SettingsButton[4]= new Button(window, "", 160, 15, 0, Button_image);

	Button_image.loadFromFile("E:\\Projects\\Assets\\button.png");
	SettingsButton[5] = new Button(window, "BACK", 320, 680, 100, Button_image);


	//TEXT
	font.loadFromFile("E:\\Uni Content\\Semester_02\\OOP\\OOP_Pro\\Fonts\\Jersey10-Regular.ttf");
	text.setString("BALL SPEED:");
	text1.setString("GAME SOUND");
	text.setFont(font);
	text.setFillColor(sf::Color::Black);
	text.setCharacterSize(100);
	text1.setFont(font);
	text1.setFillColor(sf::Color::Black);
	text1.setCharacterSize(100);
	text.setPosition(100, 275);
	text1.setPosition(100, 505);

}

void Menu::drawMainMenu(sf::RenderWindow& window)
{
	window.draw(MainMenuBackground_sprite);
	for (int i = 0; i < 6; i++)
	{
		mainMenuButtons[i]->Draw_button(window);
	}

}

bool Menu::MouseOnAnyButtonMainMenu(sf::RenderWindow& window, int i)
{
	if (mainMenuButtons[i]->MouseInArea(window))
	{
		//cout << "in"<<endl;
		return true;
	}
	return false;
}

void Menu::Highligh_ButtonsMainMenu(int i)
{
	mainMenuButtons[i]->Highlight();
}

void Menu::original_ButtonsMainMenu(int i)
{
	mainMenuButtons[i]->Original();
}



void Menu::drawInstructions(sf::RenderWindow& window)
{
	window.draw(InstructionsBackground_sprite);
	InstructionsButtons[0]->Draw_button(window);
	InstructionsButtons[1]->Draw_button(window);
}

bool Menu::MouseOnAnyButtonInstructions(sf::RenderWindow& window, int i)
{
	if (InstructionsButtons[i]->MouseInArea(window))
	{
		//cout << "in" << endl;
		return true;
	}

	return false;
}

void Menu::Highligh_ButtonsInstructions(int i)
{
	InstructionsButtons[i]->Highlight();
}

void Menu::original_ButtonsInstructions(int i)
{
	InstructionsButtons[i]->Original();
}


void Menu::drawGamePage(sf::RenderWindow& window)
{
	GameButtons[0]->Draw_button(window);
	GameButtons[1]->Draw_button(window);
}
bool Menu::MouseOnAnyGameButton(sf::RenderWindow& window, int i)
{
	if (GameButtons[i]->MouseInArea(window))
	{
		//cout << "in"<<endl;
		return true;
	}
	return false;
}

void Menu::Highligh_GameButton(int i)
{
	GameButtons[i]->Highlight();
}

void Menu::original_GameButton(int i)
{
	GameButtons[i]->Original();
}


void Menu::drawPausePage(sf::RenderWindow& window)
{
	window.draw(PausePageBackground_sprite);
	PausePageButtons[0]->Draw_button(window);
	PausePageButtons[1]->Draw_button(window);
}

bool Menu::MouseOnAnyButtonPausePage(sf::RenderWindow& window, int i)
{
	if (PausePageButtons[i]->MouseInArea(window))
	{
		//cout << "in" << endl;
		return true;
	}

	return false;
}

void Menu::Highligh_ButtonsPausePage(int i)
{
	PausePageButtons[i]->Highlight();
}

void Menu::original_ButtonsPausePage(int i)
{
	PausePageButtons[i]->Original();
}



void Menu::drawSettings(sf::RenderWindow& window)
{
	window.draw(SettingsBackground_sprite);
	window.draw(text);
	window.draw(text1);

	for (int i = 0; i < 6; i++)
	{
		SettingsButton[i]->Draw_button(window);
	}

}

bool Menu::MouseOnAnySettingButton(sf::RenderWindow& window, int i)
{
	if (SettingsButton[i]->MouseInArea(window))
	{
		//cout << "in"<<endl;
		return true;
	}
	return false;
}

void Menu::Highligh_SettingButton(int i)
{
	SettingsButton[i]->Highlight();
}

void Menu::original_SettingButton(int i)
{
	SettingsButton[i]->Original();
}



void Menu::drawlevel(sf::RenderWindow& window)
{
	
	window.draw(levelBackground_sprite);
	for (int i = 0; i < 6; i++)
	{
		levelButton[i]->Draw_button(window);
	}

}

bool Menu::MouseOnAnylevelButton(sf::RenderWindow& window, int i)
{
	if (levelButton[i]->MouseInArea(window))
	{
		//cout << "in"<<endl;
		return true;
	}
	return false;
}

void Menu::Highligh_levelButton(int i)
{
	levelButton[i]->Highlight();
}

void Menu::original_levelButton(int i)
{
	levelButton[i]->Original();
}
