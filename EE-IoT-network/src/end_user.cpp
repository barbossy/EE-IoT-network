#include "end_user.h"

EndUser::EndUser(const uint32_t & numOfSCs, const float& minRate)
    : mMinRate(minRate)
{
    mTransmitPower.resize(numOfSCs);
}

EResults EndUser::setLink(std::shared_ptr<RayleighChannelIface> rayleighChannel)
{
    mLink->setChannelCoefficients(rayleighChannel);
    return EResults::SUCCESS;
}
