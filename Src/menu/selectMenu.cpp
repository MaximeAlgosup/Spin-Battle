#include "selectMenu.hpp"
#include "display.hpp"


// text options
char playText[] = "Play";
char settingsText[] = "Settings";
char creditsText[] = "Credits";
char exitText[] = "Exit";

SelectMenu::SelectMenu(char* title, char* backgroundPath, char* fontPath, sf::Color fontColor, char* soundPath, char* cursorSpritePath) : Menu(title, backgroundPath, fontPath, fontColor, soundPath){
    this->type = SelectMenuType::PLAY;
    this->cursorSpritePath = cursorSpritePath;
    this->cursorRotation = 0;
}

void SelectMenu::run(sf::RenderWindow *window){
    // Play music
    this->playMusic();
    bool menu = true;
    this->playMusic();
    sf::sleep(sf::milliseconds(50));
    while (menu){
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Enter)){
            switch(this->type){
                case SelectMenuType::PLAY:
                    // Play the game
                    menu = false;
                    break;
                case SelectMenuType::SETTINGS:
                    // Display the settings
                    break;
                case SelectMenuType::CREDITS:
                    // Display the credits
                    break;
                case SelectMenuType::EXIT:
                    // Exit the game
                    window->close();
                    exit(EXIT_SUCCESS);
                    break;
            }
        }
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Down)){
            this->selectOptionDown();
            // cooldown
            sf::sleep(sf::milliseconds(50));
        }
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Up)){
            this->selectOptionUp();
            // cooldown
            sf::sleep(sf::milliseconds(50));
        }

        // Display the menu
        displayMenu(window, this);
        displaySelectOption(window, playText, 50, 150, this);
        displaySelectOption(window, settingsText, 50, 300, this);
        displaySelectOption(window, creditsText, 50, 450, this);
        displaySelectOption(window, exitText, 50, 600, this);
        std::array<int, 2> cursorPosition = this->getSelectedPosition();
        displayMenuCursor(window, this, cursorPosition[0], cursorPosition[1], this->cursorSpritePath);
        window->display();
    }
    // Stop music
    this->stopMusic();
}

void SelectMenu::setType(SelectMenuType type){
    this->type = type;
}

void SelectMenu::setCursorRotation(float cursorRotation){
    this->cursorRotation = cursorRotation;
}

SelectMenuType SelectMenu::getType(){
    return this->type;
}


std::array<int, 2> SelectMenu::getSelectedPosition() {
    std::array<int, 2> result;
    switch(this->type) {
        case SelectMenuType::PLAY:
            result = {50, 150};
            break;
        case SelectMenuType::SETTINGS:
            result = {50, 300};
            break;
        case SelectMenuType::CREDITS:
            result = {50, 450};
            break;
        case SelectMenuType::EXIT:
            result = {50, 600};
            break;
    }
    return result;
}

float SelectMenu::getCursorRotation(){
    return this->cursorRotation;
}


void SelectMenu::selectOptionDown(){
    switch(this->type){
        case SelectMenuType::PLAY:
            this->type = SelectMenuType::SETTINGS;
            break;
        case SelectMenuType::SETTINGS:
            this->type = SelectMenuType::CREDITS;
            break;
        case SelectMenuType::CREDITS:
            this->type = SelectMenuType::EXIT;
            break;
        case SelectMenuType::EXIT:
            this->type = SelectMenuType::PLAY;
            break;
    }
}

void SelectMenu::selectOptionUp(){
    switch(this->type){
        case SelectMenuType::PLAY:
            this->type = SelectMenuType::EXIT;
            break;
        case SelectMenuType::SETTINGS:
            this->type = SelectMenuType::PLAY;
            break;
        case SelectMenuType::CREDITS:
            this->type = SelectMenuType::SETTINGS;
            break;
        case SelectMenuType::EXIT:
            this->type = SelectMenuType::CREDITS;
            break;
    }
}