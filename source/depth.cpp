#include "depth.h"

namespace PDCore {

Depth::Depth(){
}

unsigned int Depth::getLevel(){
    return level;
}

Tile Depth::getTile(Coord8 coord){
    return backgroundLayer->operator[](coord.x + coord.y * DEPTH_WIDTH);
}

}
