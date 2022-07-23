/**
 * @file Camera.h
 * @author Alexandre Augusto de Sá dos Santos (150056940@aluno.unb.br)
 * @brief Camera class header file
 * @version 0.1
 * @date 2022-07-20
 *
 * @copyright Copyright (c) 2022
 *
 */
#ifndef CAMERA_HEADER
#define CAMERA_HEADER
#define INCLUDE_SDL_IMAGE
#define INCLUDE_SDL_MIXER
#include "SDL_include.h"
#include "GameObject.h"
#include "Vec2.h"
#include <string>

class Camera
{
private:
    GameObject *focus;

public:
    Camera();
    ~Camera();

    Vec2 pos;
    Vec2 speed;

    void Follow(GameObject *newFocus);
    void Unfollow();
    void Update(float dt);
};

#endif
