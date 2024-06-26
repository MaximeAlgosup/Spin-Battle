#pragma once

#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>

class Arena {
    protected:
        int center_x, center_y;
        int radius;
        int level;
        int score;
        char* themePath;
        int themeID;
        char* stadiumPath;
        int stadiumID;
        char* fontPath;
        sf::Color fontColor;
        char* soundPath;
        sf::Music music;

    public:
    /*
    Arena class constructor
    params:
        x: x coordinate of the center of the arena
        y: y coordinate of the center of the arena
        r: radius of the arena
        l: level of the arena
        s: score of the arena
        themePath: path to the background image
        stadiumPath: path to the theme
        fontPath: path to the font
        fontColor: color of the font
        soundPath: path to the sound
    return:
        Arena object
    */
    Arena(int x, int y, int r, int l, int s, char* themePath, char* stadiumPath, char* fontPath, sf::Color fontColor, char* soundPath);

    /*
    Get the position of the center of the arena in x coordinate
    params:
        void
    return:
        int: x coordinate of the center of the arena
    */
    int getCenterX();

    /*
    Get the position of the center of the arena in y coordinate
    params:
        void
    return:
        int: y coordinate of the center of the arena
    */
    int getCenterY();

    /*
    Get the radius of the arena
    params:
        void
    return:
        int: radius of the arena
    */
    int getRadius();

    /*
    Get the level of the arena
    params:
        void
    return:
        int: level of the arena
    */
    int getLevel();

    /*
    Get the score of the arena
    params:
        void

    return:
        int: score of the arena
    */
    int getScore();

    /*
    Get the path to the background image
    params:
        void
    return:
        char*: path to the background image
    */
    char* getThemePath();

    /*
    Get the ID of the theme
    params:
        void
    return:
        int: ID of the theme
    */
    int getThemeID();

    /*
    Get the path to the theme
    params:
        void
    return:
        char*: path to the theme
    */
    char* getStadiumPath();

    /*
    Get the ID of the stadium
    params:
        void
    return:
        int: ID of the stadium
    */
   int getStadiumID();

    /*
    Get the path to the font
    params:
        void
    return:
        char*: path to the font
    */
    char* getFontPath();

    /*
    Get the color of the font
    params:
        void
    return:
        sf::Color: color of the font
    */
    sf::Color getFontColor();

    /*
    Get the path to the sound
    params:
        void
    return:
        char*: path to the sound
    */
    char* getSoundPath();

    // Setters

    /*
        Set arena size based on the level
        params:
            void
        return:
            int: size of the arena
    */
    int setSize();

    /*
        Set the path to the background image
        params:
            backgroundPath: path to the background image
        return:
            void
    */
    void setThemePath(char* ThemePath);

    /*
        Set the ID of the theme
        params:
            themeID: ID of the theme
        return:
            void
    */
    void setThemeID(int themeID);

    /*
        Set the path to the theme
        params:
            themePath: path to the theme
        return:
            void
    */
    void setStadiumPath(char* themePath);

    /*
        Set the ID of the stadium
        params:
            stadiumID: ID of the stadium
        return:
            void
    */
    void setStadiumID(int stadiumID);

    /*
        Set the path to the font
        params:
            fontPath: path to the font
        return:
            void
    */
    void setFontPath(char* fontPath);

    /*
        Set the color of the font
        params:
            fontColor: color of the font
        return:
            void
    */
    void setFontColor(sf::Color fontColor);

    /*
        Set the path to the sound
        params:
            soundPath: path to the sound
        return:
            void
    */
    void setSoundPath(char* soundPath);


    /*
        Increase the level of the arena
        params:
            void
        return:
            int: new level of the arena
    */
    int levelUp();

    /*
        Increase the score of the arena
        params:
            points: points to add to the score
        return:
            int: new score of the arena
    */
    int scoreUp(int points);

    /*
        Play the music of the arena
        params:
            void
        return:
            void
    */
    void playMusic();

    /*
        Stop the music of the arena
        params:
            void
        return:
            void
    */
    void stopMusic();

};


