/**
 * @file PenguinCannon.h
 * @author Alexandre Augusto de Sá dos Santos (150056940@aluno.unb.br)
 * @brief PenguinCannon class header file
 * @version 0.1
 * @date 2022-09-10
 *
 * @copyright Copyright (c) 2022
 *
 */
#ifndef PENGUINCANNON_HEADER
#define PENGUINCANNON_HEADER
#define INCLUDE_SDL_IMAGE
#define INCLUDE_SDL_MIXER
#include "SDL_include.h"
#include "Component.h"
#include "Sprite.h"
#include "Vec2.h"
#include <vector>
#include <cmath>
#include <queue>
#include <string>

class PenguinCannon : public Component
{
private:
    float angle;
    std::weak_ptr<GameObject> pbody;

public:
    PenguinCannon(GameObject &associated, std::weak_ptr<GameObject> penguinBody);

    std::string type = "PenguinCannon";

    void Update(float dt);
    void Render();
    bool Is(std::string type);
    void Shoot();
};

#endif
