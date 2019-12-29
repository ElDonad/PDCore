#include "save/dataSave.h"
#include <exception>

namespace PDCore{

DataSaver::~DataSaver(){}

Node::~Node() {}

void DataSaver::setSaveSystem(std::shared_ptr<DataSaver> saver, std::function<std::shared_ptr<Node>()> nodeCreator){
    DataSaver::m_the = std::shared_ptr<DataSaver>(saver);
    DataSaver::m_nodeCreator = nodeCreator;
}

std::shared_ptr<DataSaver> DataSaver::m_the = nullptr;

std::weak_ptr<DataSaver> DataSaver::the(){
    if (m_the == nullptr){
        throw std::runtime_error("Main DataSaver not initialized !!");
    }
    else return m_the;
}

std::shared_ptr<Node> DataSaver::createNode(){
    return DataSaver::m_nodeCreator();
}

}
