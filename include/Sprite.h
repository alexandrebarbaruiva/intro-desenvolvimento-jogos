/**
 * @file Sprite.h
 * @author Alexandre Augusto de Sá dos Santos (150056940@aluno.unb.br)
 * @brief Sprite class header file
 * @version 0.1
 * @date 2022-06-26
 *
 * @copyright Copyright (c) 2022
 *
 */
#define INCLUDE_SDL_IMAGE
#define INCLUDE_SDL_MIXER
#include "SDL_include.h"
#include <string>

class Sprite
{
private:
    SDL_Texture *texture;
    int width;
    int height;
    SDL_Rect clipRect;

public:
    Sprite();
    Sprite(std::string file);

    ~Sprite();

    void Open(std::string file);

    void SetClip(int x, int y, int w, int h);

    void Render(int x, int y);

    int GetWidth();

    int GetHeight();

    bool IsOpen();

};
