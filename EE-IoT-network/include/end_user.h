#ifndef ENDUSER_H
#define ENDUSER_H

#include <Eigen/Dense>

class EndUserIface
{
public:
    EndUserIface() = default;
    virtual ~EndUserIface() = default;
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

private:
    float mMinRate;
    Eigen::Vector<float, Eigen::Dynamic> mTransmitPower;

};

#endif // ENDUSER_H
