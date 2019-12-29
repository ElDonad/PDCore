#ifndef DEPTH_H
#define DEPTH_H

#include "save/serializable.h"

namespace PDCore {

class Depth : Utils::Serializable {
public:
    unsigned int getLevel();

    friend Depth createDepth(unsigned int level);

private:
    unsigned int level;

};
}

#endif // LEVEL_H
