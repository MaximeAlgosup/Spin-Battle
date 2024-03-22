#include <iostream>
#include <SFML/Graphics.hpp>

#include "display.hpp"

#define ARENA_RADIUS 300

int main()
{
    // init window
    sf::RenderWindow window(sf::VideoMode(200, 200), "Spin-Battle", sf::Style::Fullscreen);
    // init objects
    Arena arena((sf::VideoMode::getDesktopMode().width/2), (sf::VideoMode::getDesktopMode().height/2), ARENA_RADIUS, 1, 0);

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
        // Actions
        arena.setSize();

        // Draws
        displayBackground(window);
        displayArena(window, arena);
        displayScore(window, arena);
        displayLevel(window, arena);

        // end the current frame
        window.display();
    }
    return 0;
}
