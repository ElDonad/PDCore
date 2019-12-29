#ifndef TILETYPE_H
#define TILETYPE_H

namespace PDCore {

class TileType{
public:
    virtual bool isPassable()=0;
    virtual bool isVoid()=0;

    //events

};

}

#endif // TILETYPE_H
