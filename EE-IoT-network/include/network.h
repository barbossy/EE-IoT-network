#ifndef NETWORK_H
#define NETWORK_H

#include <memory>
#include <vector>

#include "cell.h"
#include "defines.h"

class NetworkIface
{
public:
    NetworkIface() = default;
    virtual ~NetworkIface() = default;

    virtual EResults setNetworkLinks() = 0;

    void fun() {}
};

class Network : public NetworkIface
{
public:
    Network()
    {
        mCells.push_back(std::make_shared<Cell>());
    }
    ~Network() = default;
    Network(const Network&) = delete;
    Network(const Network&&) = delete;
    Network& operator =(const Network&) = delete;
    Network& operator =(const Network&&) = delete;

    EResults setNetworkLinks() override;

private:
    std::vector<std::shared_ptr<CellIface>> mCells;

};

#endif // NETWORK_H
