#ifndef CELL_H
#define CELL_H

#include <memory>
#include <tuple>

#include "defines.h"
#include "end_user.h"
#include "interference.h"
#include "link.h"
#include "rayleigh_channel.h"

class CellIface
{
public:
    CellIface() = default;
    virtual ~CellIface() = default;
};

class Cell : public CellIface
{
public:
    Cell();
    ~Cell() = default;
    Cell(const Cell &) = delete;
    Cell(const Cell &&) = delete;
    Cell& operator =(const Cell&) = delete;
    Cell& operator =(const Cell&&) = delete;
    
    EResults addUser(std::tuple<std::shared_ptr<EndUserIface>, std::shared_ptr<LinkIFace>, std::shared_ptr<InterferenceIface>>);
    EResults setRayleighChannel(std::shared_ptr<RayleighChannel>);

private:
    std::vector<std::tuple<std::shared_ptr<EndUserIface>, std::shared_ptr<LinkIFace>, std::shared_ptr<InterferenceIface>>> mUsers;
    std::shared_ptr<RayleighChannelIface> mRayleighChannel;
    EResults mIsInterferenceVaild;

};
#endif // CELL_H
