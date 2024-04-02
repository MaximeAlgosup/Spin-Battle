#include "menu.hpp"
#include "display.hpp"
#include <fstream>
#include <iostream>

Menu::Menu(char* title, char* backgroundPath, char* fontPath, sf::Color fontColor, char* soundPath){
    this->title = title;
    // Check if the background image exists
    if(!std::ifstream(backgroundPath)){
        std::cerr << "Error loading background image" << std::endl;
        exit(EXIT_FAILURE);
    }
    this->backgroundPath = backgroundPath;
    // Check if the font exists
    if(!std::ifstream(fontPath)){
        std::cerr << "Error loading font" << std::endl;
        exit(EXIT_FAILURE);
    }
    this->fontPath = fontPath;
    this->fontColor = fontColor;
    this->soundPath = soundPath;
    if (!music.openFromFile("../Src/assets/musics/beybladeopenning.ogg"))
        exit(EXIT_FAILURE);
    else{
        music.setLoop(true);
    }
}

void Menu::run(sf::RenderWindow *window){
    music.play();
    // Display the menu
    // init objects
    bool printText = true;
    bool menu = true;
    this->playMusic();
    while (menu){
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)){
            window->close();
            exit(EXIT_SUCCESS);
        }
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Enter)){
            menu = false;
        }
        displayMenu(window, this);
        if(printText){
            displayMenuText(window, this);
            printText = false;
        }
        else{
            printText = true;
        }
        
        window->display();
        sf::sleep(sf::seconds(1));
    }
    // Stop music
    this->stopMusic();
}

void Menu::setTitle(char* title){
    this->title = title;
}

void Menu::setBackgroundPath(char* backgroundPath){
    // Check if the background image exists
    if(!std::ifstream(backgroundPath)){
        std::cerr << "Error loading background image" << std::endl;
        exit(EXIT_FAILURE);
    }
    this->backgroundPath = backgroundPath;
}

void Menu::setFontPath(char* fontPath){
    // Check if the font exists
    if(!std::ifstream(fontPath)){
        std::cerr << "Error loading font" << std::endl;
        exit(EXIT_FAILURE);
    }
    this->fontPath = fontPath;
}

void Menu::setFontColor(sf::Color fontColor){
    this->fontColor = fontColor;
}

void Menu::setSoundPath(char* soundPath){
    this->soundPath = soundPath;
    if (!music.openFromFile(soundPath))
        exit(EXIT_FAILURE);
    else{
        music.setLoop(true);
    }
}

char* Menu::getTitle(){
    return this->title;
}

char* Menu::getBackgroundPath(){
    return this->backgroundPath;
}

char* Menu::getFontPath(){
    return this->fontPath;
}

sf::Color Menu::getFontColor(){
    return this->fontColor;
}

char* Menu::getSoundPath(){
    return this->soundPath;
}

void Menu::playMusic(){
    music.play();
}

void Menu::stopMusic(){
    music.stop();
}