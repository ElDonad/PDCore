#include "tile.h"

namespace PDCore {

unsigned int Tile::getId(){
    return tileId;
}

unsigned int Tile::getType(){
    return type;
}

Tile::Tile(unsigned int tileId, unsigned int type) : tileId{tileId}, type{type} {};

Tile::Tile(const Tile& other) : tileId{other.tileId}, type{other.type} {}

}
