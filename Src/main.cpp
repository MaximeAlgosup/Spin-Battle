#include <iostream>
#include <SFML/Graphics.hpp>

#include "display.hpp"
#include "arena.hpp"
#include "player.hpp"
#include "bot.hpp"

#define ARENA_RADIUS 300

int main()
{
    // init window
    sf::RenderWindow window(sf::VideoMode(1920, 1080), "Spin-Battle", sf::Style::Fullscreen);
    // init objects
    Arena arena((sf::VideoMode::getDesktopMode().width/2), (sf::VideoMode::getDesktopMode().height/2), ARENA_RADIUS, 1, 0);

    Player player(arena.getCenterX(), arena.getCenterY(), 10, 5, 5);
    Bot bots[] = {
        Bot(1, true, arena.getCenterX()-120, arena.getCenterY(), 10, 5, 5),
        Bot(2, true, arena.getCenterX(), arena.getCenterY()-120, 10, 5, 5),
        Bot(3, true, arena.getCenterX()+120, arena.getCenterY(), 10, 5, 5),
        Bot(4, true, arena.getCenterX(), arena.getCenterY()+120, 10, 5, 5),
        Bot(5, true, arena.getCenterX()+120, arena.getCenterY()-180, 10, 5, 5)
    };
    // main loop
    while (window.isOpen()){
        // Events
        sf::Event event;
        while (window.pollEvent(event)){
            // "close requested" event: we close the window
            if (event.type == sf::Event::Closed || sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)){
                window.close();
            }
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left) || sf::Keyboard::isKeyPressed(sf::Keyboard::A)){
            // Check if the spinner is out of the screen
            if((player.getPosX() - player.getRadius()) > 10){
                player.moveLeft();
            }
        }
        else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right) || sf::Keyboard::isKeyPressed(sf::Keyboard::D)){
            if((player.getPosX() + player.getRadius()) < sf::VideoMode::getDesktopMode().width){
                player.moveRight();
            }
        }
        else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up) || sf::Keyboard::isKeyPressed(sf::Keyboard::W)){
            if((player.getPosY() - player.getRadius()) > 10){
                player.moveUp();
            }
        }
        else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down) || sf::Keyboard::isKeyPressed(sf::Keyboard::S)){
            if((player.getPosY() + player.getRadius()) < sf::VideoMode::getDesktopMode().height){
                player.moveDown();
            }
        }
        else{
            player.autoMove();
        }
        // Actions
        arena.setSize();
        // Bots moves
        for(int i = 0; i < 5; i++){
            bool asTarget = false;
            if(bots[i].isClose(player)){
                std::cout << "target" << std::endl;
                bots[i].target(player);
                asTarget = true;
            }
            else{
                for(int j = 0; j < 5; j++){
                    if(i != j){
                        if(bots[i].isClose(bots[j])){
                            bots[i].target(bots[j]);
                            asTarget = true;
                        }
                    }
                }
            }
            if(!asTarget){
                bots[i].autoMove();
            }
        }

        // Checker

        // Check if the player is out of the arena
        if(player.isOut(arena.getCenterX(), arena.getCenterY(), arena.getRadius())){
            displayGameOver(window);
            window.display();
            break;
        }
        // Check if the bots are out of the screen
        for(int i = 0; i < 5; i++){
            if(bots[i].isOut(arena.getCenterX(), arena.getCenterY(), arena.getRadius()) && bots[i].getInGame()){
                arena.levelUp();
                arena.scoreUp(10);
                bots[i].setInGame(false);
            }
        }
        // Check if there is a collision between the player and the bots
        for(int i = 0; i < 5; i++){
            if(player.isColliding(bots[i])){
                player.contact(&bots[i]);
            }
        }
        
        // Check if there is a collision between the bots
        for(int i = 0; i < 5; i++){
            for(int j = 0; j < 5; j++){
                if(i != j){
                    if(bots[i].isColliding(bots[j])){
                        bots[i].contact(&bots[j]);
                    }
                }
            }
        }


        // Draws
        displayBackground(window);
        displayArena(window, arena);
        for(int i = 0; i < 5; i++){
            if(!bots[i].getIsDead()){
                displayBot(window, bots[i]);
            }
        }
        displayPlayer(window, player);
        displayScore(window, arena);
        displayLevel(window, arena);

        // end the current frame
        window.display();
    }
    while(!sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)){
        displayGameOver(window);
        window.display();
    }
    return 0;
}
