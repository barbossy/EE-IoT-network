#ifndef CELL_H
#define CELL_H

#include <memory>
#include <tuple>

#include "defines.h"
#include "end_user.h"
#include "interference.h"
#include "link.h"
#include "rayleigh_channel.h"

typedef std::tuple<std::shared_ptr<EndUserIface>, std::shared_ptr<LinkIFace>, std::shared_ptr<InterferenceIface>> User;

class CellIface
{
public:
    CellIface() = default;
    virtual ~CellIface() = default;

    virtual const std::vector<User>& getUsers() const = 0;
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
    
    inline const std::vector<User>& getUsers() const override
    {
        return mUsers;
    }

    EResults addUser(User);
    EResults setRayleighChannel(std::shared_ptr<RayleighChannel>);

private:
    std::vector<User> mUsers;
    std::shared_ptr<RayleighChannelIface> mRayleighChannel;
    EResults mIsInterferenceVaild;

};
#endif // CELL_H
