/**
 * @file Resources.h
 * @author Alexandre Augusto de Sá dos Santos (150056940@aluno.unb.br)
 * @brief Resources class header file
 * @version 0.1
 * @date 2022-07-17
 *
 * @copyright Copyright (c) 2022
 *
 */
#ifndef RESOURCES_HEADER
#define RESOURCES_HEADER
#define INCLUDE_SDL_IMAGE
#define INCLUDE_SDL_MIXER
#include "SDL_include.h"
#include "Game.h"
#include <unordered_map>
#include <string>
#include <iostream>

class Resources
{
private:
    static std::unordered_map<std::string, SDL_Texture *> imageTable;
    static std::unordered_map<std::string, Mix_Music *> musicTable;
    static std::unordered_map<std::string, Mix_Chunk *> soundTable;

public:
    Resources(/* args */);
    ~Resources();

    static SDL_Texture *GetImage(std::string file);
    static void ClearImages();

    static Mix_Music *GetMusic(std::string file);
    static void ClearMusics();

    static Mix_Chunk *GetSound(std::string file);
    static void ClearSounds();
};

#endif