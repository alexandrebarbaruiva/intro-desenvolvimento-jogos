/**
 * @file Game.h
 * @author Alexandre Augusto de Sá dos Santos (150056940@aluno.unb.br)
 * @brief Game class header file
 * @version 0.1
 * @date 2022-06-26
 *
 * @copyright Copyright (c) 2022
 *
 */
#include <iostream>
#define INCLUDE_SDL_IMAGE
#define INCLUDE_SDL_MIXER
#include "SDL_include.h"

// Game class using the Singleton's design pattern, which allows
// only one instance to exist at any given moment. For that to be
// achieved, the constructor `GetInstance` must not be public.
// This way, any client will access the same instance.
class Game
{
    // As a singleton, it's constructor must be defined as private to
    // enforce the single instance directive.
private:
    /* data */
    static Game *instance;
    int initialPositionX = 0;
    int initialPositionY = 0;

    int SDLFlags = 0;
    int SDL_Image_Flags = IMG_INIT_JPG | IMG_INIT_PNG | IMG_INIT_TIF;

    SDL_Window *window;

protected:
    Game(std::string title, int width, int height);
    ~Game();
    std::string title_;

public:
    // Singleton must not be cloneable nor assignable
    Game(Game &other) = delete;
    void operator=(const Game &) = delete;

    // Method for controlling access to the single instance.
    // First run it creates the instance, after that it
    // returns the existing instance
    static Game *GetInstance();

    // Method for getting game Renderer
    void GetRenderer()
    {
        // ...
    }

    std::string title() const
    {
        return title_;
    }
};
