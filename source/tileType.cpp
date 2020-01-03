#include "tileType.h"

namespace PDCore{

Utils::EventResult TileType::onStep(Coord8 pos, std::shared_ptr<Char>)
{
    return Utils::EventResult::Ok;
}

Utils::EventResult TileType::onFall(PDCore::Utils::Coord<uint8_t>, std::shared_ptr<Char>){
    return Utils::EventResult::Ok;
}

Utils::EventResult TileType::onLeave(PDCore::Utils::Coord<uint8_t>, std::shared_ptr<Char>){
    return Utils::EventResult::Ok;
}

Utils::EventResult TileType::onCreated(PDCore::Utils::Coord<uint8_t>){
    return Utils::EventResult::Ok;
}

Utils::EventResult TileType::onDestroyed(PDCore::Utils::Coord<uint8_t>){
    return Utils::EventResult::Ok;
}

}
