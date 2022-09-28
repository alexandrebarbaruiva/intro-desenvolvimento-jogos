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
#include "Game.h"

Game *Game::instance;
std::stack<std::unique_ptr<State>> Game::stateStack;
State *Game::storedState;

Game::Game(std::string title, int width, int height) : frameStart(0), dt(0)
{
    this->frameStart = 0;
    this->dt = 0;

    srand(time(NULL));
    SDL_Log("Starting game");

    if (instance != nullptr)
    {
        std::cout << "Game is not obeying Singleton laws" << std::endl;
    }

    instance = this;

    // Initialization of basic SDL functionalities
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

    // Check for any Image initialization error
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

    if (TTF_Init() != 0)
    {
        SDL_LogError(0, "Unable to initialize TTF: %s", SDL_GetError());
        throw "Unable to initialize TTF";
    }

    Mix_AllocateChannels(32);

    window = SDL_CreateWindow(
        title.c_str(),          // window title
        SDL_WINDOWPOS_CENTERED, // initial x position
        SDL_WINDOWPOS_CENTERED, // initial y position
        width,                  // width, in pixels
        height,                 // height, in pixels
        SDL_Window_Flags        // flags
    );

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
    this->frameStart = SDL_GetTicks();
    this->storedState = nullptr;
}

Game::~Game()
{
    if (storedState != nullptr)
    {
        delete storedState;
    }
    SDL_Log("Destroying game");
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    TTF_Quit();
    Mix_CloseAudio();
    Mix_Quit();
    IMG_Quit();
    SDL_Quit();
}

State &Game::GetCurrentState()
{
    State *cState = stateStack.top().get();
    return *cState;
}

void Game::Push(State *state)
{
    this->storedState = state;
}

SDL_Renderer *Game::GetRenderer()
{
    return this->renderer;
}

Game &Game::GetInstance()
{
    if (instance == nullptr)
    {
        new Game("Alexandre Augusto de Sá dos Santos 15/00156940", GAME_SCREEN_WIDTH, GAME_SCREEN_HEIGHT);
    }

    return *instance;
}

void Game::Run()
{
    stateStack.emplace(storedState);
    stateStack.top()->Start();
    storedState = nullptr;

    while (!(stateStack.empty()) && !(stateStack.top()->QuitRequested()))
    {
        if (stateStack.top()->PopRequested())
        {
            stateStack.pop();
            Resources::ClearImages();

            if (!stateStack.empty())
            {
                stateStack.top()->Resume();
            }
        }

        if (storedState != nullptr)
        {
            stateStack.top()->Pause();
            stateStack.emplace(storedState);
            stateStack.top()->Start();
            storedState = nullptr;
        }

        CalculateDeltaTime();
        InputManager::GetInstance().Update();
        stateStack.top()->Update(GetDeltaTime());
        stateStack.top()->Render();
        SDL_RenderPresent(renderer);
        SDL_Delay(33);
    }

    while (!stateStack.empty())
    {
        stateStack.pop();
    }
    Resources::ClearImages();
    Resources::ClearMusics();
    Resources::ClearSounds();
    Resources::ClearFonts();
}

void Game::CalculateDeltaTime()
{
    dt = (SDL_GetTicks() - frameStart);
    frameStart = SDL_GetTicks();
}

float Game::GetDeltaTime()
{
    return dt / 1000;
}
