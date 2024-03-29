#pragma once
#include <SFML/Graphics.hpp>
#include "arena.hpp"
#include "player.hpp"
#include "bot.hpp"

/*
    Display the background of the game
    params:
        window: the window to display the background
    return:
        void
*/
void displayBackground(sf::RenderWindow &window);

/*
    Display the arena
    params:
        window: the window to display the arena
        arena: the arena to display
    return:
        void
*/
void displayArena(sf::RenderWindow &window, Arena &arena);

/*
    Display the score of the player
    params:
        window: the window to display the score
        arena: the arena to display the score
    return:
        void
*/
void displayScore(sf::RenderWindow &window, Arena &arena);

/*
    Display the level of the player
    params:
        window: the window to display the level
        arena: the arena to display the level
    return:
        void
*/
void displayLevel(sf::RenderWindow &window, Arena &arena);

/*
    Display the player
    params:
        window: the window to display the player
        player: the player to display
    return:
        void
*/
void displayPlayer(sf::RenderWindow &window, Player &player);

/*
    Display the bot
    params:
        window: the window to display the bot
        bot: the bot to display
    return:
        void
*/
void displayBot(sf::RenderWindow &window, Bot &bot);

/*
    Display the game over screen
    params:
        window: the window to display the game over screen
    return:
        void
*/
void displayGameOver(sf::RenderWindow &window);