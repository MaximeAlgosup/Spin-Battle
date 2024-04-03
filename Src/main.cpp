#include <iostream>
#include "player.hpp"
#include "arena.hpp"
#include "party.hpp"
#include "menu.hpp"
#include "display.hpp"
#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>

#define ARENA_RADIUS 400
#define TITLE "Spin-Battle"
char menuTitle[] = "Press Enter to Start the 206 turbo";
char menuBackgroundPath[] = "../Src/assets/pictures/beybladeswllpp.jpg";
char menuMusicPath[] = "../Src/assets/musics/beybladeopenning.ogg";
char arenaBackgroundPath[] = "../Src/assets/pictures/space.png";
char arenaThemePath[] = "../Src/assets/pictures/alan.jpg";
char arenaMusicPath[] = "../Src/assets/musics/battle.ogg";
char fontPath[] = "../Src/assets/fonts/LoveDays-2v7Oe.ttf";
char player1SpritePath[] = "../Src/assets/pictures/ldrago.png";
char player2SpritePath[] = "../Src/assets/pictures/pegasus.png";

int main()
{
    // init window
    // sf::RenderWindow window(sf::VideoMode(1920, 1080), TITLE, sf::Style::Fullscreen);
    sf::RenderWindow window(sf::VideoMode(1920, 1080), TITLE);

    // init menu
    Menu menu(menuTitle, menuBackgroundPath, fontPath, sf::Color::White, menuMusicPath);
    menu.run(&window);

    // init arena
    Arena arena((sf::VideoMode::getDesktopMode().width/2), (sf::VideoMode::getDesktopMode().height/2), ARENA_RADIUS, 1, 0, arenaBackgroundPath, arenaThemePath, fontPath, sf::Color::White, arenaMusicPath);

    // init players
    Player player1(arena.getCenterX()-70, arena.getCenterY(), 15, 15, 10000, 5, sf::Color::Red, player1SpritePath);
    Player player2(arena.getCenterX()+70, arena.getCenterY(), 15, 15, 10000, 5, sf::Color::Blue, player2SpritePath);

    // init party
    Party party(&player1, &player2, &arena, &window);
    party.run();
    
    exit(EXIT_SUCCESS);
}
