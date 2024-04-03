#include "party.hpp"
#include "display.hpp"
#include <iostream>
#include <chrono>
#include <SFML/Graphics.hpp>

Party::Party(Player *player1, Player *player2, Arena *arena, sf::RenderWindow *window){
    this->player1 = player1;
    this->player2 = player2;
    this->arena = arena;
    this->window = window;
    this->time = 100;
    this->inGame = true;
}

Party::Party(Player *player1, Player *player2, Arena *arena, sf::RenderWindow *window, int time){
    this->player1 = player1;
    this->player2 = player2;
    this->arena = arena;
    this->window = window;
    this->time = time;
    this->inGame = true;
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
        // visual update
        update();
        if(time == 0){
            displayTime(window, arena, time);
            break;
        }
    }
    if(player1->getScore() > player2->getScore()){
        win(1);
    }
    else if(player1->getScore() < player2->getScore()){
        win(2);
    }
    else{
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
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)){
        // Check if the spinner is out of the screen
        if((player1->getPosX() - player1->getRadius()) > 10){
            player1->moveLeft();
        }
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)){
        if((player1->getPosX() + player1->getRadius()) < window->getSize().x){
            player1->moveRight();
        }
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)){
        if((player1->getPosY() - player1->getRadius()) > 10){
            player1->moveUp();
        }
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)){
        if((player1->getPosY() + player1->getRadius()) < window->getSize().y){
            player1->moveDown();
        }
    }
    // move player 2
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)){
        // Check if the spinner is out of the screen
        if((player2->getPosX() - player2->getRadius()) > 10){
            player2->moveLeft();
        }
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)){
        if((player2->getPosX() + player2->getRadius()) < window->getSize().x){
            player2->moveRight();
        }
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)){
        if((player2->getPosY() - player2->getRadius()) > 10){
            player2->moveUp();
        }
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)){
        if((player2->getPosY() + player2->getRadius()) < window->getSize().y){
            player2->moveDown();
        }
    }
    else{
        player1->autoMove();
        player2->autoMove();
    }
}


void Party::update(){
    // Draws
    displayBackground(window, arena);
    displayArena(window, arena);
    displayPlayer(window, player1);
    displayPlayer(window, player2);
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

