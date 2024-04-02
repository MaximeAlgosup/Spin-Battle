#include "party.hpp"
#include "display.hpp"
#include <iostream>
#include <SFML/Graphics.hpp>

Party::Party(Player *player1, Player *player2, Arena *arena, sf::RenderWindow *window){
    this->player1 = player1;
    this->player2 = player2;
    this->arena = arena;
    this->window = window;
}

void Party::run(){
    this->arena->playMusic();
    while(window->isOpen()){
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

        // visual update
        update();
    }
    this->arena->stopMusic();
}

void Party::keybordEvent(){
    // Events
    sf::Event event;
    while (window->pollEvent(event)){
        // "close requested" event: we close the window
        if (event.type == sf::Event::Closed || sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)){
            window->close();
            exit(EXIT_SUCCESS);
        }
    }
    // move player 1
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)){
        // Check if the spinner is out of the screen
        if((player1->getPosX() - player1->getRadius()) > 10){
            player1->moveLeft();
        }
    }
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)){
        if((player1->getPosX() + player1->getRadius()) < sf::VideoMode::getDesktopMode().width){
            player1->moveRight();
        }
    }
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)){
        if((player1->getPosY() - player1->getRadius()) > 10){
            player1->moveUp();
        }
    }
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)){
        if((player1->getPosY() + player1->getRadius()) < sf::VideoMode::getDesktopMode().height){
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
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)){
        if((player2->getPosX() + player2->getRadius()) < sf::VideoMode::getDesktopMode().width){
            player2->moveRight();
        }
    }
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)){
        if((player2->getPosY() - player2->getRadius()) > 10){
            player2->moveUp();
        }
    }
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)){
        if((player2->getPosY() + player2->getRadius()) < sf::VideoMode::getDesktopMode().height){
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
    // end the current frame
    window->display();  
}

void Party::win(){
    while(!sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)){
        displayWin(window);
        window->display();
    }
}

void Party::lose(){
     while(!sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)){
        displayGameOver(window);
        window->display();
    }
}
