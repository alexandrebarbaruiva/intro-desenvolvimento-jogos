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
}

void Music::Open(std::string file)
{
    music = Resources::GetMusic(file);
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
        Mix_VolumeMusic(80);
    }
}

void Music::Stop(int msToStop)
{
    Mix_FadeOutMusic(msToStop);
}

bool Music::IsOpen()
{
    return (music != nullptr);
}