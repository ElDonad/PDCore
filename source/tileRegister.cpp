#include "tileRegister.h"

namespace PDCore {

unsigned int TileRegister::nextId = 0;

std::optional<std::shared_ptr<TileType>> TileRegister::getTileType(unsigned int tileTypeId){
    auto type = types.find(tileTypeId);
    if (type == types.end()) return std::nullopt;
    else return type->second;
}

std::optional<unsigned int> TileRegister::getTileTypeId(std::shared_ptr<TileType> type){
    for (auto a : types){
        if (a.second == type) return a.first;
        else return std::nullopt;
    }
}

unsigned int TileRegister::registerTileType(std::shared_ptr<TileType> type){
    types.insert(std::pair<unsigned int, std::shared_ptr<TileType>>(nextId, type));
    nextId++;
}


}
