/**
 * @file Sound.cpp
 * @author Alexandre Augusto de Sá dos Santos (150056940@aluno.unb.br)
 * @brief Sound class implementation file
 * @version 0.1
 * @date 2022-07-01
 *
 * @copyright Copyright (c) 2022
 *
 */
#include <iostream>
#include "../include/Sound.h"

Sound::Sound(GameObject &associated) : Component(associated)
{
    chunk = nullptr;
}

Sound::Sound(GameObject &associated, std::string file) : Sound(associated)
{
    Open(file);
}

Sound::~Sound()
{
}

void Sound::Play(int times)
{
    channel = Mix_PlayChannel(-1, chunk, times - 1);
    Mix_VolumeChunk(chunk, 50);
    if (channel == -1)
    {
        SDL_LogError(0, "No sound loaded: %s", Mix_GetError());
    }
}

void Sound::Stop()
{
    if (chunk != nullptr)
    {
        Mix_HaltChannel(channel);
    }
}

void Sound::Open(std::string file)
{
    chunk = Resources::GetSound(file);
    if (chunk == nullptr)
    {
        SDL_LogError(0, "Sound couldn't be opened: %s", Mix_GetError());
    }
}

bool Sound::IsOpen()
{
    if (Mix_Playing(channel))
    {
        return true;
    }
    return false;
}

void Sound::Update(float dt)
{
}

void Sound::Render()
{
}

bool Sound::Is(std::string type)
{
    return (type == "Sound");
}
