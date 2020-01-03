#ifndef TILE_H
#define TILE_H

namespace PDCore {
/**
 * @brief Background tile class
 *
 * The background is not meant to contain individual tiles, therefore the Tile CLass has no capability to handle single tile behaviour.
 * If such a  behaviour is needed, the tile need to be inherited in the tile array.
 */
class Tile{
public:
    Tile(unsigned int tileId, unsigned int type);
    Tile(const Tile&);
    unsigned int getType();
    unsigned int getId();

private:
    const unsigned int tileId;//!  Stores the tile identifier (to retrieve the TileEntity
    const unsigned int type;

};

}

#endif // TILE_H
