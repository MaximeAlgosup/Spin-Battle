#include "party.hpp"
#include "display.hpp"
#include <iostream>
#include <chrono>
#include <SFML/Graphics.hpp>

#define CONTACT_SOUND "../Src/assets/sounds/contact.ogg"

Party::Party(Player *player1, Player *player2, Arena *arena, sf::RenderWindow *window){
    this->player1 = player1;
    this->player2 = player2;
    this->arena = arena;
    this->window = window;
    this->time = 100;
    this->inGame = true;
    if (!buffer.loadFromFile(CONTACT_SOUND)) exit(EXIT_FAILURE);
    sound.setBuffer(buffer);
}

Party::Party(Player *player1, Player *player2, Arena *arena, sf::RenderWindow *window, int time){
    this->player1 = player1;
    this->player2 = player2;
    this->arena = arena;
    this->window = window;
    this->time = time;
    this->inGame = true;
    if (!buffer.loadFromFile(CONTACT_SOUND)) exit(EXIT_FAILURE);
    sound.setBuffer(buffer);
}

void Party::run(Setting *settings){
    if(settings->getIsMusicOn() == true){
        this->arena->playMusic();
    }
    auto start = std::chrono::system_clock::now();
    while(this->inGame){
        // Events
        keybordEvent();
        // Actions
        this->arena->setSize();

        // spinner collision
        if(player1->isColliding(*player2)){
            contactSound(settings->getIsMusicOn());
            int result = player1->contact(player2);
            switch(result){
                case 1:
                    player1->scoreUp(2);
                    break;
                case -1:
                    player2->scoreUp(2);
                    break;
                default:
                    player1->scoreUp(1);
                    player2->scoreUp(1);
                    break;
            }
        }

        // visual update
        update();
        if(time == 0){
            displayTime(window, arena, time);
            break;
        }
        // Check if the spinner is out of the arena
        if(player1->isOut(arena->getCenterX(), arena->getCenterY(), arena->getRadius())){
            player1->setDead(true);
            player1->resetScore();
            if(player2->getScore() == 0) player2->scoreUp(1);
            time = 0;
        }
        else if(player2->isOut(arena->getCenterX(), arena->getCenterY(), arena->getRadius())){
            player2->setDead(true);
            player2->resetScore();
            if(player1->getScore() == 0) player1->scoreUp(1);
            time = 0;
        }
        else{
            // time management
            auto end = std::chrono::system_clock::now();
            std::chrono::duration<double> elapsed_seconds = end-start;
            if(elapsed_seconds.count() > 1){
                start = std::chrono::system_clock::now();
                time--;
            }
        }
    }
    if(player1->getScore() > player2->getScore()){
        player1->setPosX(arena->getCenterX());
        player1->setPosY(arena->getCenterY());
        update();
        win(1);
    }
    else if(player1->getScore() < player2->getScore()){
        player2->setPosX(arena->getCenterX());
        player2->setPosY(arena->getCenterY());
        update();
        win(2);
    }
    else{
        update();
        equality();
    }
    this->arena->stopMusic();
}

void Party::keybordEvent(){
    // Events
    sf::Event event;
    while (window->pollEvent(event)){
        // "close requested" event: we close the window
        if (event.type == sf::Event::Closed || sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)){
            inGame = false;
        }
    }
    // move player 1
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Left) && sf::Keyboard::isKeyPressed(sf::Keyboard::Up)){
        // Check if the spinner is out of the screen
        if((player1->getPosX() - player1->getRadius()) > 10 && (player1->getPosY() - player1->getRadius()) > 10){
            player1->moveUpLeft();
        }
    }
    else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Left) && sf::Keyboard::isKeyPressed(sf::Keyboard::Down)){
        // Check if the spinner is out of the screen
        if((player1->getPosX() - player1->getRadius()) > 10 && (player1->getPosY() + player1->getRadius()) < window->getSize().y){
            player1->moveDownLeft();
        }
    }
    else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Right) && sf::Keyboard::isKeyPressed(sf::Keyboard::Up)){
        // Check if the spinner is out of the screen
        if((player1->getPosX() + player1->getRadius()) < window->getSize().x && (player1->getPosY() - player1->getRadius()) > 10){
            player1->moveUpRight();
        }
    }
    else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Right) && sf::Keyboard::isKeyPressed(sf::Keyboard::Down)){
        // Check if the spinner is out of the screen
        if((player1->getPosX() + player1->getRadius()) < window->getSize().x && (player1->getPosY() + player1->getRadius()) < window->getSize().y){
            player1->moveDownRight();
        }
    }
    else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Left)){
        // Check if the spinner is out of the screen
        if((player1->getPosX() - player1->getRadius()) > 10){
            player1->moveLeft();
        }
    }
    else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Right)){
        if((player1->getPosX() + player1->getRadius()) < window->getSize().x){
            player1->moveRight();
        }
    }
    else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Up)){
        if((player1->getPosY() - player1->getRadius()) > 10){
            player1->moveUp();
        }
    }
    else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Down)){
        if((player1->getPosY() + player1->getRadius()) < window->getSize().y){
            player1->moveDown();
        }
    }
    else if(sf::Keyboard::isKeyPressed(sf::Keyboard::RControl)){
        player1->teleport();
    }
    // move player 2
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::W) && sf::Keyboard::isKeyPressed(sf::Keyboard::A)){
        // Check if the spinner is out of the screen
        if((player2->getPosX() - player2->getRadius()) > 10 && (player2->getPosY() - player2->getRadius()) > 10){
            player2->moveUpLeft();
        }
    }
    else if(sf::Keyboard::isKeyPressed(sf::Keyboard::A) && sf::Keyboard::isKeyPressed(sf::Keyboard::S)){
        // Check if the spinner is out of the screen
        if((player2->getPosX() - player2->getRadius()) > 10 && (player2->getPosY() + player2->getRadius()) < window->getSize().y){
            player2->moveDownLeft();
        }
    }
    else if(sf::Keyboard::isKeyPressed(sf::Keyboard::W) && sf::Keyboard::isKeyPressed(sf::Keyboard::D)){
        // Check if the spinner is out of the screen
        if((player2->getPosX() + player2->getRadius()) < window->getSize().x && (player2->getPosY() - player2->getRadius()) > 10){
            player2->moveUpRight();
        }
    }
    else if(sf::Keyboard::isKeyPressed(sf::Keyboard::D) && sf::Keyboard::isKeyPressed(sf::Keyboard::S)){
        // Check if the spinner is out of the screen
        if((player2->getPosX() + player2->getRadius()) < window->getSize().x && (player2->getPosY() + player2->getRadius()) < window->getSize().y){
            player2->moveDownRight();
        }
    }
    else if(sf::Keyboard::isKeyPressed(sf::Keyboard::A)){
        // Check if the spinner is out of the screen
        if((player2->getPosX() - player2->getRadius()) > 10){
            player2->moveLeft();
        }
    }
    else if(sf::Keyboard::isKeyPressed(sf::Keyboard::D)){
        if((player2->getPosX() + player2->getRadius()) < window->getSize().x){
            player2->moveRight();
        }
    }
    else if(sf::Keyboard::isKeyPressed(sf::Keyboard::W)){
        if((player2->getPosY() - player2->getRadius()) > 10){
            player2->moveUp();
        }
    }
    else if(sf::Keyboard::isKeyPressed(sf::Keyboard::S)){
        if((player2->getPosY() + player2->getRadius()) < window->getSize().y){
            player2->moveDown();
        }
    }
    else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Q)){
        player2->teleport();
    }
    
    player1->autoMove();
    player2->autoMove();
}


void Party::update(){
    // Draws
    displayBackground(window, arena);
    displayArena(window, arena);
    if(!player1->getIsDead()) displayPlayer(window, player1);
    if(!player2->getIsDead()) displayPlayer(window, player2);
    displayScore1(window, arena, player1);
    displayScore2(window, arena, player2);
    displayTime(window, arena, time);
    // end the current frame
    window->display();  
}

void Party::win(int player){
    bool isdisplayed = false;
    while(!sf::Keyboard::isKeyPressed(sf::Keyboard::Enter)){
        displayWin(window, player);
        if(!isdisplayed){
            isdisplayed = true;
            window->display();
        }
    }
}

void Party::equality(){
    bool isdisplayed = false;
    while(!sf::Keyboard::isKeyPressed(sf::Keyboard::Enter)){
        displayDraw(window);
        if(!isdisplayed){
            isdisplayed = true;
            window->display();
        }
    }
}

void Party::contactSound(bool isMusicOn){
    if(isMusicOn){
        sound.setVolume(200);
        sound.play();
    }
}
