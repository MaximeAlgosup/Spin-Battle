#include <iostream>
#include "display.hpp"

#define FONT_PATH "../Src/assets/fonts/LoveDays-2v7Oe.ttf"


void displayMenu(sf::RenderWindow *window, Menu *menu){
    // Set background color
    sf::Texture BackgroundTexture;
    sf::Sprite background;
    
    if(!BackgroundTexture.loadFromFile(menu->getBackgroundPath())){
      exit(EXIT_FAILURE);
    }
    else
    {
      background.setTexture(BackgroundTexture);
    }
    window->draw(background);
}

void displayMenuText(sf::RenderWindow *window, Menu *menu){
    // create a text
    sf::Font font;
    if(!font.loadFromFile(menu->getFontPath())){
        std::cerr << "Error loading font" << std::endl;
        exit(EXIT_FAILURE);
    }
    sf::Text text;
    text.setFont(font);
    text.setString(menu->getTitle());
    text.setCharacterSize(70);
    text.setFillColor(menu->getFontColor());
    text.setPosition(window->getSize().x/2-300, 100);
    window->draw(text);
}

void displaySelectOption(sf::RenderWindow *window, char* text, int x, int y, Menu *menu){
    // create rectangle
    sf::RectangleShape rectangle(sf::Vector2f(400, 100));
    rectangle.setFillColor(menu->getFontColor());
    rectangle.setOutlineColor(sf::Color::White);
    rectangle.setOutlineThickness(5);
    rectangle.setPosition(x, y);
    window->draw(rectangle);
    // create a text
    sf::Font font;
    if(!font.loadFromFile(menu->getFontPath())){
        std::cerr << "Error loading font" << std::endl;
        exit(EXIT_FAILURE);
    }
    sf::Text option;
    option.setFont(font);
    option.setString(text);
    option.setCharacterSize(70);
    option.setFillColor(sf::Color::White);
    option.setPosition(x+10, y+10);
    window->draw(option);
}

void displayMenuCursor(sf::RenderWindow *window, SelectMenu *menu, int x, int y, char* cursorSpritePath){
    // create a circle
    sf::CircleShape circle(50);
    sf::Texture texture;
    if (!texture.loadFromFile(cursorSpritePath)){
        exit(EXIT_FAILURE);
    }
    else{
        circle.setTexture(&texture);
    }
    circle.rotate(menu->getCursorRotation()-167.f);
    circle.setOrigin(50, 50);
    circle.setPosition(x+350, y+50);
    // draw the circle
    window->draw(circle);
    menu->setCursorRotation(menu->getCursorRotation()+30.f);
}

void displaySetting(sf::RenderWindow *window, Setting *setting){
    // Set background color
    sf::Texture BackgroundTexture;
    sf::Sprite background;
    
    if(!BackgroundTexture.loadFromFile(setting->getBackgroundPath())){
      exit(EXIT_FAILURE);
    }
    else
    {
      background.setTexture(BackgroundTexture);
    }
    // create a text
    sf::Font font;
    if(!font.loadFromFile(setting->getFontPath())){
        std::cerr << "Error loading font" << std::endl;
        exit(EXIT_FAILURE);
    }
    sf::Text text;
    text.setFont(font);
    text.setString("Settings");
    text.setCharacterSize(100);
    text.setFillColor(setting->getFontColor());
    text.setPosition(window->getSize().x/2-180, 30);

    sf::Text esc;
    esc.setFont(font);
    esc.setString("->esc");
    esc.setCharacterSize(70);
    esc.setFillColor(sf::Color::White);
    esc.setPosition(window->getSize().x-300, window->getSize().y-140);
    
    // draw
    window->draw(background);
    window->draw(text);
    window->draw(esc);
}

void displaySettingOption(sf::RenderWindow *window, Setting *setting, char* text, int x, int y){
    // create rectangle
    sf::RectangleShape rectangle(sf::Vector2f(400, 100));
    rectangle.setFillColor(setting->getFontColor());
    rectangle.setOutlineColor(sf::Color::White);
    rectangle.setOutlineThickness(5);
    rectangle.setPosition(x, y);
    window->draw(rectangle);
    // create a text
    sf::Font font;
    if(!font.loadFromFile(setting->getFontPath())){
        std::cerr << "Error loading font" << std::endl;
        exit(EXIT_FAILURE);
    }
    sf::Text option;
    option.setFont(font);
    option.setString(text);
    option.setCharacterSize(70);
    option.setFillColor(sf::Color::White);
    option.setPosition(x+10, y+10);
    window->draw(option);
}

void displaySettingCursor(sf::RenderWindow *window, Setting *setting, int x, int y, char* cursorSpritePath){
    // create a circle
    sf::CircleShape circle(50);
    sf::Texture texture;
    if (!texture.loadFromFile(cursorSpritePath)){
        exit(EXIT_FAILURE);
    }
    else{
        circle.setTexture(&texture);
    }
    circle.rotate(setting->getCursorRotation()-167.f);
    circle.setOrigin(50, 50);
    circle.setPosition(x+350, y+50);
    // draw the circle
    window->draw(circle);
    setting->setRotation(setting->getCursorRotation()+30.f);
}

void displaySoundState(sf::RenderWindow *window, Setting *setting){
    // create rectangle
    sf::RectangleShape rectangle(sf::Vector2f(400, 100));
    rectangle.setFillColor(setting->getFontColor());
    rectangle.setOutlineColor(sf::Color::White);
    rectangle.setOutlineThickness(5);
    rectangle.setPosition(window->getSize().x/2-200, 450);
    window->draw(rectangle);
    // create a text
    sf::Font font;
    if(!font.loadFromFile(setting->getFontPath())){
        std::cerr << "Error loading font" << std::endl;
        exit(EXIT_FAILURE);
    }
    sf::Text text;
    text.setFont(font);
    if(setting->getIsMusicOn()){
        text.setString("Music: On");
    }
    else{
        text.setString("Music: Off");
    }
    text.setCharacterSize(70);
    text.setFillColor(sf::Color::White);
    text.setPosition(window->getSize().x/2-190, 460);
    window->draw(text);
}

void displayStadiumState(sf::RenderWindow *window, Setting *setting){
    // create rectangle
    sf::RectangleShape rectangle(sf::Vector2f(600, 100));
    rectangle.setFillColor(setting->getFontColor());
    rectangle.setOutlineColor(sf::Color::White);
    rectangle.setOutlineThickness(5);
    rectangle.setPosition(window->getSize().x/2-200, 150);
    window->draw(rectangle);
    // create a text
    sf::Font font;
    if(!font.loadFromFile(setting->getFontPath())){
        std::cerr << "Error loading font" << std::endl;
        exit(EXIT_FAILURE);
    }
    sf::Text text;
    text.setFont(font);
    switch (setting->getStadiumID()){
    case 1:
        text.setString("Stadium: < | * * >");
        break;
    case 2:
        text.setString("Stadium: < * | * >");
        break;
    case 3:
        text.setString("Stadium: < * * | >");
        break;
    }
    text.setCharacterSize(70);
    text.setFillColor(sf::Color::White);
    text.setPosition(window->getSize().x/2-190, 160);
    window->draw(text);
}

void displayThemeState(sf::RenderWindow *window, Setting *setting){
    // create rectangle
    sf::RectangleShape rectangle(sf::Vector2f(600, 100));
    rectangle.setFillColor(setting->getFontColor());
    rectangle.setOutlineColor(sf::Color::White);
    rectangle.setOutlineThickness(5);
    rectangle.setPosition(window->getSize().x/2-200, 300);
    window->draw(rectangle);
    // create a text
    sf::Font font;
    if(!font.loadFromFile(setting->getFontPath())){
        std::cerr << "Error loading font" << std::endl;
        exit(EXIT_FAILURE);
    }
    sf::Text text;
    text.setFont(font);
    switch (setting->getThemeID()){
    case 1:
        text.setString("Theme: < | * * >");
        break;
    case 2:
        text.setString("Theme: < * | * >");
        break;
    case 3:
        text.setString("Theme: < * * | >");
        break;
    }
    text.setCharacterSize(70);
    text.setFillColor(sf::Color::White);
    text.setPosition(window->getSize().x/2-190, 310);
    window->draw(text);
}

void displayBackground(sf::RenderWindow *window, Arena *arena){
    // set background image
    sf::Texture BackgroundTexture;
    sf::Sprite background;
    
    if(!BackgroundTexture.loadFromFile(arena->getThemePath())){
      exit(EXIT_FAILURE);
    }
    else
    {
      background.setTexture(BackgroundTexture);
    }
    window->draw(background);
}

void displayArena(sf::RenderWindow *window, Arena *arena){
    // create a circle
    sf::CircleShape circle(arena->getRadius());
    circle.setFillColor(sf::Color{128, 128, 128, 255});
    circle.setOutlineColor(sf::Color{128, 128, 128, 255});
    circle.setOutlineThickness(5);
    sf::Texture texture;
    if (!texture.loadFromFile(arena->getStadiumPath())){
        exit(EXIT_FAILURE);

    }
    else{
        circle.setTexture(&texture);
    }
    circle.setPosition(arena->getCenterX()-arena->getRadius()-10, arena->getCenterY()-arena->getRadius()-10);
    // draw the circle
    window->draw(circle);
}

void displayScore1(sf::RenderWindow *window, Arena *arena, Player *player){
    // create a text
    sf::Font font;
    if(!font.loadFromFile(arena->getFontPath())){
        std::cerr << "Error loading font" << std::endl;
        exit(EXIT_FAILURE);
    }
    sf::Text text;
    text.setFont(font);
    text.setString("Score: " + std::to_string(player->getScore()));
    text.setCharacterSize(70);
    text.setFillColor(sf::Color::Red);
    text.setPosition(window->getSize().x-300, 110);
    // draw the text
    window->draw(text);
}

void displayWinRound1(sf::RenderWindow *window, Arena *arena, Player *player){
    // create a text
    sf::Font font;
    if(!font.loadFromFile(arena->getFontPath())){
        std::cerr << "Error loading font" << std::endl;
        exit(EXIT_FAILURE);
    }
    sf::Text text;
    text.setFont(font);
    text.setString("Won: " + std::to_string(player->getRoundWins()));
    text.setCharacterSize(70);
    text.setFillColor(sf::Color::Red);
    text.setPosition(window->getSize().x-300, 180);
    // draw the text
    window->draw(text);
}

void displayScore2(sf::RenderWindow *window, Arena *arena, Player *player){
    // create a text
    sf::Font font;
    if(!font.loadFromFile(arena->getFontPath())){
        std::cerr << "Error loading font" << std::endl;
        exit(EXIT_FAILURE);
    }
    sf::Text text;
    text.setFont(font);
    text.setString("Score: " + std::to_string(player->getScore()));
    text.setCharacterSize(70);
    text.setFillColor(sf::Color::Blue);
    text.setPosition(10, 110);
    // draw the text
    window->draw(text);
}

void displayWinRound2(sf::RenderWindow *window, Arena *arena, Player *player){
    // create a text
    sf::Font font;
    if(!font.loadFromFile(arena->getFontPath())){
        std::cerr << "Error loading font" << std::endl;
        exit(EXIT_FAILURE);
    }
    sf::Text text;
    text.setFont(font);
    text.setString("Won: " + std::to_string(player->getRoundWins()));
    text.setCharacterSize(70);
    text.setFillColor(sf::Color::Blue);
    text.setPosition(10, 180);
    // draw the text
    window->draw(text);
}

void displayTime(sf::RenderWindow *window, Arena *arena, int time){
    // create a text
    sf::Font font;
    if(!font.loadFromFile(arena->getFontPath())){
        std::cerr << "Error loading font" << std::endl;
        exit(EXIT_FAILURE);
    }
    sf::Text text;
    text.setFont(font);
    text.setString("Time: " + std::to_string(time));
    text.setCharacterSize(70);
    text.setFillColor(arena->getFontColor());
    text.setPosition(window->getSize().x/2, 10);
    // draw the text
    window->draw(text);
}

void displayPlayer(sf::RenderWindow *window, Player *player){
    // create a circle
    sf::CircleShape circle(player->getRadius());
    sf::Texture texture;
    if (!texture.loadFromFile(player->getSpritePath())){
        exit(EXIT_FAILURE);

    }
    else{
        circle.setTexture(&texture);
    }
    circle.setOutlineColor(player->getRingColor());
    circle.setOutlineThickness(5);
    circle.setOrigin(player->getRadius(), player->getRadius());
    circle.setPosition(player->getPosX()-player->getRadius()-5, player->getPosY()-player->getRadius()-5);
    // rotate the circle
    circle.rotate(player->getRotation()+167.f);
    // draw the circle
    window->draw(circle);
    player->setRotation(circle.getRotation());
}

void displayBot(sf::RenderWindow *window, Bot *bot){
    // create a circle
    sf::CircleShape circle(bot->getRadius());
    circle.setFillColor(sf::Color::Green);
    circle.setOutlineColor(sf::Color::Red);
    circle.setOutlineThickness(5);
    circle.setPosition(bot->getPosX()-bot->getRadius()-5, bot->getPosY()-bot->getRadius()-5);
    // draw the circle
    window->draw(circle);
}

void displayGameOver(sf::RenderWindow *window){
    // create a text
    sf::Font font;
    if(!font.loadFromFile(FONT_PATH)){
        std::cerr << "Error loading font" << std::endl;
        exit(EXIT_FAILURE);
    }
    sf::Text text;
    text.setFont(font);
    text.setString("Game Over");
    text.setCharacterSize(100);
    text.setFillColor(sf::Color::Red);
    text.setPosition(window->getSize().x/2-280, window->getSize().y/2-50);
    // draw the text
    window->draw(text);
}

void displayWin(sf::RenderWindow *window, int player){
    // create a text
    sf::Font font;
    if(!font.loadFromFile(FONT_PATH)){
        std::cerr << "Error loading font" << std::endl;
        exit(EXIT_FAILURE);
    }
    sf::Text text;
    text.setFont(font);
    if(player == 1){
        text.setString("Red player wins!");
    }
    else{
        text.setString("Blue player wins!");
    }
    text.setCharacterSize(100);
    text.setFillColor(sf::Color::Green);
    text.setPosition(window->getSize().x/2-400, window->getSize().y/2-50);
    // draw the text
    window->draw(text);
}

void displayDraw(sf::RenderWindow *window){
    // create a text
    sf::Font font;
    if(!font.loadFromFile(FONT_PATH)){
        std::cerr << "Error loading font" << std::endl;
        exit(EXIT_FAILURE);
    }
    sf::Text text;
    text.setFont(font);
    text.setString("Draw!");
    text.setCharacterSize(100);
    text.setFillColor(sf::Color::Yellow);
    text.setPosition(window->getSize().x/2-250, window->getSize().y/2-50);
    // draw the text
    window->draw(text);
}

void displayCredit(sf::RenderWindow *window, char* text, char *fontPath, sf::Color color){
    // Create rectangle
    sf::RectangleShape rectangle(sf::Vector2f(1000, 600));
    rectangle.setFillColor(color);
    rectangle.setOutlineColor(sf::Color::White);
    rectangle.setOutlineThickness(5);
    rectangle.setPosition(window->getSize().x/2-500, window->getSize().y/2-300);
    window->draw(rectangle);
    // create a text
    sf::Font font;
    if(!font.loadFromFile(fontPath)){
        std::cerr << "Error loading font" << std::endl;
        exit(EXIT_FAILURE);
    }
    sf::Text credit;
    credit.setFont(font);
    credit.setString(text);
    credit.setCharacterSize(70);
    credit.setFillColor(sf::Color::White);
    credit.setPosition(window->getSize().x/2-450, window->getSize().y/2-350);
    window->draw(credit);
}

void displayRoundNumber(sf::RenderWindow *window, Arena *arena, int round){
    // create a text
    sf::Font font;
    if(!font.loadFromFile(arena->getFontPath())){
        std::cerr << "Error loading font" << std::endl;
        exit(EXIT_FAILURE);
    }
    sf::Text text;
    text.setFont(font);
    text.setString("Round: " + std::to_string(round));
    text.setCharacterSize(70);
    text.setFillColor(arena->getFontColor());
    text.setPosition(window->getSize().x/2-300, 10);
    // draw the text
    window->draw(text);
}

void displayFinalScore(sf::RenderWindow *window, Player *player1, Player *player2){
    // create a text
    sf::Font font;
    if(!font.loadFromFile(FONT_PATH)){
        std::cerr << "Error loading font" << std::endl;
        exit(EXIT_FAILURE);
    }
    sf::Text text;
    text.setFont(font);
    text.setString("Final Score");
    text.setCharacterSize(100);
    text.setFillColor(sf::Color::White);
    text.setPosition(window->getSize().x/2-250, 30);
    // draw the text
    window->draw(text);
    // create a text
    sf::Text text1;
    text1.setFont(font);
    if(player1->getRoundWins() > player2->getRoundWins()){
        text1.setString("Red player wins!");
        text1.setFillColor(sf::Color::Red);
        text1.setPosition(window->getSize().x/2-270, window->getSize().y/2);
    }
    else if(player1->getRoundWins() < player2->getRoundWins()){
        text1.setString("Blue player wins!");
        text1.setFillColor(sf::Color::Blue);
        text1.setPosition(window->getSize().x/2-280, window->getSize().y/2);
    }
    else{
        text1.setString("Draw!");
        text1.setFillColor(sf::Color::Yellow);
        text1.setPosition(window->getSize().x/2-150, window->getSize().y/2);
    }
    text1.setCharacterSize(70);
    // draw the text
    window->draw(text1);
}