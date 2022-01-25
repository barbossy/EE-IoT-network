#include "link.h"

Link::Link(const uint32_t& numOfSCs)
{
    mChannelCoefficients.resize(numOfSCs);
}

void Link::setChannelCoefficients(std::shared_ptr<RayleighChannelIface> channel)
{
    channel->generateChannel(mChannelCoefficients);
}
