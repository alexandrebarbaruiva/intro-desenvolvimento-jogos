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
#define LEFT_ARROW_KEY SDLK_LEFT
#define RIGHT_ARROW_KEY SDLK_RIGHT
#define UP_ARROW_KEY SDLK_UP
#define DOWN_ARROW_KEY SDLK_DOWN
#define ESCAPE_KEY SDLK_ESCAPE
#define SPACE_KEY SDLK_SPACE
#define CTRL_KEY SDLK_LCTRL
#define LEFT_MOUSE_BUTTON SDL_BUTTON_LEFT
#include "SDL_include.h"
#include <unordered_map>
#include <string>

class InputManager
{
private:
    int mouseUpdate[6];
    bool mouseState[6];

    std::unordered_map<int, bool> keyState;
    std::unordered_map<int, int> keyUpdate;

    bool quitRequested;
    int updateCounter;
    int mouseX;
    int mouseY;

public:
    InputManager();
    ~InputManager();
    static InputManager &GetInstance();
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
