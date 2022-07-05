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
#include "Face.h"

class State
{
private:
    Sprite *bg;
    Music *music;
    bool quitRequested;
    std::vector<std::unique_ptr<GameObject>> objectArray;

public:
    State();
    ~State();

    void Input();
    void AddObject(int mouseX, int mouseY);
    bool QuitRequested();
    void LoadAssets();
    void Update(float dt);
    void Render();
};
#endif

// Links
// https://www.cppstories.com/2014/05/vector-of-objects-vs-vector-of-pointers/
