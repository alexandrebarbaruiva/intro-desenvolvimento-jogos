/**
 * @file Face.h
 * @author Alexandre Augusto de Sá dos Santos (150056940@aluno.unb.br)
 * @brief Face class header file
 * @version 0.1
 * @date 2022-07-01
 *
 * @copyright Copyright (c) 2022
 *
 */
#ifndef FACE_HEADER
#define FACE_HEADER
#define INCLUDE_SDL_IMAGE
#define INCLUDE_SDL_MIXER
#include "SDL_include.h"
#include "Component.h"
#include "Sound.h"
#include "InputManager.h"
#include "Camera.h"
#include <string>

class Face : public Component
{
private:
    int hitpoints;

public:
    Face(GameObject &associated);
    ~Face();

    std::string type = "Face";

    void Damage(int damage);
    void Update(float dt);
    void Render();
    bool Is(std::string type);
};

#endif
