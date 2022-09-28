/**
 * @file HealthBox.h
 * @author Alexandre Augusto de Sá dos Santos (150056940@aluno.unb.br)
 * @brief HealthBox class header file
 * @version 0.1
 * @date 2022-07-01
 *
 * @copyright Copyright (c) 2022
 *
 */
#ifndef HEALTHBOX_HEADER
#define HEALTHBOX_HEADER
#include "Component.h"

class HealthBox : public Component
{
private:
    int healEffect;

public:
    HealthBox(GameObject &associated);

    std::string type = "HealthBox";

    void Update(float dt);
    void Render();
    bool Is(std::string type);
    int GetHealth();
    void NotifyCollision(GameObject &other);
};
#endif