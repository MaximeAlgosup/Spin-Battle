#include "spinner.hpp"
#include <cmath>
#include <iostream>

Spinner::Spinner(unsigned int x, unsigned int y, int w, int s, int a) {
    this->pos_x = x;
    this->pos_y = y;
    this->weight = w;
    this->speed = s;
    this->agility = a;
    this->isDead = false;
    this->radius = 20;
    this->direction = 0;
    this->inertia = 0;
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
    this->direction = 1;
    this->inertia = this->weight;
}

void Spinner::moveDown(){
    this->pos_y += this->speed;
    this->direction = 2;
    this->inertia = this->weight;
}

void Spinner::moveLeft(){
    this->pos_x -= this->speed;
    this->direction = 3;
    this->inertia = this->weight;
}

void Spinner::moveRight(){
    this->pos_x += this->speed;
    this->direction = 4;
    this->inertia = this->weight;
}

void Spinner::autoMove(){
    if(this->inertia == 0){
        return;
    }
    if(this->direction == 1){
        this->pos_y -= this->speed;
    }
    else if(this->direction == 2){
        this->pos_y += this->speed;
    }
    else if(this->direction == 3){
        this->pos_x -= this->speed;
    }
    else if(this->direction == 4){
        this->pos_x += this->speed;
    }
    else{
        this->moveUp();
    }
    this->inertia -= this->agility;
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