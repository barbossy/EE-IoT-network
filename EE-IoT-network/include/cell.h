#ifndef CELL_H
#define CELL_H

#include <memory>

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

    virtual const std::vector<std::shared_ptr<EndUserIface>>& getUsers() const = 0;

    virtual EResults addUser(std::shared_ptr<EndUserIface>) = 0;
    virtual EResults setInteference(std::map<std::string, std::shared_ptr<CellIface>>) = 0;
    virtual std::string getCellId() = 0;
};

class Cell : public CellIface
{
public:
    Cell(std::string);
    Cell() = default;
    ~Cell() = default;
    Cell(const Cell &) = delete;
    Cell(const Cell &&) = delete;
    Cell& operator =(const Cell&) = delete;
    Cell& operator =(const Cell&&) = delete;
    
    inline const std::vector<std::shared_ptr<EndUserIface>>& getUsers() const override
    {
        return mUsers;
    }

    inline std::string getCellId() override
    {
        return mCellId;
    }

    EResults addUser(std::shared_ptr<EndUserIface>) override;
    EResults setInteference(std::map<std::string, std::shared_ptr<CellIface>>) override;

private:
    std::vector<std::shared_ptr<EndUserIface>> mUsers;
    std::string mCellId;
    EResults mIsInterferenceVaild;

};
#endif // CELL_H
