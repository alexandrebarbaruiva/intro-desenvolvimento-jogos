/**
 * @file InputManager.h
 * @author Alexandre Augusto de Sá dos Santos (150056940@aluno.unb.br)
 * @brief InputManager class header file
 * @version 0.1
 * @date 2022-07-20
 *
 * @copyright Copyright (c) 2022
 *
 */
#ifndef INPUT_HEADER
#define INPUT_HEADER
#define INCLUDE_SDL_IMAGE
#define INCLUDE_SDL_MIXER
#include "SDL_include.h"
#include <string>

class InputManager
{
private:
    int mouseUpdate[6];
    bool mouseState[6];

    // keyState
    // keuUpdate

    bool quitRequested;
    int updateCounter;
    int mouseX;
    int mouseY;

    InputManager();
    ~InputManager();

public:
    InputManager &GetInstance();
    void Update();

    bool KeyPress(int key);
    bool KeyRelease(int key);
    bool IsKeyDown(int key);

    bool MousePress(int button);
    bool MouseRelease(int button);
    bool IsMouseDown(int button);

    int GetMouseX();
    int GetMouseY();

    bool QuitRequested();
};

#endif
