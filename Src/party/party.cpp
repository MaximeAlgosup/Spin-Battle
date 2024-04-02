#include "party.hpp"
#include "display.hpp"
#include <iostream>
#include <SFML/Graphics.hpp>

Party::Party(Player *player, Bot *bots, Arena *arena, sf::RenderWindow *window){
    this->player = player;
    for(int i = 0; i < 5; i++){
        this->bots[i] = &bots[i];
    }
    this->arena = arena;
    this->window = window;
}

void Party::run(){
    while(window->isOpen()){
        // Events
        keybordEvent();
        // Actions
        this->arena->setSize();

        // visual update
        update();

        // Check if player win or lose
        bool isWin = true;
        for(int i = 0; i < 5; i++){
            if(bots[i]->getIsDead() == false){
                isWin = false;
            }
        }
        if(isWin){
            win();
        }
        if(player->getIsDead()){
            lose();
        }
    }
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
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left) || sf::Keyboard::isKeyPressed(sf::Keyboard::A)){
        // Check if the spinner is out of the screen
        if((player->getPosX() - player->getRadius()) > 10){
            player->moveLeft();
        }
    }
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right) || sf::Keyboard::isKeyPressed(sf::Keyboard::D)){
        if((player->getPosX() + player->getRadius()) < sf::VideoMode::getDesktopMode().width){
            player->moveRight();
        }
    }
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up) || sf::Keyboard::isKeyPressed(sf::Keyboard::W)){
        if((player->getPosY() - player->getRadius()) > 10){
            player->moveUp();
        }
    }
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down) || sf::Keyboard::isKeyPressed(sf::Keyboard::S)){
        if((player->getPosY() + player->getRadius()) < sf::VideoMode::getDesktopMode().height){
            player->moveDown();
        }
    }
    else{
        player->autoMove();
    }
}


void Party::update(){
    // Draws
        displayBackground(window);
        displayArena(window, arena);
        for(int i = 0; i < 5; i++){
            if(!bots[i]->getIsDead()){
                displayBot(window, bots[i]);
            }
        }
        displayPlayer(window, player);
        displayScore(window, arena);
        displayLevel(window, arena);

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
