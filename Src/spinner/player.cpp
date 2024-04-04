#include "player.hpp"
#include <fstream>
#include <iostream>

#define TELEPORTATION_COST 50
#define TELEPORTATION_RANGE 100

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

void Player::teleport(){
    if(this->score >= TELEPORTATION_COST){
        this->score -= TELEPORTATION_COST;
        switch (this->direction)
        {
        case UP:
            this->setPosY(this->getPosY() - TELEPORTATION_RANGE);
            break;
        case DOWN:
            this->setPosY(this->getPosY() + TELEPORTATION_RANGE);
            break;
        case LEFT:
            this->setPosX(this->getPosX() - TELEPORTATION_RANGE);
            break;
        case RIGHT:
            this->setPosX(this->getPosX() + TELEPORTATION_RANGE);
            break;
        case UP_LEFT:
            this->setPosX(this->getPosX() - TELEPORTATION_RANGE);
            this->setPosY(this->getPosY() - TELEPORTATION_RANGE);
            break;
        case UP_RIGHT:
            this->setPosX(this->getPosX() + TELEPORTATION_RANGE);
            this->setPosY(this->getPosY() - TELEPORTATION_RANGE);
            break;
        case DOWN_LEFT:
            this->setPosX(this->getPosX() - TELEPORTATION_RANGE);
            this->setPosY(this->getPosY() + TELEPORTATION_RANGE);
            break;
        case DOWN_RIGHT:
            this->setPosX(this->getPosX() + TELEPORTATION_RANGE);
            this->setPosY(this->getPosY() + TELEPORTATION_RANGE);
            break;        
        default:
            break;
        }
    }
}