#ifndef TILEREGISTER_H
#define TILEREGISTER_H

#include <memory>
#include <map>
#include <optional>

#include "tileType.h"

namespace PDCore {

class TileRegister{
    static unsigned int registerTileType(std::shared_ptr<TileType> type);
    static std::optional<unsigned int> getTileTypeId(std::shared_ptr<TileType> type);
    static std::optional<std::shared_ptr<TileType>> getTileType(unsigned int tileId);

private:
    static std::map<unsigned int, std::shared_ptr<TileType>> types;
    static unsigned int nextId;
};

TileRegister::nextId = 0;

}

#endif // TILEREGISTER_H
