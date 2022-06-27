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
    SDL_Log("Starting game");
    if (instance != nullptr)
    {
        std::cout << "Game is not obeying Singleton laws" << std::endl;
    }

    instance = this;

    // Check for any SDL initialization error
    if (SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO | SDL_INIT_TIMER) != 0)
    {
        SDL_LogError(0, "Unable to initialize SDL: %s", SDL_GetError());
        throw "Unable to initialize SDL";
    }

    // Check for any Image initialization error
    if (IMG_Init(SDL_Image_Flags) == 0)
    {
        SDL_LogError(0, "Unable to initialize SDL_Image: %s", IMG_GetError());
        throw "Unable to initialize SDL_Image";
    }

    // Check for any Audio initialization error
    if (Mix_Init(SDL_Mix_Flags) == 0)
    {
        SDL_LogError(0, "Unable to initialize SDL_Mix: %s", Mix_GetError());
        throw "Unable to initialize SDL_Mix";
    }

    // Check for any Audio initialization error
    if (Mix_OpenAudio(MIX_DEFAULT_FREQUENCY, MIX_DEFAULT_FORMAT, MIX_DEFAULT_CHANNELS, 1024) != 0)
    {
        SDL_LogError(0, "Unable to initialize Mix_OpenAudio: %s", Mix_GetError());
        throw "Unable to initialize Mix_OpenAudio";
    }

    // Changes default 8 audio channels to 32 (might increase if needed by game)
    Mix_AllocateChannels(32);

    // https://stackoverflow.com/questions/347949/how-to-convert-a-stdstring-to-const-char-or-char
    // Create Game Window
    window = SDL_CreateWindow(
        title.c_str(),          // window title
        SDL_WINDOWPOS_CENTERED, // initial x position
        SDL_WINDOWPOS_CENTERED, // initial y position
        width,                  // width, in pixels
        height,                 // height, in pixels
        SDL_Window_Flags        // flags
    );
    windowTitle = title;

    // Check if window has been successfully created
    if (window == nullptr)
    {
        SDL_LogError(0, "Unable to create window: %s", SDL_GetError());
        throw "Unable to create window";
    }

    // Create Game renderer
    renderer = SDL_CreateRenderer(
        window,                  // window to render
        -1,                      // renderer to use, -1 to choose automagically
        SDL_RENDERER_ACCELERATED // flags
    );

    if (renderer == nullptr)
    {
        SDL_LogError(0, "Unable to create Renderer: %s", SDL_GetError());
        throw "Unable to create Renderer";
    }

    state = new State();
}

Game::~Game()
{
    // Destroys in constructor's reverse order
    // Renderer -> Window -> Audio -> Mix -> Img -> SDL
    SDL_Log("Destroying game");
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    Mix_CloseAudio();
    Mix_Quit();
    IMG_Quit();
    SDL_Quit();
}

State Game::GetState()
{
    return *state;
}

SDL_Renderer *Game::GetRenderer()
{
    return renderer;
}

std::string Game::getTitle()
{
    return windowTitle;
}

Game *Game::instance{nullptr};

// GetInstance makes sure there's only one Game instance
Game *Game::GetInstance()
{
    if (instance == nullptr)
    {
        new Game("Alexandre Augusto de Sá dos Santos 15/00156940", 1024, 600);
    }
    return instance;
}

void Game::Run()
{
    while (!state->QuitRequested())
    {
        state->Update(0);
        state->Render();
        SDL_RenderPresent(renderer);
        SDL_Delay(33);
    }
}