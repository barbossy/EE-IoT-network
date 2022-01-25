#ifndef RAYLEIGHCHANNEL_H
#define RAYLEIGHCHANNEL_H

#include <Eigen/Dense>

#include "defines.h"

class RayleighChannelIface
{
public:
    RayleighChannelIface() = default;
    virtual ~RayleighChannelIface() = default;

    virtual EResults generateChannel(Eigen::Vector<float, Eigen::Dynamic>&) = 0;
};

class RayleighChannel : public RayleighChannelIface
{
public:
    RayleighChannel() = default;
    ~RayleighChannel() = default;
    RayleighChannel(const RayleighChannel&) = delete;
    RayleighChannel(const RayleighChannel&&) = delete;
    RayleighChannel& operator =(const RayleighChannel&) = delete;
    RayleighChannel& operator =(const RayleighChannel&&) = delete;

    EResults generateChannel(Eigen::Vector<float, Eigen::Dynamic>&) override;
};

#endif // RAYLEIGHCHANNEL_H
