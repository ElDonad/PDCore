#include "depth.h"

namespace PDCore {



Depth createDepth(unsigned int level){
    auto depth = Depth();
    depth.level = level;

    return depth;
}

unsigned int Depth::getLevel(){
    return level;
}

}
