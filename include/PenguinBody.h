/**
 * @file Penguin.h
 * @author Alexandre Augusto de Sá dos Santos (150056940@aluno.unb.br)
 * @brief Penguin class header file
 * @version 0.1
 * @date 2022-09-10
 *
 * @copyright Copyright (c) 2022
 *
 */
#ifndef PENGUINBODY_HEADER
#define PENGUINBODY_HEADER
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

class PenguinBody : public Component
{
private:
    std::weak_ptr<GameObject> pcannon;
    Vec2 speed;
    float linearSpeed;
    float angle;
    int hp;

public:
    static PenguinBody *player;
    std::string type = "PenguinBody";

    PenguinBody(GameObject &associated);
    ~PenguinBody();

    void Start();
    void Update(float dt);
    void Render();
    bool Is(std::string type);
};

#endif
