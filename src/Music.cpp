/**
 * @file Music.cpp
 * @author Alexandre Augusto de Sá dos Santos (150056940@aluno.unb.br)
 * @brief Music class implementation file
 * @version 0.1
 * @date 2022-06-26
 *
 * @copyright Copyright (c) 2022
 *
 */
#include "../include/Music.h"
#include <iostream>

Music::Music(/* args */)
{
    music = nullptr;
}

Music::Music(std::string file)
{
    Open(file);
}

Music::~Music()
{
    Stop(1500);
    Mix_FreeMusic(music);
}

void Music::Open(std::string file)
{
    music = Mix_LoadMUS(file.c_str());
}

void Music::Play(int times)
{
    if (music == nullptr)
    {
        SDL_LogError(0, "No music loaded: %s", SDL_GetError());
    }
    else
    {
        Mix_PlayMusic(music, times);
    }
}

void Music::Stop(int msToStop)
{
    Mix_FadeOutMusic(msToStop);
}

bool Music::IsOpen()
{
    if (music != nullptr)
    {
        return true;
    }
    return false;
}