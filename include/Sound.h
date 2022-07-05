/**
 * @file Sound.h
 * @author Alexandre Augusto de Sá dos Santos (150056940@aluno.unb.br)
 * @brief Sound class header file
 * @version 0.1
 * @date 2022-07-01
 *
 * @copyright Copyright (c) 2022
 *
 */
#ifndef SOUND_HEADER
#define SOUND_HEADER
#define INCLUDE_SDL_IMAGE
#define INCLUDE_SDL_MIXER
#include "SDL_include.h"
#include "GameObject.h"
#include "Component.h"
#include <string>

class Sound : public Component
{
private:
    Mix_Chunk *chunk;
    int channel;

public:
    Sound(GameObject &associated);
    Sound(GameObject &associated, std::string file);
    ~Sound();

    std::string type = "Sound";

    void Play(int times = 1);
    void Stop();
    void Open(std::string file);
    bool IsOpen();
    void Update(float dt);
    void Render();
    bool Is(std::string type);
};

#endif
