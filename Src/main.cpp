#include <iostream>
#include "player.hpp"
#include "bot.hpp"
#include "arena.hpp"
#include "display.hpp"
#include <SFML/Audio.hpp>

#define ARENA_RADIUS 300

int main()
{
    // init window
    sf::RenderWindow window(sf::VideoMode(1920, 1080), "Spin-Battle", sf::Style::Fullscreen);
    // init objects
    bool printText = true;
    bool menu = true;
    sf::Music music;
    if (!music.openFromFile("../Src/assets/musics/beybladeopenning.ogg"))
        exit(EXIT_FAILURE);
    else{
        music.setLoop(true);
        music.play();
    }
    while(menu){
        // Events
        sf::Event event;
        while (window.pollEvent(event)){
            // "close requested" event: we close the window
            if (event.type == sf::Event::Closed || sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)){
                window.close();
                exit(EXIT_SUCCESS);
            }
            if(sf::Keyboard::isKeyPressed(sf::Keyboard::Enter)){
                menu = false;
            }
        }
        displayMenu(window);
        if(printText){
            displayMenuText(window);
            printText = false;
        }
        else{
            printText = true;
        }
        
        window.display();
        sf::sleep(sf::seconds(1));
    }
    music.stop();
    if (!music.openFromFile("../Src/assets/musics/battle.ogg"))
        exit(EXIT_FAILURE);
    else{
        music.setLoop(true);
        music.play();
    }
    Arena arena((sf::VideoMode::getDesktopMode().width/2), (sf::VideoMode::getDesktopMode().height/2), ARENA_RADIUS, 1, 0);

    Player player(arena.getCenterX(), arena.getCenterY(), 15, 15, 10000, 5);
    Bot bots[] = {
        Bot(4, true, arena.getCenterX()-120, arena.getCenterY(), 10, 5, 20000, 5),
        Bot(4, true, arena.getCenterX(), arena.getCenterY()-120, 10, 5, 20000, 5),
        Bot(4, true, arena.getCenterX()+120, arena.getCenterY(), 10, 5, 20000, 5),
        Bot(4, true, arena.getCenterX(), arena.getCenterY()+120, 10, 5, 20000, 5),
        Bot(4, true, arena.getCenterX()+120, arena.getCenterY()-180, 10, 5, 20000, 5)
    };
    // main loop
    while (window.isOpen()){
        // Events
        sf::Event event;
        while (window.pollEvent(event)){
            // "close requested" event: we close the window
            if (event.type == sf::Event::Closed || sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)){
                window.close();
                exit(EXIT_SUCCESS);
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
            if(asTarget){
                continue;
            }
            else{
                bots[i].autoMove();
            }
        }

        // Checker

        
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
    }
    while(!sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)){
        displayGameOver(window);
        window.display();
    }
    return 0;
}
