#include <iostream>


class Game
{
public:
    std::string title;
    int width;
    int height;

    // static GetState();
    Game& GetInstance();

// private:
//     // constructor
//     Game(title, width, height);
};