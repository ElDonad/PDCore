#ifndef GENERATOR_H
#define GENERATOR_H

#include <memory>

#include "depth.h"
#include "tile.h"
#include "flagHandler.h"

namespace PDCore {

class Entity;//TEMP

/**
 * @brief The class responsible for all the generation of a depth.
 *
 * The generation functions cannot get any parameter, so all additional information has to be provided
 * at construction time, and it is good practice to create one generator per Depth.
 */

class Generator{
public:
    virtual ~Generator();
    virtual std::shared_ptr<Tile> generateBackground()=0;//called during the first generation and every time the background needs to be regenerated.
    virtual std::map<Coord8, std::shared_ptr<Entity>> populateProps()=0;//called once during the first generation.
    virtual std::map<Coord8, std::shared_ptr<Entity>> populateEntities()=0;//called once during the first generation.
};

}

#endif // GENERATOR_H
