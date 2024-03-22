#include "spinner.hpp"
#include <cmath>

Spinner::Spinner(unsigned int x, unsigned int y, int w, int s, int a) {
    this->pos_x = x;
    this->pos_y = y;
    this->weight = w;
    this->speed = s;
    this->agility = a;
    this->isDead = false;
    this->radius = 20;
}

// Getters

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
    this->pos_y -= this->speed;
}

void Spinner::moveDown(){
    this->pos_y += this->speed;
}

void Spinner::moveLeft(){
    this->pos_x -= this->speed;
}

void Spinner::moveRight(){
    this->pos_x += this->speed;
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
