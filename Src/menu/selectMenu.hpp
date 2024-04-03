#pragma once
#include <array>
#include "menu.hpp"
#include "credit.hpp"

enum class SelectMenuType{
    PLAY,
    SETTINGS,
    CREDITS,
    EXIT
};

class SelectMenu : public Menu{
    private:
        SelectMenuType type;
        char* cursorSpritePath;
        float cursorRotation;
        Credit *credits;

    public:

        /*
            Constructor
            params:
                title: the title of the menu
                backgroundPath: the path of the background image
                fontPath: the path of the font
                fontColor: the color of the font
                soundPath: the path of the sound
                cursorSpritePath: the path of the cursor sprite
            return:
                SelectMenu object
        */
        SelectMenu(char* title, char* backgroundPath, char* fontPath, sf::Color fontColor, char* soundPath, char* cursorSpritePath);

        /*
            Run the menu
            params:
                window: the window to display the menu
            return:
                void
        */
        void run(sf::RenderWindow *window);

        /*
            Set the type of the menu
            params:
                type: the type of the menu
            return:
                void
        */
        void setType(SelectMenuType type);

        /*
            Set the cursor rotation
            params:
                cursorRotation: the rotation of the cursor
            return:
                void
        */
        void setCursorRotation(float cursorRotation);

        /*
            Get the type of the menu
            params:
                void
            return:
                SelectMenuType
        */
        SelectMenuType getType();


        /*
            Get the selected position
            params:
                void
            return:
                std::array<int, 2>: the selected position
        */
        std::array<int, 2> getSelectedPosition();

        /*
            Get the cursor rotation
            params:
                void
            return:
                float: the rotation of the cursor
        */
        float getCursorRotation();

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

    
};