#include "bot.hpp"
#include <cmath>
#include <iostream>

Bot::Bot(int level, bool ig, unsigned int x, unsigned int y, int w, int s, int i, int a) : Spinner(x, y, w, s, i, a){
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
    if(distance < (this->visionDistance + spin.getRadius() + 5)){
        return true;
    }
    return false;
}

void Bot::target(Spinner spin){
    int dist_x = this->pos_x - spin.getPosX();
    int dist_y = this->pos_y - spin.getPosY();
    if(abs(dist_x) > abs(dist_y)){
        if(dist_x > 0){
            if(this->direction == LEFT || this->inertia < this->agility){
                this->direction = LEFT;
                this->speed += 1;
                if(this->speed > this->maxSpeed){
                    this->speed = this->maxSpeed;
                }
                this->inertia = this->weight*pow(this->speed, 2);
                if(this->inertia > this->maxInertia){
                    this->inertia = this->maxInertia;
                }
            }
            this->autoMove();
        }
        else{
            if(this->direction == RIGHT || this->inertia < this->agility){
                this->direction = RIGHT;
                this->speed += 1;
                if(this->speed > this->maxSpeed){
                    this->speed = this->maxSpeed;
                }
                this->inertia = this->weight*pow(this->speed, 2);
                if(this->inertia > this->maxInertia){
                    this->inertia = this->maxInertia;
                }
            }
            this->autoMove();
        }
    }
    else{
        if(dist_y > 0){
            if(this->direction == UP || this->inertia < this->agility){
                this->direction = UP;
                this->speed += 1;
                if(this->speed > this->maxSpeed){
                    this->speed = this->maxSpeed;
                }
                this->inertia = this->weight*pow(this->speed, 2);
                if(this->inertia > this->maxInertia){
                    this->inertia = this->maxInertia;
                }
            }
            this->autoMove();
        }
        else{
            if(this->direction == DOWN || this->inertia < this->agility){
                this->direction = DOWN;
                this->speed += 1;
                if(this->speed > this->maxSpeed){
                    this->speed = this->maxSpeed;
                }
                this->inertia = this->weight*pow(this->speed, 2);
                if(this->inertia > this->maxInertia){
                    this->inertia = this->maxInertia;
                }
            }
            this->autoMove();
        }
    }
}

void Bot::autoMove(){
    // Move the bot
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
