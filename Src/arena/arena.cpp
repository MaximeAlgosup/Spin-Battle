#include "arena.hpp"
#include <iostream>
#include <fstream>

Arena::    Arena(int x, int y, int r, int l, int s, char* backgroundPath, char* fontPath, sf::Color fontColor, char* soundPath) {
    this->center_x = x;
    this->center_y = y;
    this->radius = r;
    this->level = l;
    this->score = s;
    // Check if the background image exists
    if(!std::ifstream(backgroundPath)){
        std::cerr << "Error loading background image" << std::endl;
        exit(EXIT_FAILURE);
    }
    this->backgroundPath = backgroundPath;
    // Check if the font exists
    if(!std::ifstream(fontPath)){
        std::cerr << "Error loading font" << std::endl;
        exit(EXIT_FAILURE);
    }
    this->fontPath = fontPath;
    this->fontColor = fontColor;
    this->soundPath = soundPath;
    if (!music.openFromFile("../Src/assets/musics/beybladeopenning.ogg"))
        exit(EXIT_FAILURE);
    else{
        music.setLoop(true);
    }
}

// Getters

int Arena::getCenterX(){
    return this->center_x;
}

int Arena::getCenterY(){
    return this->center_y;
}

int Arena::getRadius(){
    return this->radius;
}

int Arena::getLevel(){
    return this->level;
}

int Arena::getScore(){
    return this->score;
}

char* Arena::getBackgroundPath(){
    return this->backgroundPath;
}

char* Arena::getFontPath(){
    return this->fontPath;
}

sf::Color Arena::getFontColor(){
    return this->fontColor;
}

char* Arena::getSoundPath(){
    return this->soundPath;
}

// Setters

int Arena::setSize(){
    if(this->level >= 1 && this->level < 5){
        this->radius = 300;
        return 300;
    }
    else if(this->level >= 5 && this->level < 10){
        this->radius = 200;
        return 200;
    }
    else if(this->level == 10 || this->level > 10){
        this->radius = 100;
        return 100;
    }
    else{
        this->radius = 50;
        return 50;
    }
    return this->radius;
}

void Arena::setBackgroundPath(char* backgroundPath){
    // Check if the background image exists
    if(!std::ifstream(backgroundPath)){
        std::cerr << "Error loading background image" << std::endl;
        exit(EXIT_FAILURE);
    }
    this->backgroundPath = backgroundPath;
}

void Arena::setFontPath(char* fontPath){
    // Check if the font exists
    if(!std::ifstream(fontPath)){
        std::cerr << "Error loading font" << std::endl;
        exit(EXIT_FAILURE);
    }
    this->fontPath = fontPath;
}

void Arena::setFontColor(sf::Color fontColor){
    this->fontColor = fontColor;
}

void Arena::setSoundPath(char* soundPath){
    this->soundPath = soundPath;
    if (!music.openFromFile(soundPath))
        exit(EXIT_FAILURE);
    else{
        music.setLoop(true);
    }
}

int Arena::levelUp(){
    this->level++;
    return this->level;
}

int Arena::scoreUp(int points){
    this->score += points;
    return this->score;
}

void Arena::playMusic(){
    music.play();
}

void Arena::stopMusic(){
    music.stop();
}