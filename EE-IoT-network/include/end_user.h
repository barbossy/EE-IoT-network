#ifndef ENDUSER_H
#define ENDUSER_H

#include <Eigen/Dense>
#include <memory>
#include <map>

#include "link.h"

class CellIface;
class Cell;

class EndUserIface
{
public:
    EndUserIface() = default;
    virtual ~EndUserIface() = default;

    virtual float getMinRate() const = 0;
    virtual std::string getCellId() const = 0;

    virtual void setMinRate(float) = 0;
    virtual void setCellId(std::string) = 0;
    virtual EResults setLink(std::shared_ptr<RayleighChannelIface>) = 0;
    virtual EResults setInterference(std::map<std::string, std::shared_ptr<CellIface>>&) = 0;
};

class EndUser : public EndUserIface,
                public std::enable_shared_from_this<EndUser>
{
public:
    EndUser(const uint32_t&, const float& = 0);
    ~EndUser() = default;
    EndUser(const EndUser&) = delete;
    EndUser(const EndUser&&) = delete;
    EndUser& operator =(const EndUser&) = delete;
    EndUser& operator =(const EndUser&&) = delete;

    EResults setLink(std::shared_ptr<RayleighChannelIface>) override;
    EResults setInterference(std::map<std::string, std::shared_ptr<CellIface>> &) override;

    inline float getMinRate() const override
    {
        return mMinRate;
    }
    inline std::string getCellId() const override
    {
        return mCellId;
    }
    inline void setMinRate(float minRate) override
    {
        mMinRate = minRate;
    }
    inline void setCellId(std::string cellId) override
    {
        mCellId = cellId;
    }

    inline std::shared_ptr<EndUser> get()
    {
        return shared_from_this();
    }

private:
    std::shared_ptr<LinkIFace> mLink;
    std::vector<std::pair<std::shared_ptr<EndUserIface>, std::shared_ptr<LinkIFace>>> mInterference;
    Eigen::Vector<float, Eigen::Dynamic> mTransmitPower;
    std::string mCellId;
    float mMinRate;

};

#endif // ENDUSER_H
