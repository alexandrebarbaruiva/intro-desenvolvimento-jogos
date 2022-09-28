#include "Minion.h"
#include "Bullet.h"
#include "Collider.h"
#include "Game.h"
#include <cmath>

Minion::Minion(GameObject &associated, std::weak_ptr<GameObject> alienCenter, float arcOffsetDeg) : Component(associated)
{
    this->alienCenter = alienCenter;
    this->arc = arcOffsetDeg;

    float minionScale = ((float)rand() / RAND_MAX) * (1.5 - 1) + 1;
    Sprite *minionSprite = new Sprite(associated, "assets/img/minion.png", 1, 1.0);
    minionSprite->SetScale(minionScale, minionScale);

    associated.AddComponent(minionSprite);
    associated.AddComponent(new Collider(associated));

    Vec2 origin = Vec2::Rotate(Vec2(100, 0), arc) + alienCenter.lock().get()->box.Center();
    associated.box.SetCenter(origin);
}

void Minion::Update(float dt)
{
    if (alienCenter.lock() == nullptr)
    {
        associated.RequestDelete();
        return;
    }
    this->arc += PI / 62;
    this->associated.angleDeg = arc * 180 / PI;

    Vec2 origin = Vec2::Rotate(Vec2(100, 0), arc) + alienCenter.lock().get()->box.Center();
    associated.box.SetCenter(origin);
}

void Minion::Render()
{
}

void Minion::NotifyCollision(GameObject &other)
{
}

bool Minion::Is(std::string type)
{
    return (type == Minion::type);
}

void Minion::Shoot(Vec2 target)
{
    float angle = (target - associated.box.Center()).Atan2();

    GameObject *bulletObject = new GameObject();
    bulletObject->AddComponent(
        new Bullet(
            *bulletObject,                  // associated
            angle,                          // angle
            500,                            // speed
            10,                             // damage
            500,                            // maxDistance
            "assets/img/minionbullet2.png", // sprite
            0.05,                           // frameTime
            3,                              // frameCount
            true                            // targetsPlayer
            ));
    bulletObject->box.SetOrigin({associated.box.Origin()});
    bulletObject->angleDeg = angle * 180 / PI;
    Game::GetInstance().GetCurrentState().AddObject(bulletObject);
}
