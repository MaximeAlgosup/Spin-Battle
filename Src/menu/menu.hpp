#pragma once

#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>

class Menu{

    protected:
        char* title;
        char* backgroundPath;
        char* fontPath;
        sf::Color fontColor;
        char* soundPath;
        sf::Music music;
        bool isMusicPlaying;

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
        Menu(char* title, char* backgroundPath, char* fontPath, sf::Color fontColor, char* soundPath);

        /*
            Run the menu
            params:
                window: the window to display the menu
            return:
                void
        */
        void run(sf::RenderWindow *window);
        
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
        void setFontColor(sf::Color fontColor);

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
                sf::Color: the color of the font
        */
        sf::Color getFontColor();

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
        void playMusic();

        /*
            Stop the sound of the menu
            params:
                void
            return:
                void
        */
        void stopMusic();

        /*
            Pause the sound of the menu
            params:
                void
            return:
                void
        */
        void pauseMusic();
};