/**
 * @file State.cpp
 * @author Alexandre Augusto de Sá dos Santos (150056940@aluno.unb.br)
 * @brief State class implementation file
 * @version 0.1
 * @date 2022-06-26
 *
 * @copyright Copyright (c) 2022
 *
 */
#include "../include/State.h"

State::State() {
    quitRequested = false;
    bg = new Sprite("assets/img/ocean.jpg");
    music = new Music("assets/audio/stageState.ogg");
    music->Play();
}

void State::LoadAssets(){
    // Load music, images, fonts here.
}

void State::Update(float dt){
    // Updates entities' state
    if (SDL_QuitRequested())
    {
        quitRequested = true;
    }
    
}

void State::Render(){
    bg->Render(0, 0);
}

bool State::QuitRequested(){
    return quitRequested;
}