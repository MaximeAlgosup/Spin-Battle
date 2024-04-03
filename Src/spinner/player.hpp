#pragma once

#include "spinner.hpp"
#include <SFML/Graphics.hpp>

class Player : public Spinner {
    private:
        int score;
        int level;
        sf::Color ringColor;
        char* spritePath;

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
                rc: color of the ring
                spritePath: path to the sprite
            return:
                Player object
        */
        Player(unsigned int x, unsigned int y, int w, int s, int i, int a, sf::Color rc, char* spritePath);

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

        /*
            Get the path to the sprite
            params:
                void
            return:
                char*: path to the sprite
        */
        char* getSpritePath();

        /*
            Get the color of the ring
            params:
                void
            return:
                sf::Color: color of the ring
        */
        sf::Color getRingColor();

        // Setters

        /*
            Set if the player is dead
            params:
                dead: true if the player is dead, false otherwise
            return:
                void
        */
        void setDead(bool dead);

        /*
            Set the path to the sprite
            params:
                spritePath: path to the sprite
            return:
                void
        */
        void setSpritePath(char* spritePath);

        /*
            Increase the score of the player
            params:
                points: points to increase the score
            return:
                void
        */
        void scoreUp(int points);


        /*
            Reset the score of the player
            params:
                void
            return:
                void
        */
        void resetScore();

        /*
            Increase the level of the player
            params:
                void
            return:
                void
        */
        void levelUp();
};