/**
 * @file Game.cpp
 * @author Alexandre Augusto de Sá dos Santos (150056940@aluno.unb.br)
 * @brief Game class implementation file
 * @version 0.1
 * @date 2022-06-26
 *
 * @copyright Copyright (c) 2022
 *
 */
#include <iostream>
#include "../include/Game.h"

Game::Game(std::string title, int width, int height)
{
    std::cout << "Starting game" << std::endl;
    // Check for any SDL initialization error
    if (SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO | SDL_INIT_TIMER) != 0)
    {
        SDL_Log("Unable to initialize SDL: %s", SDL_GetError());
        throw "Unable to initialize SDL";
    }

    // https://stackoverflow.com/questions/347949/how-to-convert-a-stdstring-to-const-char-or-char
    window = SDL_CreateWindow(
        title.c_str(),    // window title
        initialPositionX, // initial x position
        initialPositionY, // initial y position
        width,            // width, in pixels
        height,           // height, in pixels
        SDLFlags          // flags
    );

    // Check if window has been successfully created
    if (window == NULL)
    {
        SDL_Log("Unable to create window: %s", SDL_GetError());
        throw "Unable to create window";
    }
    SDL_Delay(3000);
    std::cout << "Destroying window" << std::endl;
    SDL_DestroyWindow(window);
    SDL_Quit();
}

Game::~Game()
{
}

Game *Game::instance{nullptr};

// GetInstance makes sure there's only one Game instance
Game *Game::GetInstance()
{
    if (instance == nullptr)
    {
        instance = new Game("Alexandre Augusto de Sá dos Santos 15/00156940", 1024, 600);
    }
    return instance;
}