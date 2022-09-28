/**
 * @file PenguinCannon.cpp
 * @author Alexandre Augusto de Sá dos Santos (150056940@aluno.unb.br)
 * @brief PenguinCannon class implementation file
 * @version 0.1
 * @date 2022-07-01
 *
 * @copyright Copyright (c) 2022
 *
 */
#include "PenguinCannon.h"

PenguinCannon::PenguinCannon(GameObject &associated, std::weak_ptr<GameObject> penguinBody) : Component(associated)
{
    associated.AddComponent(new Sprite(associated, "assets/img/cubngun.png"));
    associated.AddComponent(new Collider(associated));
    this->pbody = penguinBody;
    this->angle = 0;
}

void PenguinCannon::Update(float dt)
{
    if (pbody.lock()->IsDead())
    {
        associated.RequestDelete();
    }
    InputManager input = InputManager::GetInstance();
    Vec2 mouseCoord = {
        input.GetMouseX() + Camera::pos.x,
        input.GetMouseY() + Camera::pos.y};

    cooldown.Update(dt);
    associated.box.SetCenter(pbody.lock()->box.Center());

    Vec2 direction = mouseCoord - associated.box.Center();
    associated.angleDeg = direction.Atan2() * 180 / PI;

    if (input.MousePress(LEFT_MOUSE_BUTTON) && cooldown.Get() >= 1)
    {
        Shoot();
        cooldown.Restart();
    }
}

void PenguinCannon::Shoot()
{
    GameObject *bulletObject = new GameObject();
    bulletObject->AddComponent(
        new Bullet(
            *bulletObject,                  // associated
            associated.angleDeg * PI / 180, // angle
            500,                            // speed
            20,                             // damage
            500,                            // maxDistance
            "assets/img/penguinbullet.png", // sprite
            0.05,                           // frameTime
            4,                              // frameCount
            false                           // targetsPlayer
            ));

    // calculating bullet starting point
    Vec2 offset = Vec2::Rotate(Vec2(associated.box.x + associated.box.w, associated.box.y + associated.box.h / 2) - associated.box.Center(), associated.angleDeg * PI / 180);
    Vec2 start = associated.box.Center() + offset;

    bulletObject->box.x = start.x - bulletObject->box.w / 2;
    bulletObject->box.y = start.y;
    bulletObject->angleDeg = associated.angleDeg;
    Game::GetInstance().GetCurrentState().AddObject(bulletObject);
}

void PenguinCannon::Render()
{
}

void PenguinCannon::NotifyCollision(GameObject &other)
{
}

bool PenguinCannon::Is(std::string type)
{
    return (type == PenguinCannon::type);
}
