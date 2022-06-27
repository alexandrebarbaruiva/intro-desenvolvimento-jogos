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
#include "../include/State.h"

State::State() {
    quitRequested = false;
    // bg = new Sprite()
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
    // bg = Render();
}
