#include "arena.hpp"

Arena::Arena(int x, int y, int r, int l, int s) {
    this->center_x = x;
    this->center_y = y;
    this->radius = r;
    this->level = l;
    this->score = s;
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

int Arena::levelUp(){
    this->level++;
}

int Arena::scoreUp(int points){
    this->score += points;
}