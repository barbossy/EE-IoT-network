#ifndef LINK_H
#define LINK_H

#include <iostream>
#include <Eigen/Dense>

class LinkIFace
{
public:
    LinkIFace() = default;
    virtual ~LinkIFace() = default;
};

class Link : public LinkIFace
{
public:
    Link(const uint32_t&);
    ~Link() = default;
    Link() = delete;
    Link(const Link&) = delete;
    Link(const Link&&) = delete;
    Link& operator =(const Link&) = delete;
    Link& operator =(const Link&&) = delete;

    float calculateLinkThroughput(const Eigen::Vector<float, Eigen::Dynamic>&);

private:
    float mNoise;
    Eigen::Vector<float, Eigen::Dynamic> mChannelCoefficients;
};

#endif // LINK_H
