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
#include "InputManager.h"
#include <string>

class Camera
{
private:
    static GameObject *focus;

public:
    static Vec2 pos;
    static Vec2 speed;

    static void Follow(GameObject *newFocus);
    static void Unfollow();
    static void Update(float dt);
};

#endif
