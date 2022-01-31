#ifndef NETWORK_H
#define NETWORK_H

#include <memory>
#include <map>

#include "cell.h"
#include "defines.h"

class NetworkIface
{
public:
    NetworkIface() = default;
    virtual ~NetworkIface() = default;

    virtual EResults addCell(std::shared_ptr<CellIface>) = 0;
};

class Network : public NetworkIface
{
public:
    Network()
    {
//        mCells.push_back(std::make_shared<Cell>());
    }
    ~Network() = default;
    Network(const Network&) = delete;
    Network(const Network&&) = delete;
    Network& operator =(const Network&) = delete;
    Network& operator =(const Network&&) = delete;

    EResults addCell(std::shared_ptr<CellIface>) override;

private:
    std::map<std::string, std::shared_ptr<CellIface>> mCells;

};

#endif // NETWORK_H
