#include <iostream>
#include <SFML/Graphics.hpp>

#include "display.hpp"
#include "arena.hpp"
#include "spinner.hpp"

#define ARENA_RADIUS 300

int main()
{
    // init window
    sf::RenderWindow window(sf::VideoMode(1920, 1080), "Spin-Battle", sf::Style::Fullscreen);
    // init objects
    Arena arena((sf::VideoMode::getDesktopMode().width/2), (sf::VideoMode::getDesktopMode().height/2), ARENA_RADIUS, 1, 0);

    Spinner spinner(arena.getCenterX(), arena.getCenterY(), 10, 10, 10);
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
            if((spinner.getPosX() - spinner.getRadius()) > 10){
                spinner.moveLeft();
            }
        }
        else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right) || sf::Keyboard::isKeyPressed(sf::Keyboard::D)){
            if((spinner.getPosX() + spinner.getRadius()) < sf::VideoMode::getDesktopMode().width){
                spinner.moveRight();
            }
        }
        else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up) || sf::Keyboard::isKeyPressed(sf::Keyboard::W)){
            if((spinner.getPosY() - spinner.getRadius()) > 10){
                spinner.moveUp();
            }
        }
        else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down) || sf::Keyboard::isKeyPressed(sf::Keyboard::S)){
            if((spinner.getPosY() + spinner.getRadius()) < sf::VideoMode::getDesktopMode().height){
                spinner.moveDown();
            }
        }
        // Actions
        arena.setSize();

        // Checker
        if(spinner.isOut(arena.getCenterX(), arena.getCenterY(), arena.getRadius())){
            displayGameOver(window);
            window.display();
            break;
        }


        // Draws
        displayBackground(window);
        displayArena(window, arena);
        displaySpinner(window, spinner);
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
