#include "Game.h"
#include <iostream>

Game::Game()
{

    //MENU
    TheMenu = new Menu(window);
    GameState = 1;
    hitPaddle = 0;
    lastHit = 1;
    hitup = 1;
    hitside = 1;
    level = 1;
    lives = 3;

}

void Game::SaveGame()
{
    ofstream savedGame;
    savedGame.open("E:\\Projects\\Brick_Breaker\\SaveGame.txt");
    //cout << "In the file\n";

    savedGame << GameState << endl;
    savedGame << level << endl;

    savedGame << ballSprite.getPosition().x << endl;
    savedGame << ballSprite.getPosition().y << endl;
    savedGame << angle << endl;
    savedGame << speed << endl;


   
    for (i = 0; i < 32; i++)
    {
        savedGame << b[i]->getExistence()<<endl;
        savedGame << b[i]->getHealth()<<endl;
       
    }

    savedGame.close();
}
void Game::RetriveOldData(sf::RenderWindow& window)
{
    ifstream savedGame;
    savedGame.open("E:\\Projects\\Brick_Breaker\\SaveGame.txt");
    std:: cout << "In the file\n";

    int l;
    savedGame >> GameState;
    savedGame >> l;
    level = l;

    float ballX, ballY, ballSpeed;
    int ballAngle;
    int BHealth;
    bool BExist;

    savedGame >> ballX;
    savedGame >> ballY;
    savedGame >> ballAngle;
    savedGame >> ballSpeed;

    ballSprite.setPosition(ballX, ballY);
    angle = ballAngle;
    speed = ballSpeed;

    std::cout << "   " << ballX << "  " << ballY << "  " << ballAngle << "  " << ballSpeed << endl;

    for (i = 0; i < 32; i++)
    {

        savedGame >> BExist;
        savedGame >> BHealth;

        b[i]->setExist(BExist);
        b[i]->setHealth(BHealth);

        b[i]->changeBrick();
    }

    levelUp(level);

}


void Game::SetUpAssets()
{
    //BACKGROUND IMAGE
    background.loadFromFile("E:\\Projects\\Assets\\doodle1.jpg");
    backgroundTexture.loadFromImage(background);
    backgroundSprite.setTexture(backgroundTexture);
    backgroundSprite.setPosition(0, 0);
    Spritecolor = backgroundSprite.getColor();
    Spritecolor.a = 150;  // Set alpha to 128 (50% opacity)
    backgroundSprite.setColor(Spritecolor);


    GAMEOVER.loadFromFile("E:\\Projects\\centi\\Textures\\gameover1.jpg");
    GAMEOVERTexture.loadFromImage(GAMEOVER);
    GAMEOVERSprite.setTexture(GAMEOVERTexture);
    GAMEOVERSprite.setPosition(-30, -70);
    GAMEOVERSprite.setScale(1.1, 1.1);
    GAMEOVERSprite.setColor(sf::Color(255, 255, 255, 255 * 0.6));

    DONE.loadFromFile("E:\\Projects\\Assets\\done.jpg");
    DONETexture.loadFromImage(DONE);
    DONESprite.setTexture(DONETexture);
    DONESprite.setPosition(0, 0);
    DONESprite.setScale(2.5, 3);
    DONESprite.setColor(sf::Color(255, 255, 255, 255 * 0.8));


    //PADDLE IMAGE
    paddle.loadFromFile("E:\\Projects\\Assets\\paddle.png");
    paddleTexture.loadFromImage(paddle);
    paddleSprite.setTexture(paddleTexture);
    paddleSprite.setPosition(300, 700);
    paddleSprite.setScale(0.8, 0.3);
    paddlePartLength = (paddleSprite.getGlobalBounds().width - (paddleSprite.getGlobalBounds().width / 4)) / 5;
    lastHit = 6;

    //SOUND
    soundBuffer.loadFromFile("E:\\Projects\\Assets\\Oggy - Ending.mp3");
    sound.setBuffer(soundBuffer);
    sound.setLoop(true);
    sound.play();
    isMuted = 0;

    //BALL
    ball.loadFromFile("E:\\Projects\\Assets\\ball.png");
    ballTexture.loadFromImage(ball);
    ballSprite.setTexture(ballTexture);
    ballSprite.setPosition(400, 700);
    ballSprite.setScale(0.1, 0.1);
    angle = 60;
    angleRad = 0;
    speed = 3.5;
    ss << std::fixed << std::setprecision(1) << speed;
    formattedSpeed = ss.str();
    lives = 6;
    gameOver = false;
    i = 0;// iterator
    fallen = false;

    //BRICKS
    for (i = 0; i < 8; i++)
    {
       // if (i % 2 == 0)
        {
            b[i] = new Brick(i * 130 - 20, 100, 4);
            b[i + 8] = new Brick(i * 130 - 20, 150, 3);
            b[i + 16] = new Brick(i * 130 - 20, 200, 2);
            b[i + 24] = new Brick(i * 130 - 20, 250, 1);
        }
    }
   

   // b[p++] = new Brick(i * 130 - 20, 650, 1);
   
    
    
    
   
    //TEXT 
    font.loadFromFile("E:\\Uni Content\\Semester_02\\OOP\\OOP_Pro\\Fonts\\Jersey10-Regular.ttf");
    text.setString("LEVEL 0"+ std::to_string(level));
    text.setFont(font);
    text.setFillColor(sf::Color::White);
    text.setCharacterSize(80);
    text.setPosition(400, -10);

    text1.setString(formattedSpeed);
    text1.setFont(font);
    text1.setFillColor(sf::Color::Black);
    text1.setCharacterSize(90);
    text1.setPosition(645, 290);

    text2.setString("LIVES: "+ std::to_string(lives));
    text2.setFont(font);
    text2.setFillColor(sf::Color::White);
    text2.setCharacterSize(70);
    text2.setPosition(770, 770);

   
}

//void Game::reflectFromSides(int& angle)
//{
//    angle += 90;
//}

void Game::moveBall(sf::Clock& clock)
{

    if (clock.getElapsedTime().asMilliseconds() < 0.1)
        return;

    clock.restart();
    
   
    // Convert the angle to radians
    if (angleRad != angle * (3.14159265f / 180.0f))
    {
        angleRad = angle * (3.14159265f / 180.0f);
        std::cout << "Angle : " << angle << std::endl;

        // Calculate the velocity components
        velocityX = speed*std::cos(angleRad);
        velocityY = speed*std::sin(angleRad);
    }

    

    // Update the object's position
    position = ballSprite.getPosition();
      
    position.x += velocityX;
    position.y -= velocityY;

    ballSprite.setPosition(position);
}
void Game::updateGame(sf::RenderWindow& window, sf::Clock& clock)
{
    if (GameState == 1)
        TheMenu->drawMainMenu(window);
    else if (GameState == 2)
        TheMenu->drawInstructions(window);
    else if (GameState == 3)
        TheMenu->drawPausePage(window);
    else if (GameState == 6)
        TheMenu->drawlevel(window);
    else if (GameState == 5)
    {
        TheMenu->drawSettings(window);
        text1.setString(formattedSpeed);
        window.draw(text1);
    }
    else if (GameState == 4)
    {

        if (ballSprite.getPosition().y > 700 && ballSprite.getPosition().y < 720 && ballSprite.getPosition().x > paddleSprite.getPosition().x - 20 && ballSprite.getPosition().x < paddleSprite.getPosition().x + paddleSprite.getLocalBounds().width)
        {
            for (i = 0; i < 5; i++)
            {
                if (ballSprite.getPosition().x > paddleSprite.getPosition().x + (paddlePartLength * i) && ballSprite.getPosition().x < paddleSprite.getPosition().x + (paddlePartLength * (i + 1)))
                {
                    lastHit = i + 1;
                    std::cout << "true: " << lastHit << std::endl;
                }
            }
            angle = 180 - angle;
            //std::cout << "angle at 1 : " << angle << std::endl;
            hitPaddle = 1;
        }



        if (hitPaddle)
        {
            //std::cout << "in hittt\n";
            switch (lastHit)
            {
            case 5:
                angle = 30;// Angle when ball touches edge
                break;
            case 4:
                angle = 60;// Angle when ball touches near edge
                break;
            case 3:
                angle = 90;// Angle when ball touches near mid
                break;
            case 2:
                angle = 120;// Angle when ball touches mid
                break;
            case 1:
                angle = 150;// Angle when ball touches near mid
                break;

            }

            hitPaddle = 0;
        }

        if (ballSprite.getPosition().x < 945 && ballSprite.getPosition().x > -5)
            hitside = 1;

        if (ballSprite.getPosition().y <710 && ballSprite.getPosition().y > 5)
            hitup = 1;

        if (hitside && (ballSprite.getPosition().x > 950 || ballSprite.getPosition().x < -10))
        {
            std::cout << "inn update\n";
            angle = 180 - angle;
            hitside = 0;
        }

        if (hitup && ballSprite.getPosition().y <= 0)
        {
            std::cout << "inn up\n";
            //angle = 180 - angle;
            angle = -angle;
            hitup = 0;
        }


        //if (ballSprite.getPosition().y < 500)
        {
            for (i = 0; i < 32; i++)
            {
                if (b[i] != NULL && b[i]->getExistence() == true)
                {
                    if ((ballSprite.getPosition().x > b[i]->get_x() - 20 && ballSprite.getPosition().x < b[i]->get_x() + 110) && (((ballSprite.getPosition().y < b[i]->get_y() + 50 && ballSprite.getPosition().y > b[i]->get_y() + 45 && (angle > 0 && angle < 180))) || (ballSprite.getPosition().y > b[i]->get_y() - 40 && ballSprite.getPosition().y < b[i]->get_y() - 30 && ((angle < 0 && angle>-180) || (angle > 180 && angle < 360)))))
                    {
                                                                      
                        b[i]->setHealth(b[i]->getHealth() - 1);
                        std::cout << "touched up\n";
                        //angle = 180 - angle;
                        angle = -angle;

                        std::cout << "brick x: " << b[i]->get_x() << std::endl;
                        std::cout << "brick y: " << b[i]->get_y() << std::endl;

                        if (b[i] != NULL && b[i]->getHealth() == 0)
                        {
                            b[i]->setExist(0);
                        }

                        if (b[i] != NULL && b[i]->getExistence())
                        {
                            b[i]->changeBrick();
                        }
                        break;
                       
                    }

                    else if (((ballSprite.getPosition().x > b[i]->get_x() - 45 && ballSprite.getPosition().x < b[i]->get_x() - 35 && ((angle<90 && angle>-90) || (angle > 270 && angle < 360))) || (ballSprite.getPosition().x > b[i]->get_x() + 125 && ballSprite.getPosition().x < b[i]->get_x() + 130) && ((angle > 90 && angle < 270) || (angle<-90 && angle>-270))) && ballSprite.getPosition().y < b[i]->get_y() + 50 && ballSprite.getPosition().y > b[i]->get_y() - 20)
                    {
                        if (b[i] != NULL && b[i]->getHealth() != 0)
                        {
                            b[i]->setHealth(b[i]->getHealth() - 1);
                            std::cout << "touched side\n";
                            //angle = 180 - angle;
                            angle = 180 - angle;

                            std::cout << "brick x: " << b[i]->get_x() << std::endl;
                            std::cout << "brick y: " << b[i]->get_y() << std::endl;

                            if (b[i] != NULL && b[i]->getHealth() == 0)
                            {
                                b[i]->setExist(0);
                            }

                            if (b[i] != NULL && b[i]->getExistence())
                            {
                                b[i]->changeBrick();
                            }
                            break;

                            break;
                        }
                    }
                }
            }
        }

        posX = sf::Mouse::getPosition(window).x;

        if (posX < 0)
        {
            posX = 0;
        }
        else if (posX > 1000)
        {
            posX = 1000;
        }
        paddleSprite.setPosition(posX - (paddleSprite.getPosition().x + paddleSprite.getLocalBounds().width) / 4, 700);

        //Checking if the ball has fallen
        if (ballSprite.getPosition().y > 1600)
        {
            fallen = true;
        }

        if (fallen && lives>0)
        {
            ballSprite.setPosition(400, 700);
            lives--;
            fallen = false;
            angle = 150;
            text2.setString("LIVES: " + std::to_string(lives));

            if (lives == 0)
            {
                gameOver = true;
            }
        }


        window.draw(backgroundSprite);
        if (GameState == 4)
        {
            TheMenu->drawGamePage(window);
        }

        window.draw(paddleSprite);
        window.draw(ballSprite);
        window.draw(text);
        window.draw(text2);
        

        for (i = 0; i < 32; i++)
        {
            if (b[i]!=NULL && b[i]->getExistence())
                b[i]->drawBricks(window);

        }

        if (gameOver)
            window.draw(GAMEOVERSprite);


        checkBricks();

        if (level > 5)
        {
            window.draw(DONESprite);
        }
    }
}

void Game::runGame()
{

    SetUpAssets();

    // Create a window with a title and size
    sf::RenderWindow window(sf::VideoMode(1000, 850), "SFML Window");

    // Create a clock to manage time



    // Main loop
    while (window.isOpen()) {
        // Process events

        while (window.pollEvent(event)) {

            switch (event.type)
            {
                case (sf::Event::Closed):
                {
                    window.close();
                    break;
                }
                case (sf::Event::KeyPressed):
                {
                    if (event.key.code == sf::Keyboard::Escape) {
                        window.close();
                    }
                }
                case (sf::Event::MouseMoved):
                    for (i = 0; i < 6; i++)
                    {
         
                        if (TheMenu->MouseOnAnyButtonMainMenu(window,i))
                        {
                            TheMenu->Highligh_ButtonsMainMenu(i);
                        }
                        if (!TheMenu->MouseOnAnyButtonMainMenu(window, i))
                            TheMenu->original_ButtonsMainMenu(i);


                    }

                    for (i = 0; i < 2; i++)
                    {

                        if (TheMenu->MouseOnAnyGameButton(window, i))
                        {
                            TheMenu->Highligh_GameButton(i);
                        }
                        if (!TheMenu->MouseOnAnyGameButton(window, i))
                            TheMenu->original_GameButton(i);


                    }

                    for (i = 0; i < 2; i++)
                    {
                        if (TheMenu->MouseOnAnyButtonPausePage(window, i))
                        {
                            TheMenu->Highligh_ButtonsPausePage(i);
                        }
                        if (!TheMenu->MouseOnAnyButtonPausePage(window, i))
                            TheMenu->original_ButtonsPausePage(i);
                    }
                    for (i = 0; i < 2; i++)
                    {
                        if (TheMenu->MouseOnAnyButtonInstructions(window, i))
                            TheMenu->Highligh_ButtonsInstructions(i);

                        if (!TheMenu->MouseOnAnyButtonInstructions(window, i))
                            TheMenu->original_ButtonsInstructions(i);
                        
                    }

                    for (i = 0; i < 6; i++)
                    {
                        if (TheMenu->MouseOnAnySettingButton(window, i))
                            TheMenu->Highligh_SettingButton(i);

                        if (!TheMenu->MouseOnAnySettingButton(window, i))
                            TheMenu->original_SettingButton(i);

                        if (TheMenu->MouseOnAnylevelButton(window, i))
                            TheMenu->Highligh_levelButton(i);

                        if (!TheMenu->MouseOnAnylevelButton(window, i))
                            TheMenu->original_levelButton(i);

                    }



                    //playerInventory[0]->MouseOnAnyItem(window);
                    break;

                case (sf::Event::MouseButtonPressed):
                {
                    if (TheMenu->MouseOnAnyButtonMainMenu(window, 0) && GameState == 1)
                    {
                        GameState = 4;
                    }
                    else if (TheMenu->MouseOnAnyButtonMainMenu(window, 1) && GameState == 1)
                    {
                        RetriveOldData(window);
                    }
                    else if (TheMenu->MouseOnAnyButtonMainMenu(window, 2) && GameState == 1)
                    {
                        GameState = 2;
                    }
                    else if (TheMenu->MouseOnAnyButtonMainMenu(window, 3) && GameState == 1)
                    {
                        GameState = 6;
                    }
                 
                    else if (TheMenu->MouseOnAnyButtonMainMenu(window, 4) && GameState == 1)
                    {
                        GameState = 5;
                        //window.close();
                    }
                    else if (TheMenu->MouseOnAnyButtonMainMenu(window, 5) && GameState == 1)
                    {
                        window.close();
                    }
                    else if (TheMenu->MouseOnAnyButtonInstructions(window, 0) && GameState == 2)
                    {
                        GameState = 1;
                    }
                    else if (TheMenu->MouseOnAnyButtonInstructions(window, 1) && GameState == 2)
                    {
                        GameState = 4;
                    }
                    else if (TheMenu->MouseOnAnyButtonPausePage(window, 0) && GameState == 3)
                    {
                        GameState = 4;
                    }
                    else if (TheMenu->MouseOnAnyButtonPausePage(window, 1) && GameState == 3)
                    {
                        GameState = 1;
                    }
                    else if (GameState == 4 && TheMenu->MouseOnAnyGameButton(window, 0))
                    {
                        GameState = 3;
                    }
                    else if (GameState == 4 && TheMenu->MouseOnAnyGameButton(window, 1))
                    {
                        std::cout << "GAME SAVED";
                        SaveGame();
                        window.close();
                    }
                    else if (GameState == 5 && TheMenu->MouseOnAnySettingButton(window, 0))
                    {
                        if (speed < 5)
                        {
                           
                            speed += 0.5;
                            std::cout << "INC++: " << speed << endl;
                            // Clear stringstream for reuse
                            ss.str("");
                            ss << std::fixed << std::setprecision(1) << speed;
                            formattedSpeed = ss.str();
                        }
                    }
                    else if (GameState == 5 && TheMenu->MouseOnAnySettingButton(window, 1))
                    {
                        if (speed > 1)
                        {
                            speed -= 0.5;
                            std::cout << "DE--: " << speed << endl;
                            // Clear stringstream for reuse
                            ss.str("");
                            ss << std::fixed << std::setprecision(1) << speed;
                            formattedSpeed = ss.str();

                        }
                    }
                    else if (GameState == 5 && TheMenu->MouseOnAnySettingButton(window, 2))
                    {
                        if (isMuted)
                        {
                            sound.setVolume(100);
                            isMuted = 0;
                        }
                    }
                    else if (GameState == 5 && TheMenu->MouseOnAnySettingButton(window, 3))
                    {
                        if (!isMuted)
                        {
                            sound.setVolume(0);
                            isMuted = 1;
                        }
                    }
                    else if (GameState == 5 && TheMenu->MouseOnAnySettingButton(window, 5))
                    {
                        GameState = 1;
                    }
                    else if (GameState == 6 && TheMenu->MouseOnAnySettingButton(window, 0))
                    {

                        level = 1;
                        levelUp(1);
                        GameState = 4;
                        
                    }
                    else if (GameState == 6 && TheMenu->MouseOnAnySettingButton(window, 1))
                    {
                        level = 2;
                        levelUp(2);
                        GameState = 4;
                    }
                    else if (GameState == 6 && TheMenu->MouseOnAnySettingButton(window, 2))
                    {
                        level = 3;
                        levelUp(3);
                        GameState = 4;
                    }
                    else if (GameState == 6 && TheMenu->MouseOnAnySettingButton(window, 3))
                    {
                        level = 4;
                        levelUp(4);
                        GameState = 4;
                    }
                    else if (GameState == 6 && TheMenu->MouseOnAnySettingButton(window, 4))
                    {
                        level = 5;
                        levelUp(5);
                        GameState = 4;
                    
                    }
                    else if (GameState == 6 && TheMenu->MouseOnAnySettingButton(window, 5))
                    {
                        GameState = 1;
                    }
                  

                    break;
                }
            }
        }

       
        // Clear the window with a black color
        window.clear(sf::Color::Black);
        updateGame(window, clock);
        if (GameState == 4 && !gameOver && level<6)
            moveBall(clock);

        window.display();

    }
}


void Game::checkBricks()
{
    BrickBroken = 1;
    if (level < 6)
    {
        for (i = 0; i < 32; i++)
        {
            if (b[i] != NULL)
            {
                if (b[i]->getExistence() == true)
                {
                    BrickBroken = 0;
                    break;
                }
            }
        }


        if (BrickBroken && level < 6)
            levelUp(++level);
        //if(level>5)
    }
  
}


void Game::levelUp(int l)
{
    int p = 0;
    level=l;

    if (b[0] != NULL)
    {
        for (i = 0; i < 32; i++) {
            delete b[i];
            b[i] = nullptr;
        }
    }
   /* for (i = 0; i < 32;i++)
    {
        b[i]->setExist(0);
    }
    delete[] b;*/

    //BRICKS
    int q = 0;
    int tt = 100;

    if(level==2)
    {
            for (i = 0; i < 16; i++)
            {
                if (q > 7)
                    q = 0;

                if (i % 2 == 0)
                {
                    b[p] = new Brick(q * 130 - 20, tt, 4);
                    b[8 + p] = new Brick(q * 130 - 20, tt + 50, 3);
                    b[16 + p] = new Brick(q * 130 - 20, tt + 100, 2);
                    b[24 + p++] = new Brick(q * 130 - 20, tt + 150, 1);
                    q += 2;
                    tt += 50;
                }
            }
    }

    else if(level==3)
    {
            for (i = 0; i < 8; i++)
            {
                if (i % 2 == 0)
                {
                    b[p] = new Brick(i * 130 - 20, 100, 4);
                    b[p + 8] = new Brick(i * 130 - 20, 200, 3);
                    b[p + 16] = new Brick(i * 130 - 20, 300, 2);
                    b[p++ + 24] = new Brick(i * 130 - 20, 400, 1);
                }
                else if (i % 2 != 0)
                {
                    b[p] = new Brick(i * 130 - 20, 150, 4);
                    b[p + 8] = new Brick(i * 130 - 20, 250, 3);
                    b[p + 16] = new Brick(i * 130 - 20, 350, 2);
                    b[p++ + 24] = new Brick(i * 130 - 20, 450, 1);
                }
            }
    }

    else if (level == 4)
    {
        for (i = 0; i < 8; i++)
        {
            // if (i % 2 == 0)
            {
                b[p++] = new Brick(i * 130 - 20, 100, 4);
                b[p++] = new Brick(i * 130 - 20, 350, 4);
            }
            if (i > 1 && i < 6)
            {
                b[p++] = new Brick(i * 130 - 20, 150, 1);
                b[p++] = new Brick(i * 130 - 20, 200, 2);
                b[p++] = new Brick(i * 130 - 20, 250, 2);
                b[p++] = new Brick(i * 130 - 20, 300, 3);
            }
        }
    }

    else if (level == 5)
    {
        for (int i = 6; i > 0; i--)
        {
            if (i > 5)
                b[p++] = new Brick(i * 130 - 20, 100, 4);
            if (i > 4)
                b[p++] = new Brick(i * 130 - 20, 150, 4);
            if (i > 3)
                b[p++] = new Brick(i * 130 - 20, 200, 4);
            if (i > 2)
                b[p++] = new Brick(i * 130 - 20, 250, 3);
            if (i > 1)
                b[p++] = new Brick(i * 130 - 20, 300, 2);
            if (i >= 0)
                b[p++] = new Brick(i * 130 - 20, 350, 1);
        }
        for (int i = 4; i > 0; i--)
        {

            if (i > 3)
                b[p++] = new Brick(i * 130 - 20 + 130, 400, 4);
            if (i > 2)
                b[p++] = new Brick(i * 130 - 20 + 130, 450, 3);
            if (i > 1)
                b[p++] = new Brick(i * 130 - 20 + 130, 500, 2);
            if (i >= 0)
                b[p++] = new Brick(i * 130 - 20 + 130, 550, 1);
        }

        b[p++] = new Brick(4 * 130 - 20 + 130, 400, 1);
    }

   

    ballSprite.setPosition(400, 700);
    text.setString("LEVEL 0" + std::to_string(level));
   
   

}


Game::~Game()
{
    for (i = 0; i < 27; i++)
    {
        if (b[i] != nullptr)
            delete b[i];
    }
}