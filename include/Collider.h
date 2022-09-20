// /**
//  * @file Collider.h
//  * @author Alexandre Augusto de Sá dos Santos (150056940@aluno.unb.br)
//  * @brief Collider class header file
//  * @version 0.1
//  * @date 2022-08-20
//  *
//  * @copyright Copyright (c) 2022
//  *
//  */
// #ifndef COLLIDER_HEADER
// #define COLLIDER_HEADER
// #include "Component.h"
// #include "GameObject.h"
// #include "Sprite.h"
// #include "Rect.h"
// #include "Vec2.h"
// #include <vector>
// #include <cmath>
// #include <string>

// class Collider : public Component
// {
// private:
//     Vec2 scale;
//     Vec2 offset;

// public:
//     std::string type = "Collider";
//     Rect box;

//     Collider(GameObject &associated, Vec2 scale = {1, 1}, Vec2 offset = {0, 0});

//     void Start();
//     void Update(float dt);
//     void Render();
//     bool Is(std::string type);
//     void SetScale(Vec2 scale);
//     void SetOffset(Vec2 offset);
// };

// #endif
