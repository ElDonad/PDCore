#ifndef DEPTH_H
#define DEPTH_H

#include <memory>
#include <array>
#include <vector>
#include "utils/coord.h"

#include "tile.h"
#include "save.h"

#define DEPTH_HEIGHT 50
#define DEPTH_WIDTH 50

namespace PDCore {

class Entity;//TEMP
class Generator;

class Depth {
public:
    unsigned int getLevel();
    Depth(std::shared_ptr<Generator>);

    Tile getTile(Coord8 coord);
    void setTile(Coord8 coord, Tile);

    std::shared_ptr<Entity> getProp(Coord8);
    void setProp(Coord8, std::shared_ptr<Entity>);

    std::shared_ptr<Entity> getEntity(Coord8);
    void setEntity(Coord8, std::shared_ptr<Entity>);


    void generate();//generate the backgroundLayer data, populate the propsLayer and entitiesLayer.
    void load();//regenerate the backgroundLayer
    void unload();//delete the backgroundLayer data to save memory space.

    template<class Archive>
    void serialize(Archive& ar);

private:
    unsigned int level;
    int depthSeed;//Should be the only thing needed by the generator to generate the terrain identically
    std::shared_ptr<std::array<Tile, DEPTH_WIDTH * DEPTH_HEIGHT>> backgroundLayer;
    std::map<Coord8, std::shared_ptr<Entity>> propsLayer;//grass, furnitures,...
    std::map<Coord8, std::shared_ptr<Entity>> entitiesLayer;//mobs
    bool isGenerated;
    std::shared_ptr<Generator> generator;

};

template<class Archive>
void Depth::serialize(Archive& ar){
    ar(level, depthSeed, propsLayer, entitiesLayer);
}

}

#endif // LEVEL_H
