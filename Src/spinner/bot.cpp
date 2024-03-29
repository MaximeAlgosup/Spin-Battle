#include "bot.hpp"
#include <iostream>

Bot::Bot(int level, bool ig, unsigned int x, unsigned int y, int w, int s, int a) : Spinner(x, y, w, s, a){
    this->level = level;
    this->inGame = ig;
    switch (this->level)
    {
    case 1:
        this->visionDistance = 75;
        break;
    case 2:
        this->visionDistance = 125;
        break;
    case 3:
        this->visionDistance = 150;
        break;
    case 4:
        this->visionDistance = 175;
        break;
    default:
        this->visionDistance = 200;
        break;
    }
}

bool Bot::isClose(Spinner spin){
    int distance = this->getDistance(spin);
    std::cout << "Distance: " << distance << std::endl;
    std::cout << "Vision: " << this->visionDistance << std::endl;
    std::cout << "Radius: " << spin.getRadius() << std::endl << std::endl;
    if(distance < (this->visionDistance + spin.getRadius() + 5)){
        return true;
    }
    return false;
}

void Bot::target(Spinner spin){
    if(this->pos_x < spin.getPosX()){
        this->moveRight();
    }
    else if(this->pos_x > spin.getPosX()){
        this->moveLeft();
    }
    else if(this->pos_y < spin.getPosY()){
        this->moveDown();
    }
    else if(this->pos_y > spin.getPosY()){
        this->moveUp();
    }
}

void Bot::autoMove(){
    // Move the bot
    if(this->inertia == 0){
        return;
    }
    if(this->direction == UP){
        this->pos_y -= this->speed;
    }
    else if(this->direction == DOWN){
        this->pos_y += this->speed;
    }
    else if(this->direction == LEFT){
        this->pos_x -= this->speed;
    }
    else if(this->direction == RIGHT){
        this->pos_x += this->speed;
    }

    if(this->inertia > this->agility){
        this->inertia -= this->agility;
    }
    else{
        this->inertia = this->agility;
    }
    
    if(this->speed > 1){
        this->speed -= 1;
    }
    else{
        this->speed = 1;
    }
}

// Getters

bool Bot::getInGame(){
    return this->inGame;
}

// Setters

void Bot::setInGame(bool inGame){
    this->inGame = inGame;
}
