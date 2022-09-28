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
#include "Music.h"
#include "Resources.h"

#define INCLUDE_SDL
#include "SDL_include.h"

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
    if (Mix_PlayMusic(music.get(), times) == -1)
    {
        SDL_Log("Cant play music: %s", SDL_GetError());
    }
    Mix_VolumeMusic(50);
}

void Music::Stop(int msToStop)
{
    Mix_FadeOutMusic(msToStop);
}

bool Music::IsOpen()
{
    return music != nullptr;
}
