#include "menu.hpp"
#include <iostream>

Menu::Menu(char* title, char* backgroundPath, char* fontPath, char* fontColor, char* soundPath){
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

void Menu::setFontColor(char* fontColor){
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

char* Menu::getFontColor(){
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