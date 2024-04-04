#include <iostream>
#include "player.hpp"
#include "arena.hpp"
#include "party.hpp"
#include "menu.hpp"
#include "selectMenu.hpp"
#include "display.hpp"
#include "setting.hpp"
#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>

#define ARENA_RADIUS 400

// Texts
#define TITLE "Spin-Battle"
char menuTitle[] = "Press Enter to Start";
char selectMenuTitle[] = "Select an option";

// Backgrounds
char menuBackgroundPath[] = "../Src/assets/pictures/menu.jpg";
char selectMenuBackgroundPath[] = "../Src/assets/pictures/selectMenu.jpg";
char stadiumPath[] = "../Src/assets/pictures/stadium1.png";
char ThemePath[] = "../Src/assets/pictures/theme1.png";

// Sprites
char player1SpritePath[] = "../Src/assets/sprites/ldrago.png";
char player2SpritePath[] = "../Src/assets/sprites/pegasus.png";

// Musics
char menuMusicPath[] = "../Src/assets/musics/menu.ogg";
char selectMenuMusicPath[] = "../Src/assets/musics/selectMenu.ogg";
char arenaMusicPath[] = "../Src/assets/musics/battle.ogg";

// Fonts
char fontPath[] = "../Src/assets/fonts/LoveDays-2v7Oe.ttf";


int main()
{
    // init window
    sf::RenderWindow window(sf::VideoMode(1920, 1080), TITLE, sf::Style::Fullscreen);

    // init menu
    Menu menu(menuTitle, menuBackgroundPath, fontPath, sf::Color{39, 1, 0, 255}, menuMusicPath);
    menu.run(&window);

    // init settings
    Setting settings(sf::Color{39, 1, 0, 255}, fontPath, selectMenuBackgroundPath, player1SpritePath);
    Setting *settingsPtr = &settings;

    while (true)
    {
        // init arena
        Arena arena((window.getSize().x/2), (window.getSize().y/2), ARENA_RADIUS, 1, 0, ThemePath, stadiumPath, fontPath, sf::Color::White, arenaMusicPath);

        // init players
        Player player1(arena.getCenterX()+70, arena.getCenterY(), 15, 30, 7000, 20, sf::Color::Red, player1SpritePath);
        Player player2(arena.getCenterX()-70, arena.getCenterY(), 15, 30, 7000, 20, sf::Color::Blue, player2SpritePath);


        // init select menu
        SelectMenu selectMenu(selectMenuTitle, selectMenuBackgroundPath, fontPath, sf::Color{39, 1, 0, 255}, selectMenuMusicPath, player1SpritePath);
        selectMenu.setSetting(settingsPtr);
        selectMenu.run(&window, &arena);

        settingsPtr = selectMenu.getSetting();

        // init party
        Party party(&player1, &player2, &arena, &window);
        party.run(settingsPtr);
    }
    
    exit(EXIT_SUCCESS);
}
