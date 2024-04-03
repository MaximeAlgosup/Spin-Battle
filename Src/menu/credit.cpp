#include "credit.hpp"
#include "display.hpp"

Credit::Credit(char* text){
    this->text = text;
    this->isDisplay = true;
}

void Credit::run(sf::RenderWindow *window, char *fontPath, sf::Color color){
    sf::sleep(sf::milliseconds(200));
    while(this->isDisplay){
       if(sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)){
            this->isDisplay = false;
        }

        // Display the credit
        displayCredit(window, this->getText(), fontPath, color);
        window->display();
    }
    this->isDisplay = true;
    return;
}

char* Credit::getText(){
    return this->text;
}

