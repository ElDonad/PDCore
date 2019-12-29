#include "save/serializable.h"

namespace PDCore::Utils {

std::vector<std::shared_ptr<Node>> Serializable::serialize(){
    std::vector<std::shared_ptr<Node>> serializedData;

    for (auto sub : m_subbed){
        serializedData.push_back(sub.first());
    }
    return serializedData;
}

void Serializable::deserialize(std::vector<std::shared_ptr<Node> > base){
    for (unsigned int l=0; l != m_subbed.size(); l++){
        m_subbed[l].second(base[l]);
    }
}

void Serializable::subscribe(std::function<std::shared_ptr<Node> ()> serialize, std::function<void (std::shared_ptr<Node>)> deserialize){
    m_subbed.emplace_back(serialize, deserialize);
}

}
