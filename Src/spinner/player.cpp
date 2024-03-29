#include "player.hpp"

Player::Player(unsigned int x, unsigned int y, int w, int s, int a) : Spinner(x, y, w, s, a) {
    this->score = 0;
    this->level = 1;
}

int Player::getScore(){
    return this->score;
}

int Player::getLevel(){
    return this->level;
}

void Player::scoreUp(int points){
    this->score += points;
}

void Player::levelUp(){
    this->level++;
}