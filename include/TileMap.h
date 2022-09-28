/**
 * @file TileMap.h
 * @author Alexandre Augusto de Sá dos Santos (150056940@aluno.unb.br)
 * @brief TileMap class header file
 * @version 0.1
 * @date 2022-06-26
 *
 * @copyright Copyright (c) 2022
 *
 */
#ifndef TILEMAP_HEADER
#define TILEMAP_HEADER
#include "TileSet.h"
#include "Component.h"
#include "GameObject.h"

class TileMap : public Component
{
private:
    std::vector<int> tileMatrix;
    TileSet *tileSet;
    int mapWidth;
    int mapHeight;
    int mapDepth;

public:
    TileMap(GameObject &associated, std::string file, TileSet *tileSet);

    std::string type = "TileMap";

    void Load(std::string file);
    void SetTileSet(TileSet *tileSet);
    int &At(int x, int y, int z = 0);

    void Render();
    void RenderLayer(int layer, int cameraX = 0, int cameraY = 0);

    int GetWidth();
    int GetHeight();
    int GetDepth();

    bool Is(std::string type);
    void Update(float dt);
    void NotifyCollision(GameObject &other);
};
#endif