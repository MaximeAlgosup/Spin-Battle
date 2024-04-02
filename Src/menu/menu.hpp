#pragma once

#include <SFML/Audio.hpp>

class Menu{

    private:
        char* title;
        char* backgroundPath;
        char* fontPath;
        char* fontColor;
        char* soundPath;
        sf::Music music;

    public:

        /*
            Constructor
            params:
                title: the title of the menu
                backgroundPath: the path of the background image
                fontPath: the path of the font
                fontColor: the color of the font
                soundPath: the path of the sound
            return:
                Menu object
        */
        Menu(char* title, char* backgroundPath, char* fontPath, char* fontColor, char* soundPath);

        // Getters and Setters

        /*
            Set the title of the menu
            params:
                title: the title of the menu
            return:
                void
        */
        void setTitle(char* title);

        /*
            Set the background path of the menu
            params:
                backgroundPath: the path of the background image
            return:
                void
        */
        void setBackgroundPath(char* backgroundPath);

        /*
            Set the font path of the menu
            params:
                fontPath: the path of the font
            return:
                void
        */
        void setFontPath(char* fontPath);

        /*
            Set the font color of the menu
            params:
                fontColor: the color of the font
            return:
                void
        */
        void setFontColor(char* fontColor);

        /*
            Set the sound path of the menu
            params:
                soundPath: the path of the sound
            return:
                void
        */
        void setSoundPath(char* soundPath);

        /*
            Get the title of the menu
            params:
                void
            return:
                char*: the title of the menu
        */
        char* getTitle();

        /*
            Get the background path of the menu
            params:
                void
            return:
                char*: the path of the background image
        */
        char* getBackgroundPath();

        /*
            Get the font path of the menu
            params:
                void
            return:
                char*: the path of the font
        */
        char* getFontPath();

        /*
            Get the font color of the menu
            params:
                void
            return:
                char*: the color of the font
        */
        char* getFontColor();

        /*
            Get the sound path of the menu
            params:
                void
            return:
                char*: the path of the sound
        */
        char* getSoundPath();

        /*
            Play the sound of the menu
            params:
                void
            return:
                void
        */
        void playSound();

        /*
            Stop the sound of the menu
            params:
                void
            return:
                void
        */
        void stopSound();

};