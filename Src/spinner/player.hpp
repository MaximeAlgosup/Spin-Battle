#pragma once

#include "spinner.hpp"

class Player : public Spinner {
    private:
        int score;
        int level;

    public:

        /*
            Constructor
            params:
                x: x position of the spinner
                y: y position of the spinner
                w: weight of the spinner
                s: max speed of the spinner
                i: max inertia of the spinner
                a: agility of the spinner
            return:
                Player object
        */
        Player(unsigned int x, unsigned int y, int w, int s, int i, int a);

        // Getters

        /*
            Get the score of the player
            params:
                void
            return:
                int: score of the player
        */
        int getScore();

        /*
            Get the level of the player
            params:
                void
            return:
                int: level of the player
        */
        int getLevel();

        // Setters

        /*
            Increase the score of the player
            params:
                points: points to increase the score
            return:
                void
        */
        void scoreUp(int points);

        /*
            Increase the level of the player
            params:
                void
            return:
                void
        */
        void levelUp();
};