#pragma once

enum Direction{
            UP,
            DOWN,
            LEFT,
            RIGHT,
            NONE
        };

class Spinner{
    protected:
        int radius;
        unsigned int pos_x, pos_y;
        int weight;
        int maxSpeed;
        int speed;
        int agility;
        enum Direction direction;
        int inertia;
        bool isDead;

    public:
        /*
            Constructor
            params:
                x: x position of the spinner
                y: y position of the spinner
                w: weight of the spinner
                s: max speed of the spinner
                a: agility of the spinner
            return:
                void
        */
        Spinner(unsigned int x, unsigned int y, int w, int s, int a);

        /*
            Get the x position of the spinner
            params:
                void
            return:
                int: x position of the spinner
        */
        int getPosX();

        /*
            Get the y position of the spinner
            params:
                void
            return:
                int: y position of the spinner
        */
        int getPosY();

        /*
            Get the weight of the spinner
            params:
                void
            return:
                int: weight of the spinner
        */
        int getWeight();
        
        /*
            Get the speed of the spinner
            params:
                void
            return:
                int: speed of the spinner
        */
        int getSpeed();

        /*
            Get the agility of the spinner
            params:
                void
            return:
                int: agility of the spinner
        */
        int getAgility();

        /*
            Get the status of the spinner
            params:
                void
            return:
                bool: status of the spinner
        */
        int getRadius();

        /*
            Get the status of the spinner
            params:
                void
            return:
                bool: status of the spinner
        */
        bool getIsDead();

        /*
            Move the spinner up
            params:
                void
            return:
                void
        */
        void moveUp();

        /*
            Move the spinner down
            params:
                void
            return:
                void
        */
        void moveDown();

        /*
            Move the spinner left
            params:
                void
            return:
                void
        */
        void moveLeft();

        /*
            Move the spinner right
            params:
                void
            return:
                void
        */
        void moveRight();

        /*
            Move the spinner automatically following the inertia
            params:
                void
            return:
                void
        */
        void autoMove();

        /*
            Check if the spinner is out of the arena
            params:
                arena_x: x position of the arena
                arena_y: y position of the arena
                arena_radius: radius of the arena
            return:
                bool: status of the spinner
        */
        bool isOut(int arena_x, int arena_y, int arena_radius);

        /*
            Display the spinner data
            params:
                void
            return:
                void
        */
        void displayData();
};