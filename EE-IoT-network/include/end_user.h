#ifndef ENDUSER_H
#define ENDUSER_H

#include <Eigen/Dense>
#include <memory>

#include "interference.h"
#include "link.h"

class EndUserIface
{
public:
    EndUserIface() = default;
    virtual ~EndUserIface() = default;

    virtual float getMinRate() const = 0;
//    virtual std::string getCellId() const = 0;

    virtual void setMinRate(float) = 0;
    virtual void setCellId(std::string) = 0;
    virtual EResults setLink(std::shared_ptr<RayleighChannelIface>) = 0;
};

class EndUser : public EndUserIface
{
public:
    EndUser(const uint32_t&, const float& = 0);
    ~EndUser() = default;
    EndUser(const EndUser&) = delete;
    EndUser(const EndUser&&) = delete;
    EndUser& operator =(const EndUser&) = delete;
    EndUser& operator =(const EndUser&&) = delete;

    EResults setLink(std::shared_ptr<RayleighChannelIface>) override;

    inline float getMinRate() const override
    {
        return mMinRate;
    }
    inline void setMinRate(float minRate) override
    {
        mMinRate = minRate;
    }
    inline void setCellId(std::string cellId) override
    {
        mCellId = cellId;
    }


private:
    std::shared_ptr<LinkIFace> mLink;
    std::shared_ptr<InterferenceIface> mInterference;
    Eigen::Vector<float, Eigen::Dynamic> mTransmitPower;
    std::string mCellId;
    float mMinRate;

};

#endif // ENDUSER_H
