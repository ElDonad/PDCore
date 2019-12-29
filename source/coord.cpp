#include "utils/coord.h"

namespace PDCore::Utils {

template<typename T>
Coord<T>::Coord(T x, T y){
    this->x = x;
    this->y = y;
}

template<typename T>
T Rect<T>::h(){
    return dim.x;
}

template<typename T>
T Rect<T>::w(){
    return dim.y;
}

template<typename T>
T Rect<T>::x(){
    return pos.x;
}

template<typename T>
T Rect<T>::y(){
    return pos.y;
}

template<typename T>
void Rect<T>::seth(T h){
    dim.x = h;
}

template<typename T>
void Rect<T>::setw(T w){
    dim.y = w;
}

template<typename T>
void Rect<T>::setx(T x){
    pos.x = x;
}

template<typename T>
void Rect<T>::sety(T y){
    dim.y = y;
}


template<typename T>
bool Rect<T>::intersect(std::shared_ptr<Rect<T>> b, bool inclusive){
    if (inclusive){
        if(x() <= b->x() + b->h() && x() + h() >= b->x()&&
           y() <= b->y() + b->w() && y() + w() >= b->y()){
            return true;
        }
        else return false;
    }
    else{
        if(x() <= b->x() + b->h() && x() + h() >= b->x()&&
           y() <= b->y() + b->w() && y() + w() >= b->y()){
            return true;
        }
        else return false;
    }
}

}
