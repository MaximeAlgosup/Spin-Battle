#pragma once

#include "spinner.hpp"

class Bot : public Spinner {
    private:
        int level;
        bool inGame;

    public:

        /*
            Constructor
            params:
                level: level of the bot
                ig: inGame status of the bot
                x: x position of the spinner
                y: y position of the spinner
                w: weight of the spinner
                s: max speed of the spinner
                a: agility of the spinner
            return:
                Bot object
        */
        Bot(int level, bool ig, unsigned int x, unsigned int y, int w, int s, int a);


        /*
            Move the bot
            params:
                void
            return:
                void
        */
        void move();

        // Getters

        /*
            Get the inGame status of the bot
            params:
                void
            return:
                bool: inGame status of the bot
        */
        bool getInGame();

        // Setters

        /*
            Set the inGame status of the bot
            params:
                inGame: inGame status of the bot
            return:
                void
        */
        void setInGame(bool inGame);
};