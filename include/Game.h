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
#ifndef GAME_HEADER
#define GAME_HEADER
#define INCLUDE_SDL
#define INCLUDE_SDL_IMAGE
#define INCLUDE_SDL_MIXER
#include "SDL_include.h"
#include "State.h"
#include "InputManager.h"
#include "Resources.h"
#include <stack>
#include <ctime>
#include <iostream>
#define ALIEN_HP 100
#define PENGUIN_HP 100
#define HEALTH_BOX 20
#define GAME_SCREEN_WIDTH 1024
#define GAME_SCREEN_HEIGHT 600

// Game class using the Singleton's design pattern, which allows
// only one instance to exist at any given moment. For that to be
// achieved, the constructor `GetInstance` must not be public.
// This way, any client will access the same instance.
class Game
{
    // As a singleton, it's constructor must be defined as private to
    // enforce the single instance directive.
private:
    static Game *instance;
    std::string windowTitle;

    int SDL_Window_Flags = 0;
    int SDL_Image_Flags = IMG_INIT_JPG | IMG_INIT_PNG | IMG_INIT_TIF;
    int SDL_Mix_Flags = MIX_INIT_FLAC | MIX_INIT_MP3 | MIX_INIT_OGG;

    Game(std::string title, int width, int height);

    SDL_Window *window;
    SDL_Renderer *renderer;
    static State *storedState;
    static std::stack<std::unique_ptr<State>> stateStack;
    int frameStart;
    float dt;
    void CalculateDeltaTime();

public:
    ~Game();
    // Game loop
    // 1. Load screens
    // 2. Input data is processed
    // 3. States are updated
    // 4. Objects are drawn on screen
    void Run();

    // Method for controlling access to the single instance.
    // First run it creates the instance, after that it
    // returns the existing instance
    static Game &GetInstance();

    // Method for getting game Renderer
    SDL_Renderer *GetRenderer();

    // Method for getting current game State
    State &GetCurrentState();

    void Push(State *state);
    float GetDeltaTime();
};

#endif
