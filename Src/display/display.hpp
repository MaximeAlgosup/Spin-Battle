#pragma once
#include <SFML/Graphics.hpp>
#include "arena.hpp"
#include "menu.hpp"
#include "selectMenu.hpp"
#include "player.hpp"
#include "bot.hpp"


/*
    Display the menu of the game
    params:
        window: the window to display the menu
        menu: the menu to display
    return:
        void
*/
void displayMenu(sf::RenderWindow *window, Menu *menu);

/*
    Display the menu text
    params:
        window: the window to display the menu text
        menu: the menu to display the menu text
    return:
        void
*/
void displayMenuText(sf::RenderWindow *window, Menu *menu);

/*
    Display the select option of the game
    params:
        window: the window to display the select option
        text: the text to display
        x: the x position of the text
        y: the y position of the text
        menu: the menu to display the select option
    return:
        void
*/
void displaySelectOption(sf::RenderWindow *window, char* text, int x, int y, Menu *menu);

/*
    Display the menu cursor
    params:
        window: the window to display the menu cursor
        menu: the menu to display the menu cursor
        x: the x position of the cursor
        y: the y position of the cursor
        cursorSpritePath: the path of the cursor sprite
    return:
        void
*/
void displayMenuCursor(sf::RenderWindow *window, SelectMenu *menu, int x, int y, char* cursorSpritePath);

/*
    Display the background of the game
    params:
        window: the window to display the background
        arena: the arena to display the background
    return:
        void
*/
void displayBackground(sf::RenderWindow *window, Arena *arena);

/*
    Display the arena
    params:
        window: the window to display the arena
        arena: the arena to display
    return:
        void
*/
void displayArena(sf::RenderWindow *window, Arena *arena);

/*
    Display the score of the player
    params:
        window: the window to display the score
        arena: the arena to display the score
        player: the player to display the score
    return:
        void
*/
void displayScore1(sf::RenderWindow *window, Arena *arena, Player *player);

/*
    Display the score of the player
    params:
        window: the window to display the score
        arena: the arena to display the score
        player: the player to display the score
    return:
        void
*/
void displayScore2(sf::RenderWindow *window, Arena *arena, Player *player);

/*
    Display the time
    params:
        window: the window to display the time
        arena: the arena to display the time
        time: the time to display
    return:
        void
*/
void displayTime(sf::RenderWindow *window, Arena *arena, int time);

/*
    Display the player
    params:
        window: the window to display the player
        player: the player to display
    return:
        void
*/
void displayPlayer(sf::RenderWindow *window, Player *player);

/*
    Display the bot
    params:
        window: the window to display the bot
        bot: the bot to display
    return:
        void
*/
void displayBot(sf::RenderWindow *window, Bot *bot);

/*
    Display the game over screen
    params:
        window: the window to display the game over screen
    return:
        void
*/
void displayGameOver(sf::RenderWindow *window);

/*
    Display the win screen
    params:
        window: the window to display the win screen
        player: the player who win
    return:
        void
*/
void displayWin(sf::RenderWindow *window, int player);


/*
    Display the draw screen
    params:
        window: the window to display the draw screen
    return:
        void
*/
void displayDraw(sf::RenderWindow *window);

/*
    Display the credits
    params:
        window: the window to display the credits
        text: the text to display
        fontPath: the path of the font
        color: the color to display
    return:
        void
*/
void displayCredit(sf::RenderWindow *window, char* text, char *fontPath, sf::Color color);