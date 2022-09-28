/**
 * @file Alien.h
 * @author Alexandre Augusto de Sá dos Santos (150056940@aluno.unb.br)
 * @brief Alien class header file
 * @version 0.1
 * @date 2022-08-20
 *
 * @copyright Copyright (c) 2022
 *
 */
#ifndef ALIEN_HEADER
#define ALIEN_HEADER
#include "Component.h"
#include "Sprite.h"
#include "Minion.h"
#include "Collider.h"
#include "Sound.h"
#include "Game.h"
#include "Bullet.h"
#include "Timer.h"
#include <queue>
#include <climits>
#include <string>

class Alien : public Component
{
private:
    enum AlienState
    {
        MOVING,
        RESTING
    };
    Vec2 speed;
    int hp;

    AlienState state;
    Vec2 destination;

    Timer restTimer;
    float timeOffset;

    std::vector<std::weak_ptr<GameObject>> minionArray;

public:
    Alien(GameObject &associated, float timeOffset = 0);
    ~Alien();

    std::string type = "Alien";

    void Start();
    void Update(float dt);
    void Render();
    std::weak_ptr<GameObject> GetClosestMinion();
    bool Is(std::string type);
    void NotifyCollision(GameObject &other);

    static int alienCount;
};

#endif
