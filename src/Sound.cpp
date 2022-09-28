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
#include "Sound.h"
#include "Resources.h"

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
    channel = Mix_PlayChannel(-1, chunk.get(), times - 1);
    Mix_VolumeChunk(chunk.get(), 50);
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
        SDL_Log("Cant load sound: %s", SDL_GetError());
        exit(EXIT_FAILURE);
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
    return (type == Sound::type);
}

void Sound::NotifyCollision(GameObject &other)
{
}
