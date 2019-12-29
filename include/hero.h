#ifndef HERO_H
#define HERO_H

#include <memory>
#include "char.h"

namespace PDCore {

class Hero : public Char {
public:
    enum HeroType{
        Rogue,
        Knight,
        Mage
    };

    friend void initHero(std::shared_ptr<Hero>);
};
}

#endif // HERO_H
