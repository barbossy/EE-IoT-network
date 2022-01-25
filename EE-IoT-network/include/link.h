#ifndef LINK_H
#define LINK_H

#include <iostream>
#include <Eigen/Dense>
#include <memory>

#include "rayleigh_channel.h"

class LinkIFace
{
public:
    LinkIFace() = default;
    virtual ~LinkIFace() = default;

    virtual void setChannelCoefficients(std::shared_ptr<RayleighChannelIface>) = 0;
    virtual Eigen::Vector<float, Eigen::Dynamic> getChannelCoefficients() = 0;
};

class Link : public LinkIFace
{
public:
    Link(const uint32_t&);
    ~Link() = default;
    Link() = default;
    Link(const Link&) = delete;
    Link(const Link&&) = delete;
    Link& operator =(const Link&) = delete;
    Link& operator =(const Link&&) = delete;

    void setChannelCoefficients(std::shared_ptr<RayleighChannelIface>) override;
    Eigen::Vector<float, Eigen::Dynamic> getChannelCoefficients() override { return mChannelCoefficients; }

private:
    float mNoise;
    float mPathLoss;
    Eigen::Vector<float, Eigen::Dynamic> mChannelCoefficients;
};

#endif // LINK_H
