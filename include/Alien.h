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
#define INCLUDE_SDL_IMAGE
#define INCLUDE_SDL_MIXER
#include "SDL_include.h"
#include "Component.h"
#include "Sprite.h"
#include "Vec2.h"
#include "Minion.h"
#include <vector>
#include <cmath>
#include <queue>
#include <string>

class Alien : public Component
{
private:
    class Action
    {
    private:
    public:
        enum ActionType
        {
            MOVE,
            SHOOT
        };
        ActionType type;
        Vec2 pos;

        Action(ActionType type, float x, float y);
    };

    Vec2 speed;
    int hp;
    int minions;
    std::queue<Action> taskQueue;
    std::vector<std::weak_ptr<GameObject>> minionArray;

public:
    Alien(GameObject &associated, int nMinions);
    ~Alien();

    std::string type = "Alien";

    void Start();
    void Update(float dt);
    void Render();
    bool Is(std::string type);
    int GetClosestMinion(Vec2 actionPos);
};

#endif
