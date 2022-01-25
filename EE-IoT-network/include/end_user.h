#ifndef ENDUSER_H
#define ENDUSER_H

#include <Eigen/Dense>

class EndUserIface
{
public:
    EndUserIface() = default;
    virtual ~EndUserIface() = default;

    virtual float getMinRate() const = 0;
};

class EndUser : public EndUserIface
{
public:
    EndUser(const uint32_t&, const float& = 0);
    ~EndUser() = default;
    EndUser() = default;
    EndUser(const EndUser&) = delete;
    EndUser(const EndUser&&) = delete;
    EndUser& operator =(const EndUser&) = delete;
    EndUser& operator =(const EndUser&&) = delete;

    inline float getMinRate() const override
    {
        return mMinRate;
    }

private:
    float mMinRate;
    Eigen::Vector<float, Eigen::Dynamic> mTransmitPower;

};

#endif // ENDUSER_H
