#include "cell.h"


Cell::Cell() : mIsInterferenceVaild(EResults::INTERFERENCE_INVALID)
{
}

EResults Cell::setRayleighChannel(std::shared_ptr<RayleighChannel> rayleighChannel)
{
    mRayleighChannel = rayleighChannel;
    return EResults::SUCCESS;
}

EResults Cell::addUser(std::tuple<std::shared_ptr<EndUserIface>, std::shared_ptr<LinkIFace>, std::shared_ptr<InterferenceIface>> user)
{
    std::get<LINK_IDX>(user)->setChannelCoefficients(mRayleighChannel);
    mUsers.push_back(user);

    return EResults::SUCCESS;
}
