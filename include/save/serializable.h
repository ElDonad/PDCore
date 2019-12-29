#ifndef SERIALIZABLE_H
#define SERIALIZABLE_H

#include <functional>
#include "save/dataSave.h"

namespace PDCore::Utils {

class Serializable{
public:
    void subscribe(std::function<std::shared_ptr<Node>()> serialize, std::function<void(std::shared_ptr<Node>)> deserialize);
    std::vector<std::shared_ptr<Node>> serialize();
    void deserialize(std::vector<std::shared_ptr<Node>> base);
    virtual ~Serializable();

private:
    std::vector<std::pair<std::function<std::shared_ptr<Node>()>, std::function<void(std::shared_ptr<Node>)>>> m_subbed;
};

}

#endif // SERIALIZABLE_H
