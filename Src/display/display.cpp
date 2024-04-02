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
    
    // create a text
    sf::Font font;
    if(!font.loadFromFile(FONT_PATH)){
        std::cerr << "Error loading font" << std::endl;
        exit(EXIT_FAILURE);
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
    text.setPosition(sf::VideoMode::getDesktopMode().width/2-550, 100);
    window->draw(text);
}

void displayBackground(sf::RenderWindow *window, Arena *arena){
    // set background image
    sf::Texture BackgroundTexture;
    sf::Sprite background;
    
    if(!BackgroundTexture.loadFromFile(arena->getBackgroundPath())){
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
    sf::Texture texture;
    if (!texture.loadFromFile(arena->getThemePath())){
        exit(EXIT_FAILURE);

    }
    else{
        circle.setTexture(&texture);
    }
    circle.setOutlineColor(sf::Color::Yellow);
    circle.setOutlineThickness(10);
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
    text.setFillColor(arena->getFontColor());
    text.setPosition(10, 10);
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
    text.setFillColor(arena->getFontColor());
    text.setPosition(10, 110);
    // draw the text
    window->draw(text);
}

void displayPlayer(sf::RenderWindow *window, Player *player){
    // create a circle
    sf::CircleShape circle(player->getRadius());
    circle.setFillColor(sf::Color::Red);
    circle.setOutlineColor(sf::Color::Green);
    circle.setOutlineThickness(5);
    circle.setPosition(player->getPosX()-player->getRadius()-5, player->getPosY()-player->getRadius()-5);
    // draw the circle
    window->draw(circle);
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
    text.setPosition(sf::VideoMode::getDesktopMode().width/2-280, sf::VideoMode::getDesktopMode().height/2-50);
    // draw the text
    window->draw(text);
}

void displayWin(sf::RenderWindow *window){
    // create a text
    sf::Font font;
    if(!font.loadFromFile(FONT_PATH)){
        std::cerr << "Error loading font" << std::endl;
        exit(EXIT_FAILURE);
    }
    sf::Text text;
    text.setFont(font);
    text.setString("You Win");
    text.setCharacterSize(100);
    text.setFillColor(sf::Color::Green);
    text.setPosition(sf::VideoMode::getDesktopMode().width/2-280, sf::VideoMode::getDesktopMode().height/2-50);
    // draw the text
    window->draw(text);
}