#include <iostream>
#include "player.hpp"
#include "bot.hpp"
#include "arena.hpp"
#include "party.hpp"
#include "menu.hpp"
#include "display.hpp"
#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>

#define ARENA_RADIUS 300
#define TITLE "Spin-Battle"
char menuTitle[] = "Press Enter to Start the 206 turbo";
char menuBackgroundPath[] = "../Src/assets/pictures/beybladeswllpp.jpg";
char menuMusicPath[] = "../Src/assets/musics/beybladeopenning.ogg";
char arenaBackgroundPath[] = "../Src/assets/pictures/space.png";
char arenaMusicPath[] = "../Src/assets/musics/battle.ogg";
char fontPath[] = "../Src/assets/fonts/LoveDays-2v7Oe.ttf";

int main()
{
    // init window
    // sf::RenderWindow window(sf::VideoMode(1920, 1080), TITLE, sf::Style::Fullscreen);
    sf::RenderWindow window(sf::VideoMode(1920, 1080), TITLE);

    // init menu
    Menu menu(menuTitle, menuBackgroundPath, fontPath, sf::Color::White, menuMusicPath);
    menu.run(&window);

    // init arena
    Arena arena((sf::VideoMode::getDesktopMode().width/2), (sf::VideoMode::getDesktopMode().height/2), ARENA_RADIUS, 1, 0, arenaBackgroundPath, fontPath, sf::Color::White, arenaMusicPath);

    // init player
    Player player(arena.getCenterX(), arena.getCenterY(), 15, 15, 10000, 5);

    // init bots
    Bot bots[] = {
        Bot(4, true, arena.getCenterX()-120, arena.getCenterY(), 10, 5, 20000, 5),
        Bot(4, true, arena.getCenterX(), arena.getCenterY()-120, 10, 5, 20000, 5),
        Bot(4, true, arena.getCenterX()+120, arena.getCenterY(), 10, 5, 20000, 5),
        Bot(4, true, arena.getCenterX(), arena.getCenterY()+120, 10, 5, 20000, 5),
        Bot(4, true, arena.getCenterX()+120, arena.getCenterY()-180, 10, 5, 20000, 5)
    };

    // init party
    Party party(&player, bots, &arena, &window);
    party.run();
    
    exit(EXIT_SUCCESS);
}
