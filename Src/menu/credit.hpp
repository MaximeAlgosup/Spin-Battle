#pragma once

#include <SFML/Graphics.hpp>

class Credit{
    private:
        char* text;
        bool isDisplay;
    public:
        /*
            Constructor
            params:
                window: the window object
            return:
                credit object
        */
        Credit(char* text);

        /*
            Run the credit
            params:
                window: the window object
                fontPath: the font path
                color: the color object
            return:
                void
        */
        void run(sf::RenderWindow *window, char *fontPath, sf::Color color);

        /*
            Get the text
            params:
                void
            return:
                char*: the text
        */
        char *getText();
};