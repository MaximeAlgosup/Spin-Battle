#pragma once

class Arena {
    protected:
        int center_x, center_y;
        int radius;
        int level;
        int score;

    public:
    /*
    Arena class constructor
    params:
        x: x coordinate of the center of the arena
        y: y coordinate of the center of the arena
        r: radius of the arena
        l: level of the arena
        s: score of the arena
    return:
        Arena object
    */
    Arena(int x, int y, int r, int l, int s);

    /*
    Get the position of the center of the arena in x coordinate
    params:
        void
    return:
        int: x coordinate of the center of the arena
    */
    int getCenterX();

    /*
    Get the position of the center of the arena in y coordinate
    params:
        void
    return:
        int: y coordinate of the center of the arena
    */
    int getCenterY();

    /*
    Get the radius of the arena
    params:
        void
    return:
        int: radius of the arena
    */
    int getRadius();

    /*
    Get the level of the arena
    params:
        void
    return:
        int: level of the arena
    */
    int getLevel();

    /*
    Get the score of the arena
    params:
        void

    return:
        int: score of the arena
    */
    int getScore();

    // Setters

    /*
        Set arena size based on the level
        params:
            void
        return:
            int: size of the arena
    */
    int setSize();

    /*
        Increase the level of the arena
        params:
            void
        return:
            int: new level of the arena
    */
    int levelUp();

    /*
        Increase the score of the arena
        params:
            points: points to add to the score
        return:
            int: new score of the arena
    */
    int scoreUp(int points);

};


