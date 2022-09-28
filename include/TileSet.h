/**
 * @file TileSet.h
 * @author Alexandre Augusto de Sá dos Santos (150056940@aluno.unb.br)
 * @brief TileSet class header file
 * @version 0.1
 * @date 2022-07-11
 *
 * @copyright Copyright (c) 2022
 *
 */
#ifndef TILESET_HEADER
#define TILESET_HEADER
#include "GameObject.h"
#include "Sprite.h"

class TileSet
{
private:
    Sprite tileSet;
    int rows;
    int columns;
    int tileWidth;
    int tileHeight;

public:
    TileSet(GameObject &associated, int tileWidth, int tileHeight, std::string file);

    void RenderTile(unsigned index, float x, float y);

    int GetTileWidth();
    int GetTileHeight();
};

#endif
