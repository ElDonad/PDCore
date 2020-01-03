#ifndef TILETYPE_H
#define TILETYPE_H

#include <functional>

#include "flagHandler.h"
#include "utils/event.h"
#include "utils/coord.h"
#include "char.h"

namespace PDCore {

class TileType{
public:
    virtual bool isPassable()=0;
    virtual bool isVoid()=0;
    virtual bool isEmpty()=0;
    virtual bool isFlyable()=0;

    virtual ~TileType();

    //events

    virtual Utils::EventResult onCreated(Coord8 pos);
    virtual Utils::EventResult onDestroyed(Coord8 pos);

    virtual Utils::EventResult onStep(Coord8 pos, std::shared_ptr<Char> who);
    virtual Utils::EventResult onFall(Coord8 pos, std::shared_ptr<Char> who);
    virtual Utils::EventResult onLeave(Coord8 pos, std::shared_ptr<Char> who);

};

}

#endif // TILETYPE_H
