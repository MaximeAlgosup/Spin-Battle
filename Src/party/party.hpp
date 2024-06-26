#pragma once

#include <SFML/Graphics.hpp>
#include "player.hpp"
#include "arena.hpp"
#include "setting.hpp"
#include <SFML/Audio.hpp>

class Party{
    private:
        Player *player1;
        Player *player2;
        Arena *arena;
        sf::RenderWindow *window;
        int time;
        bool inGame;
        sf::SoundBuffer buffer;
        sf::Sound sound;
        int remRound;
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
                settings: the settings object
            return:
                void
        */
        void run(Setting *settings);

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

        /*
            Play the contact sound
            params:
                isMusicOn: the music state
            return:
                void
        */
        void contactSound(bool isMusicOn);

        /*
            Display the final result
            params:
                void
            return:
                void
        */
        void finalResult();
};