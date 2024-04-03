#pragma once

#include <SFML/Graphics.hpp>
#include <array>

enum class SettingType{
    STADIUM,
    THEME,
    MUSIC
};

class Setting{

    protected:
        SettingType type;
        int stadiumID;
        int themeID;
        bool isMusicOn;
        bool isDisplay;
        sf::Color fontColor;
        char* fontPath;
        char* backgroundPath;
        char* cursorSpritePath;
        float cursorRotation;


    public:

        /*
            Constructor
            params:
                stadiumID: the id of the stadium
                themeID: the id of the theme
                isMusicOn: the music state
                fontColor: the color of the font
                fontPath: the path of the font
                backgroundPath: the path of the background image
                cursorSpritePath: the path of the cursor sprite
            return:
                Setting object
        */
        Setting(int stadiumID, int themeID, bool isMusicOn, sf::Color fontColor, char* fontPath, char* backgroundPath, char* cursorSpritePath);

        /*
            Constructor
            params:
                fontColor: the color of the font
                fontPath: the path of the font
                backgroundPath: the path of the background image
                cursorSpritePath: the path of the cursor sprite
            return:
                Setting object
        */
        Setting(sf::Color fontColor, char* fontPath, char* backgroundPath, char* cursorSpritePath);


        /*
            Run the setting
            params:
                window: the window to display the setting
            return:
                void
        */
        void run(sf::RenderWindow *window);

        /*
            Get the stadium id
            params:
                void
            return:
                int
        */
        int getStadiumID();

        /*
            Get the theme id
            params:
                void
            return:
                int
        */
        int getThemeID();

        /*
            Get the music state
            params:
                void
            return:
                bool
        */
        bool getIsMusicOn();

        /*
            Get the font color
            params:
                void
            return:
                sf::Color
        */
        sf::Color getFontColor();

        /*
            Get the font path
            params:
                void
            return:
                char*
        */
        char* getFontPath();

        /*
            Get the background path
            params:
                void
            return:
                char*
        */
        char* getBackgroundPath();

        /*
            Get the cursor sprite path
            params:
                void
            return:
                char*
        */
        char* getCursorSpritePath();

        /*
            Get the cursor rotation
            params:
                void
            return:
                float
        */
        float getCursorRotation();

        /*
            Get the selected position
            params:
                void
            return:
                std::array<int, 2>: the selected position
        */
        std::array<int, 2> getSelectedPosition();

        /*
            Set the stadium id
            params:
                stadiumID: the id of the stadium
            return:
                void
        */
        void setStadiumID(int stadiumID);

        /*
            Set the theme id
            params:
                themeID: the id of the theme
            return:
                void
        */
        void setThemeID(int themeID);

        /*
            Set the music state
            params:
                isMusicOn: the music state
            return:
                void
        */
        void setIsMusicOn(bool isMusicOn);

        /*
            Set the cursor rotation
            params:
                cursorRotation: the rotation of the cursor
            return:
                void
        */
        void setRotation(float cursorRotation);


        /*
            Select the option down
            params:
                void
            return:
                void
        */
        void selectOptionDown();

        /*
            Select the option up
            params:
                void
            return:
                void
        */
        void selectOptionUp();

        /*
            Display the setting
            params:
                window: the window to display the setting
            return:
                void
        */
        void displaySettingStates(sf::RenderWindow *window);
};