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
    Stop();
    if (chunk != nullptr)
    {
        Mix_FreeChunk(chunk);
        chunk = nullptr;
    }
    
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
    chunk = Mix_LoadWAV(file.c_str());
    if (chunk == nullptr)
    {
        SDL_LogError(0, "Não foi possível carregar o arquivo WAV");
    }
}

bool Sound::IsOpen()
{
    if (Mix_Playing(channel) && chunk != nullptr)
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
    if (type == "Sound")
    {
        return true;
    }
    return false;
}
