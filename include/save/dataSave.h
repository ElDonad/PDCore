#ifndef DATASAVE_H
#define DATASAVE_H

#include <memory>
#include <string>
#include <variant>
#include <optional>
#include <vector>
#include <functional>

namespace PDCore {

class Node {
public:
    using Variant = std::variant<std::string, int16_t, int8_t, float, std::shared_ptr<Node>, std::vector<std::shared_ptr<Node>>, std::nullopt_t>;
    enum WriteState{
        OK,
        OUT_OF_MEMORY
    };
    virtual bool write(std::string tag, Variant toWrite)=0;

    virtual const std::optional<Variant> read(std::string tag="")=0;
    virtual std::optional<Variant> operator[](std::string)=0;
    virtual void operator=(const std::shared_ptr<Node>)=0;//! equivalent to operator[]("")
    virtual std::optional<Variant> operator->()=0;
    virtual std::optional<Variant> operator*()=0;
    virtual ~Node()=0;
};

class DataSaver {

public :
    static std::weak_ptr<DataSaver> the();
    static void setSaveSystem(std::shared_ptr<DataSaver> toSet, std::function<std::shared_ptr<Node>()> nodeCreator);//! Set the dataSaver that will be used to save the gameData
    virtual std::weak_ptr<Node> getRoot()=0;

    virtual ~DataSaver()=0;
    static std::shared_ptr<Node> createNode();
private:
    static std::shared_ptr<DataSaver> m_the; //! Le système de sauvegarde principal, implémenté par le client.
    static std::function<std::shared_ptr<Node>()> m_nodeCreator;
};

}
#endif // DATASAVE_H
