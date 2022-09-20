/**
 * @file State.h
 * @author Alexandre Augusto de Sá dos Santos (150056940@aluno.unb.br)
 * @brief State class header file
 * @version 0.1
 * @date 2022-06-26
 *
 * @copyright Copyright (c) 2022
 *
 */
#ifndef STATE_HEADER
#define STATE_HEADER
#define INCLUDE_SDL_IMAGE
#define INCLUDE_SDL_MIXER
#include "SDL_include.h"
#include <vector>
#include <memory>
#include "Sprite.h"
#include "Music.h"
#include "Sound.h"
#include "GameObject.h"
#include "Alien.h"
#include "PenguinBody.h"
#include "TileSet.h"
#include "TileMap.h"
#include "InputManager.h"
#include "Camera.h"
#include "CameraFollower.h"

class State
{
private:
    Music *music;
    bool started;
    bool quitRequested;
    std::vector<std::shared_ptr<GameObject>> objectArray;

public:
    State();
    ~State();

    void Start();
    void Input();
    std::weak_ptr<GameObject> AddObject(GameObject* go);
    std::weak_ptr<GameObject> GetObject(GameObject* go);
    bool QuitRequested();
    void LoadAssets();
    void Update(float dt);
    void Render();
};
#endif

// Links
// https://www.cppstories.com/2014/05/vector-of-objects-vs-vector-of-pointers/
