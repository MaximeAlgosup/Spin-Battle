#include <iostream>
#include "display.hpp"

#define FONT_PATH "../Src/fonts/FFF_Tusj.ttf"

void displayBackground(sf::RenderWindow &window){
    // set background color
    window.clear(sf::Color::Blue);
}

void displayArena(sf::RenderWindow &window, Arena &arena){
    // create a circle
    sf::CircleShape circle(arena.getRadius());
    circle.setFillColor(sf::Color::Black);
    circle.setOutlineColor(sf::Color::Yellow);
    circle.setOutlineThickness(10);
    circle.setPosition(arena.getCenterX()-arena.getRadius()-10, arena.getCenterY()-arena.getRadius()-10);
    // draw the circle
    window.draw(circle);
}

void displayScore(sf::RenderWindow &window, Arena &arena){
    // create a text
    sf::Font font;
    if(!font.loadFromFile(FONT_PATH)){
        std::cerr << "Error loading font" << std::endl;
        exit(EXIT_FAILURE);
    }
    sf::Text text;
    text.setFont(font);
    text.setString("Score: " + std::to_string(arena.getScore()));
    text.setCharacterSize(70);
    text.setFillColor(sf::Color::White);
    text.setPosition(arena.getCenterX() + 100, 10);
    // draw the text
    window.draw(text);
}


void displayLevel(sf::RenderWindow &window, Arena &arena){
    // create a text
    sf::Font font;
    if(!font.loadFromFile(FONT_PATH)){
        std::cerr << "Error loading font" << std::endl;
        exit(EXIT_FAILURE);
    }
    sf::Text text;
    text.setFont(font);
    text.setString("Level: " + std::to_string(arena.getLevel()));
    text.setCharacterSize(70);
    text.setFillColor(sf::Color::White);
    text.setPosition(10, 10);
    // draw the text
    window.draw(text);
}