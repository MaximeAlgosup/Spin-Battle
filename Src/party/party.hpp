#pragma once

#include <SFML/Graphics.hpp>
#include "player.hpp"
#include "arena.hpp"


class Party{
    private:
        Player *player1;
        Player *player2;
        Arena *arena;
        sf::RenderWindow *window;
        int time;
        bool inGame;
    public:
        
        /*
            Constructor
            params:
                player1: the player object
                player2: the player object
                arena: the arena object
                window: the window object
            return:
                Party object
        */
        Party(Player *player1, Player *player2, Arena *arena, sf::RenderWindow *window);

        /*
            Constructor
            params:
                player1: the player object
                player2: the player object
                arena: the arena object
                window: the window object
                time: the time of the party
            return:
                Party object
        */
        Party(Player *player1, Player *player2, Arena *arena, sf::RenderWindow *window, int time);


        /*
            Run the party
            params:
                void
            return:
                void
        */
        void run();

        /*
            Handle the keybord event
            params:
                void
            return:
                void
        */
        void keybordEvent();

        /*
            Update the party
            params:
                void
            return:
                void
        */
        void update();

        /*
            Display player win
            params:
                player: the player number
            return:
                void
        */
        void win(int player);

        /*
            Display players equality
            params:
                void
            return:
                void
        */
        void equality();

};