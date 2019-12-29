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

#endif //COORD_H


