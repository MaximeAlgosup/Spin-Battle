#include "player.hpp"
#include <fstream>
#include <iostream>

Player::Player(unsigned int x, unsigned int y, int w, int s, int i, int a, sf::Color rc, char* spritePath) : Spinner(x, y, w, s, i, a) {
    this->score = 0;
    this->ringColor = rc;
    // Check if the sprite exists
    if(!std::ifstream(spritePath)){
        std::cerr << "Error loading sprite" << std::endl;
        exit(EXIT_FAILURE);
    }
    this->spritePath = spritePath;
}

int Player::getScore(){
    return this->score;
}

int Player::getLevel(){
    return this->level;
}

sf::Color Player::getRingColor(){
    return this->ringColor;
}

char* Player::getSpritePath(){
    return this->spritePath;
}

void Player::setDead(bool dead){
    this->isDead = dead;
}

void Player::setSpritePath(char* spritePath){
    // Check if the sprite exists
    if(!std::ifstream(spritePath)){
        std::cerr << "Error loading sprite" << std::endl;
        exit(EXIT_FAILURE);
    }
    this->spritePath = spritePath;
}

void Player::scoreUp(int points){
    this->score += points;
}

void Player::resetScore(){
    this->score = 0;
}

void Player::levelUp(){
    this->level++;
}