#ifndef COORD_H
#define COORD_H

#include <memory>

namespace PDCore::Utils {

template<typename T>
class Coord{

public:
    Coord(T x, T y);
    T x;
    T y;
};

template<typename T>
class Rect{

public:
    Rect(Coord<T> pos, Coord<T> dim);

    Coord<T> pos;
    Coord<T> dim;

    T h();
    void seth(T);
    T w();
    void setw(T);
    T x();
    void setx(T);
    T y();
    void sety(T);

    bool intersect(std::shared_ptr<Rect<T>> other, bool inclusive=true);

};


}

#include "impl/coord.tpp"

#define Coord8 PDCore::Utils::Coord<uint8_t>

#endif //COORD_H


