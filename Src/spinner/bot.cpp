#include "bot.hpp"

Bot::Bot(int level, bool ig, unsigned int x, unsigned int y, int w, int s, int a) : Spinner(x, y, w, s, a){
    this->level = level;
    this->inGame = ig;
}

void Bot::move(){
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
