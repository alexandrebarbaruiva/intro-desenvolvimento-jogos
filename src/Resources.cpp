/**
 * @file Resources.cpp
 * @author Alexandre Augusto de Sá dos Santos (150056940@aluno.unb.br)
 * @brief Resources class implementation file
 * @version 0.1
 * @date 2022-07-17
 *
 * @copyright Copyright (c) 2022
 *
 */
#include "../include/Resources.h"
#include "../include/Game.h"

std::unordered_map<std::string, SDL_Texture *> Resources::imageTable;
std::unordered_map<std::string, Mix_Music *> Resources::musicTable;
std::unordered_map<std::string, Mix_Chunk *> Resources::soundTable;

Resources::Resources(/* args */)
{
}

Resources::~Resources()
{
}

SDL_Texture *Resources::GetImage(std::string file)
{
    // Check if image already exists on imageTable
    std::unordered_map<std::string, SDL_Texture *>::const_iterator foundFile = imageTable.find(file);

    if (foundFile != imageTable.end())
    {
        return foundFile->second;
    }
    SDL_Texture *newTexture = IMG_LoadTexture(Game::GetInstance()->GetRenderer(), file.c_str());
    imageTable.insert(std::make_pair(file, newTexture));
    return newTexture;
}

void Resources::ClearImages()
{
    std::coutCLEAR IMAGE\n";
    for (auto imageCell : imageTable)
    {
        SDL_DestroyTexture(imageCell.second);
    }
}

Mix_Music *Resources::GetMusic(std::string file)
{
    std::unordered_map<std::string, Mix_Music *>::const_iterator foundFile = musicTable.find(file);

    if (foundFile != musicTable.end())
    {
        return foundFile->second;
    }
    Mix_Music *newMusic = Mix_LoadMUS(file.c_str());
    musicTable.insert(std::make_pair(file, newMusic));
    return newMusic;
}

void Resources::ClearMusics()
{
    for (auto musicCell : musicTable)
    {
        Mix_FreeMusic(musicCell.second);
    }
}

Mix_Chunk *Resources::GetSound(std::string file)
{
    std::unordered_map<std::string, Mix_Chunk *>::const_iterator foundFile = soundTable.find(file);

    if (foundFile != soundTable.end())
    {
        return foundFile->second;
    }
    Mix_Chunk *newSound = Mix_LoadWAV(file.c_str());
    soundTable.insert(std::make_pair(file, newSound));
    return newSound;
}

void Resources::ClearSounds()
{
    for (auto soundCell : soundTable)
    {
        Mix_FreeChunk(soundCell.second);
    }
}
