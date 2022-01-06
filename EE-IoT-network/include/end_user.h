#ifndef ENDUSER_H
#define ENDUSER_H

#include<iostream>
#include <vector>

#include "link.h"

class EndUserIface
{
public:
    EndUserIface() = default;
    virtual ~EndUserIface() = default;
};

class EndUser : public EndUserIface
{
public:
    EndUser() = default;
    ~EndUser() = default;
    EndUser(const EndUser&) = delete;
    EndUser(EndUser &&) = delete;
    EndUser& operator=(const EndUser&) = delete;
    EndUser& operator=(const EndUser&&) = delete;

private:
    float mMinRate;
    std::vector<float> mTransmitPowers;
};

#endif // ENDUSER_H
