#ifndef ENDUSER_H
#define ENDUSER_H

#include<iostream>
#include <vector>

class EndUserIface
{
public:
    EndUserIface() = default;
    virtual ~EndUserIface() = default;
};

class EndUser : public EndUserIface
{
public:
    EndUser();
    ~EndUser() = default;
    EndUser(const EndUser&) = delete;
    EndUser(EndUser &&) = delete;
    EndUser& operator=(const EndUser&) = delete;
    EndUser& operator=(const EndUser&&) = delete;

private:
    float mRate;
    float mMinRate;
    float mAlpha;
    float mBeta;
    std::vector<float> mTransmitPowers;
    std::vector<float> mChannelCoefficients;

};

#endif // ENDUSER_H
