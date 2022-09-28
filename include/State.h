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
#include "GameObject.h"
#include <vector>
#include <string>
#include <memory>

class State
{
protected:
    void StartArray();
    virtual void UpdateArray(float dt);
    virtual void RenderArray();

    bool started;
    bool quitRequested;
    bool popRequested;

    std::vector<std::shared_ptr<GameObject>> objectArray;

public:
    State();
    virtual ~State();

    virtual void Start() = 0;
    virtual void Pause() = 0;
    virtual void Resume() = 0;

    virtual void LoadAssets() = 0;
    virtual void Update(float dt) = 0;
    virtual void Render() = 0;

    virtual std::weak_ptr<GameObject> AddObject(GameObject *object);
    virtual std::weak_ptr<GameObject> GetObjectPtr(GameObject *object);
    virtual std::vector<std::weak_ptr<GameObject>> QueryObjectsBy(std::string component);

    bool PopRequested();
    bool QuitRequested();
};
#endif