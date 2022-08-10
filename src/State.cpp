/**
 * @file State.cpp
 * @author Alexandre Augusto de Sá dos Santos (150056940@aluno.unb.br)
 * @brief State class implementation file
 * @version 0.1
 * @date 2022-06-26
 *
 * @copyright Copyright (c) 2022
 *
 */
#include "../include/State.h"
#include <math.h>

const double PI = M_PI;

State::State()
{
    quitRequested = false;

    GameObject *gameObjectOcean = new GameObject();

    Sprite *bg = new Sprite(*gameObjectOcean, "assets/img/ocean.jpg");
    CameraFollower *OceanFollower = new CameraFollower(*gameObjectOcean);
    gameObjectOcean->AddComponent(bg);
    gameObjectOcean->AddComponent(OceanFollower);

    objectArray.emplace_back(gameObjectOcean);

    GameObject *gameObjectMap = new GameObject();

    TileSet *tileSet = new TileSet(64, 64, "assets/img/tileset.png");
    TileMap *tileMap = new TileMap(*gameObjectMap, "assets/map/tileMap.txt", tileSet);
    gameObjectMap->AddComponent(tileMap);
    gameObjectMap->box.x = 0;
    gameObjectMap->box.y = 0;

    objectArray.emplace_back(gameObjectMap);

    music = new Music("assets/audio/stageState.ogg");
    music->Play();
}

State::~State()
{
    objectArray.clear();
}

void State::LoadAssets()
{
    // Load music, images, fonts here.
}

void State::Update(float dt)
{
    Camera::Update(dt);
    InputManager instance = InputManager::GetInstance();

    for (int pos = 0; pos < (int)objectArray.size(); pos++)
    {
        objectArray[pos].get()->Update(dt);
    }
    // Check for dead GOs
    for (int pos = 0; pos < (int)objectArray.size(); pos++)
    {
        if (objectArray[pos].get()->IsDead())
        {
            objectArray.erase(objectArray.begin() + pos);
        }
    }
    // Create penguim
    if (instance.IsKeyDown(SPACE_KEY))
    {
        Vec2 objPos = Vec2(200, 0).GetRotated(-M_PI + M_PI * (rand() % 1001) / 500.0) + Vec2(instance.GetMouseX(), instance.GetMouseY());
        AddObject((int)objPos.x, (int)objPos.y);
    }
    // Quits game
    if (instance.IsKeyDown(ESCAPE_KEY) || instance.QuitRequested())
    {
        quitRequested = true;
    }
    // Updates entities' state
    if (QuitRequested())
    {
        music->~Music();
    }
}

void State::Render()
{
    for (int pos = 0; pos < (int)objectArray.size(); pos++)
    {
        objectArray[pos].get()->Render();
    }
}

bool State::QuitRequested()
{
    return quitRequested;
}

void State::AddObject(int mouseX, int mouseY)
{
    GameObject *firstEnemy = new GameObject();

    // Add image to enemy
    Sprite *penguinFace = new Sprite(*firstEnemy, "assets/img/penguinface.png");
    firstEnemy->AddComponent(penguinFace);

    // Add position to centralize image
    firstEnemy->box.x = mouseX + Camera::pos.x - firstEnemy->box.Center().x;
    firstEnemy->box.y = mouseY + Camera::pos.y - firstEnemy->box.Center().y;

    // Add sound
    Sound *penguinSound = new Sound(*firstEnemy, "assets/audio/boom.wav");
    firstEnemy->AddComponent(penguinSound);

    // Add Face
    Face *face = new Face(*firstEnemy);
    firstEnemy->AddComponent(face);

    objectArray.emplace_back(firstEnemy);
}