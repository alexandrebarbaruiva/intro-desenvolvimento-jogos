/**
 * @file Minion.cpp
 * @author Alexandre Augusto de Sá dos Santos (150056940@aluno.unb.br)
 * @brief Minion class implementation file
 * @version 0.1
 * @date 2022-07-01
 *
 * @copyright Copyright (c) 2022
 *
 */
#include <iostream>
#include "../include/Minion.h"
#include "../include/Game.h"

Minion::Minion(GameObject &associated, std::weak_ptr<GameObject> alienCenter, float arcOffsetDeg) : Component(associated)
{
    // Set sprite
    Sprite *sprite = new Sprite(associated, "assets/img/minion.png");
    float minScale = 1;
    float maxScale = 1.5;
    float minionScale = ((float)rand() / RAND_MAX) * (maxScale - minScale) + minScale;
    sprite->SetScale(minionScale, minionScale);

    // Set object attributes
    this->alienCenter = alienCenter;
    this->arc = arcOffsetDeg;
    std::shared_ptr<GameObject> gameObject = alienCenter.lock();

    // Set associated attributes
    associated.box.setPosition(gameObject->box.Center() + (associated.box.measures() / 2));
    associated.angleDeg = this->arc;
    associated.AddComponent(sprite);
}

Minion::~Minion()
{
}

void Minion::Start()
{
}

void Minion::Update(float dt)
{
    Vec2 minionCenter = associated.box.measures() / 2;
    Vec2 aCenter = alienCenter.lock()->box.Center();
    Vec2 mCenter = associated.box.Center();
    Vec2 initialPos = aCenter - minionCenter + Vec2(150, 0).GetRotated(this->arc);

    this->arc += 1 / (M_PI * 16);

    associated.box.setPosition(initialPos);
    associated.angleDeg = -(mCenter.direct(aCenter) * 180) / (M_PI);
}

void Minion::Render()
{
}

bool Minion::Is(std::string type)
{
    return (type == Minion::type);
}

void Minion::Shoot(Vec2 target)
{
    Sprite *sprite = (Sprite *)associated.GetComponent("Sprite");
    Vec2 minionMiddle = associated.box.Center() + (associated.box.measures() / 2);
    minionMiddle = minionMiddle - Vec2(sprite->GetWidth() / 2, sprite->GetHeight() / 2);

    float bulletAngle = minionMiddle.direct(target);
    Vec2 outsideMinion = Vec2(sprite->GetWidth() / 2, 0).GetRotated(bulletAngle) + minionMiddle;

    GameObject *gameObject = new GameObject();
    gameObject->box.setPosition(outsideMinion);
    gameObject->angleDeg = -180 * bulletAngle / M_PI;

    Bullet *bullet = new Bullet(
        *gameObject,                      // GameObject
        bulletAngle,                      // angle
        400,                              // speed
        10,                               // damage
        1000,                             // maxDistance
        "./assets/img/minionbullet2.png", // sprite
        3,                                // frameCount
        1                                 // frameTime
    );
    gameObject->AddComponent(bullet);

    State *state = &Game::GetInstance()->GetState();
    state->AddObject(gameObject);
}
