#pragma once

#include <SFML/Graphics.hpp>
#include "player.hpp"
#include "bot.hpp"
#include "arena.hpp"


class Party{
    private:
        Player *player;
        Bot *bots[5];
        Arena *arena;
        sf::RenderWindow *window;
        
    public:
        
        /*
            Constructor
            params:
                player: the player object
                bots: the bots array
                arena: the arena object
                window: the window object
            return:
                Party object
        */
        Party(Player *player, Bot *bots, Arena *arena, sf::RenderWindow *indow);


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
                void
            return:
                void
        */
        void win();

        /*
            Display player lose
            params:
                void
            return:
                void
        */
        void lose();
};