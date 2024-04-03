#include "setting.hpp"
#include "display.hpp"

char stadiumText[] = "Stadium";
char themeText[] = "Theme";
char musicText[] = "Music";

Setting::Setting(int stadiumID, int themeID, bool isMusicOn, sf::Color fontColor, char* fontPath, char* backgroundPath, char* cursorSpritePath){
    this->stadiumID = stadiumID;
    this->themeID = themeID;
    this->isMusicOn = isMusicOn; 
    this->type = SettingType::STADIUM;
    this->fontColor = fontColor;
    this->fontPath = fontPath;
    this->backgroundPath = backgroundPath;
    this->cursorSpritePath = cursorSpritePath;
    this->cursorRotation = 0;
}

Setting::Setting(sf::Color fontColor, char* fontPath, char* backgroundPath, char* cursorSpritePath){
    this->stadiumID = 1;
    this->themeID = 1;
    this->isMusicOn = true;
    this->type = SettingType::STADIUM;
    this->fontColor = fontColor;
    this->fontPath = fontPath;
    this->backgroundPath = backgroundPath;
    this->cursorSpritePath = cursorSpritePath;
    this->cursorRotation = 0;
}

void Setting::run(sf::RenderWindow *window){
    this->isDisplay = true;
    displaySetting(window, this);
    displaySettingOption(window, this, stadiumText, 50, 150);
    displaySettingOption(window, this, themeText, 50, 300);
    displaySettingOption(window, this, musicText, 50, 450);
    std::array<int, 2> cursorPosition = this->getSelectedPosition();
    displaySettingCursor(window, this, cursorPosition[0], cursorPosition[1], this->cursorSpritePath);
    window->display(); 
    // Display the setting
    while (this->isDisplay){
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Enter)){
            if(this->type == SettingType::MUSIC){
                this->isMusicOn = !this->isMusicOn;
            }
            sf::sleep(sf::milliseconds(50));
        }
        else if(this->type == SettingType::STADIUM && sf::Keyboard::isKeyPressed(sf::Keyboard::Left)){
            if(this->stadiumID > 1){
                this->stadiumID -= 1;
                sf::sleep(sf::milliseconds(50));
            }
        }
        else if(this->type == SettingType::STADIUM && sf::Keyboard::isKeyPressed(sf::Keyboard::Right)){
            if(this->stadiumID < 3){
                this->stadiumID += 1;
                sf::sleep(sf::milliseconds(50));
            }
        }
        else if(this->type == SettingType::THEME && sf::Keyboard::isKeyPressed(sf::Keyboard::Left)){
            if(this->themeID > 1){
                this->themeID -= 1;
                sf::sleep(sf::milliseconds(50));
            }
        }
        else if(this->type == SettingType::THEME && sf::Keyboard::isKeyPressed(sf::Keyboard::Right)){
            if(this->themeID < 3){
                this->themeID += 1;
                sf::sleep(sf::milliseconds(50));
            }
        }
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Down)){
            this->selectOptionDown();
            sf::sleep(sf::milliseconds(50));
        }
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Up)){
            this->selectOptionUp();
            sf::sleep(sf::milliseconds(50));
        }
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)){
            this->isDisplay = false;
        }
        displaySetting(window, this);
        displaySettingOption(window, this, stadiumText, 50, 150);
        displaySettingOption(window, this, themeText, 50, 300);
        displaySettingOption(window, this, musicText, 50, 450);
        std::array<int, 2> cursorPosition = this->getSelectedPosition();
        displaySettingCursor(window, this, cursorPosition[0], cursorPosition[1], this->cursorSpritePath);
        this->displaySettingStates(window);
        window->display(); 
    }
    
}

int Setting::getStadiumID(){
    return this->stadiumID;
}

int Setting::getThemeID(){
    return this->themeID;
}

bool Setting::getIsMusicOn(){
    return this->isMusicOn;
}

sf::Color Setting::getFontColor(){
    return this->fontColor;
}

char* Setting::getFontPath(){
    return this->fontPath;
}

char* Setting::getBackgroundPath(){
    return this->backgroundPath;
}

char* Setting::getCursorSpritePath(){
    return this->cursorSpritePath;
}

float Setting::getCursorRotation(){
    return this->cursorRotation;
}

std::array<int, 2> Setting::getSelectedPosition(){
    std::array<int, 2> position;
    switch(this->type){
        case SettingType::STADIUM:
            position = {50, 150};
            break;
        case SettingType::THEME:
            position = {50, 300};
            break;
        case SettingType::MUSIC:
            position = {50, 450};
            break;
    }
    return position;
}

void Setting::setStadiumID(int stadiumID){
    this->stadiumID = stadiumID;
}

void Setting::setThemeID(int themeID){
    this->themeID = themeID;
}

void Setting::setIsMusicOn(bool isMusicOn){
    this->isMusicOn = isMusicOn;
}

void Setting::setRotation(float cursorRotation){
    this->cursorRotation = cursorRotation;
}

void Setting::selectOptionDown(){
    switch(this->type){
        case SettingType::STADIUM:
            this->type = SettingType::THEME;
            break;
        case SettingType::THEME:
            this->type = SettingType::MUSIC;
            break;
        case SettingType::MUSIC:
            this->type = SettingType::STADIUM;
            break;
    }
}

void Setting::selectOptionUp(){
    switch(this->type){
        case SettingType::STADIUM:
            this->type = SettingType::MUSIC;
            break;
        case SettingType::THEME:
            this->type = SettingType::STADIUM;
            break;
        case SettingType::MUSIC:
            this->type = SettingType::THEME;
            break;
    }
}

void Setting::displaySettingStates(sf::RenderWindow *window){
    switch(this->type){
        case SettingType::STADIUM:
            displayStadiumState(window, this);
            break;
        case SettingType::THEME:
            displayThemeState(window, this);
            break;
        case SettingType::MUSIC:
            displaySoundState(window, this);
            break;
    }
}