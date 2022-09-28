/**
 * @file EndState.cpp
 * @author Alexandre Augusto de Sá dos Santos (150056940@aluno.unb.br)
 * @brief EndState class implementation file
 * @version 0.1
 * @date 2022-06-26
 *
 * @copyright Copyright (c) 2022
 *
 */
#include "EndState.h"
#include "GameData.h"
#include "Sprite.h"
#include "Camera.h"
#include "InputManager.h"
#include "TitleState.h"
#include "Text.h"
#include "Game.h"

EndState::EndState()
{
    GameObject *bg = new GameObject();
    Sprite *result;
    if (GameData::playerVictory)
    {
        result = new Sprite(*bg, "assets/img/win.jpg");
        backgroundMusic = Music("assets/audio/endStateWin.ogg");
    }
    else
    {
        result = new Sprite(*bg, "assets/img/lose.jpg");
        backgroundMusic = Music("assets/audio/endStateLose.ogg");
    }
    bg->AddComponent(result);
    bg->box.SetOrigin({0, 0});
    AddObject(bg);

    GameObject *text = new GameObject();
    text->box.SetOrigin({GAME_SCREEN_WIDTH / 2, 500});
    text->AddComponent(new Text(*text, "assets/font/Call me maybe.ttf", 50, Text::BLENDED, "ESC to quit  SPACE to play again", {255, 0, 0, SDL_ALPHA_OPAQUE}));
    AddObject(text);
}

void EndState::Update(float dt)
{
    UpdateArray(dt);
    if (InputManager::GetInstance().KeyPress(ESCAPE_KEY) || InputManager::GetInstance().QuitRequested())
    {
        quitRequested = true;
    }

    if (InputManager::GetInstance().KeyPress(SPACE_KEY))
    {
        popRequested = true;
    }
}

EndState::~EndState()
{
    objectArray.clear();
}

void EndState::LoadAssets()
{
}

void EndState::Pause()
{
    backgroundMusic.Stop();
}

void EndState::Resume()
{
    backgroundMusic.Play();
    Camera::Reset();
}

void EndState::Start()
{
    Camera::Reset();
    LoadAssets();
    StartArray();
    started = true;
    backgroundMusic.Play();
}

void EndState::Render()
{
    RenderArray();
}
