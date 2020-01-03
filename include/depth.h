#ifndef DEPTH_H
#define DEPTH_H

#include <memory>
#include <array>
#include <vector>
#include "utils/coord.h"

#include "tile.h"
#include "char.h"
#include "save.h"

#define DEPTH_HEIGHT 50
#define DEPTH_WIDTH 50

namespace PDCore {

class Depth {
public:
    unsigned int getLevel();
    Depth();

    Tile getTile(Coord8 coord);
    void setTile(Coord8 coord, Tile);

    template<class Archive>
    void serialize(Archive& ar);

private:
    unsigned int level;
    int terrainSeed;//Should be the only thing needed by the generator to generate the terrain identically
    std::shared_ptr<std::array<Tile, DEPTH_WIDTH * DEPTH_HEIGHT>> backgroundLayer;
    std::vector<std::shared_ptr<Char>> propsLayer;//grass, furnitures,...
    std::vector<std::shared_ptr<Char>> entitiesLayer;//mobs
    bool is

};

template<class Archive>
void Depth::serialize(Archive& ar){
    ar(level, terrainSeed, propsLayer, entitiesLayer);
}

}

#endif // LEVEL_H
