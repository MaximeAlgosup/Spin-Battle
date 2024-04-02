#include "spinner.hpp"
#include <cmath>
#include <iostream>

Spinner::Spinner(unsigned int x, unsigned int y, int w, int s, int i, int a) {
    this->pos_x = x;
    this->pos_y = y;
    this->weight = w;
    this->maxSpeed = s;
    this->speed = 0;
    this->agility = a;
    this->isDead = false;
    this->radius = 20;
    this->direction = NONE;
    this->maxInertia = i;
    this->inertia = 0;
    this->isDead = false;
}

// Getters

int Spinner::getDistance(Spinner spin){
    return sqrt(pow(abs(this->pos_x - spin.getPosX()), 2) + pow(abs(this->pos_y - spin.getPosY()), 2));
}

int Spinner::getPosX(){
    return this->pos_x;
}

int Spinner::getPosY(){
    return this->pos_y;
}

int Spinner::getWeight(){
    return this->weight;
}

int Spinner::getSpeed(){
    return this->speed;
}

int Spinner::getAgility(){
    return this->agility;
}

int Spinner::getRadius(){
    return this->radius;
}

bool Spinner::getIsDead(){
    return this->isDead;
}

// Setters

void Spinner::moveUp(){
    if(this->inertia > this->agility && this->direction != UP){
        Spinner::autoMove();
        return;
    }
    if(this->speed < this->maxSpeed){
        this->speed += 1;
    }
    this->pos_y -= this->speed;
    this->direction = UP;
    this->inertia = this->weight*pow(this->speed, 2);
    if(this->inertia > this->maxInertia){
        this->inertia = this->maxInertia;
    }
}

void Spinner::moveDown(){
    if(this->inertia > this->agility && this->direction != DOWN){
        Spinner::autoMove();
        return;
    }
    if(this->speed < this->maxSpeed){
        this->speed += 1;
    }
    this->pos_y += this->speed;
    this->direction = DOWN;
    this->inertia = this->weight*pow(this->speed, 2);
    if(this->inertia > this->maxInertia){
        this->inertia = this->maxInertia;
    }
}

void Spinner::moveLeft(){
    if(this->inertia > this->agility && this->direction != LEFT){
        Spinner::autoMove();
        return;
    }
    if(this->speed < this->maxSpeed){
        this->speed += 1;
    }
    this->pos_x -= this->speed;
    this->direction = LEFT;
    this->inertia = this->weight*pow(this->speed, 2);
    if(this->inertia > this->maxInertia){
        this->inertia = this->maxInertia;
    }
}

void Spinner::moveRight(){
    if(this->inertia > this->agility && this->direction != RIGHT){
        Spinner::autoMove();
        return;
    }
    if(this->speed < this->maxSpeed){
        this->speed += 1;
    }
    this->pos_x += this->speed;
    this->direction = RIGHT;
    this->inertia = this->weight*pow(this->speed, 2);
    if(this->inertia > this->maxInertia){
        this->inertia = this->maxInertia;
    }
}

void Spinner::autoMove(){
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
        this->inertia /= this->agility;
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

void Spinner::reverseDirection(){
    if(this->direction == UP){
        this->direction = DOWN;
    }
    else if(this->direction == DOWN){
        this->direction = UP;
    }
    else if(this->direction == LEFT){
        this->direction = RIGHT;
    }
    else if(this->direction == RIGHT){
        this->direction = LEFT;
    }
}

 int Spinner::contact(Spinner *otherSpin){
    if(this->inertia > otherSpin->inertia){
        this->inertia /= 2;
        otherSpin->inertia += (this->inertia/2);
        if(otherSpin->inertia > otherSpin->maxInertia){
            otherSpin->inertia = otherSpin->maxInertia;
        }
        otherSpin->speed += (this->speed/2);
        otherSpin->direction = this->direction;
        this->reverseDirection();
        return 1;
    }
    else if(this->inertia < otherSpin->inertia){
        otherSpin->inertia /= 2;
        this->inertia += (otherSpin->inertia/2);
        if(this->inertia > this->maxInertia){
            this->inertia = this->maxInertia;
        }
        this->speed += (otherSpin->speed/2);
        this->direction = otherSpin->direction;
        otherSpin->reverseDirection();
        return -1;
    }
    else{
        this->inertia *= 4;
        otherSpin->inertia *= 4;
        this->speed *= 4;
        otherSpin->speed *= 4;
        this->reverseDirection();
        otherSpin->reverseDirection();
        return 0;
    }
 }

bool Spinner::isColliding(Spinner otherSpin){
    // Calculate the distance between the two spinners
    float distance = this->getDistance(otherSpin);
    // Check if the spinners are colliding
    if(distance < (this->radius + otherSpin.getRadius() + 10)){
        int contactSize = abs(distance - (this->radius + otherSpin.getRadius() + 10));
        if( contactSize > 0){
            switch (this->direction)
            {
            case UP:
                this->pos_y += contactSize;
                break;
            case DOWN:
                this->pos_y -= contactSize;
                break;
            case LEFT:
                this->pos_x += contactSize;
                break;
            case RIGHT:
                this->pos_x -= contactSize;
                break;
            default:
                break;
            }
        }
        return true;
    }
    return false;
}

bool Spinner::isOut(int arena_x, int arena_y, int arena_radius){
    // Calculate the distance between the center of the arena and the spinner
    float distance = sqrt(pow(abs(this->pos_x - arena_x), 2) + pow(abs(this->pos_y - arena_y), 2));
    // Check if the spinner is out of the arena
    if(distance > arena_radius+this->radius){
        this->isDead = true;
        return true;
    }
    return false;
}

void Spinner::displayData(){
    std::cout << "Spinner Data: " << std::endl;
    std::cout << "Position: (" << this->pos_x << ", " << this->pos_y << ")" << std::endl;
    std::cout << "Weight: " << this->weight << std::endl;
    std::cout << "Speed: " << this->speed << std::endl;
    std::cout << "Agility: " << this->agility << std::endl;
    std::cout << "Direction: " << this->direction << std::endl;
    std::cout << "Inertia: " << this->inertia << std::endl;
    std::cout << "Is Dead: " << this->isDead << std::endl;
    std::cout << "Radius: " << this->radius << std::endl;
    std::cout << std::endl;
}