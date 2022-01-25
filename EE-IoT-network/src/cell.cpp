#include "cell.h"

Cell::Cell() : mIsInterferenceVaild(EResults::INTERFERENCE_INVALID)
{
    // for test
    mUsers.push_back({std::make_shared<EndUser>(1,2), std::make_shared<Link>(), std::make_shared<Interference>()});
}

EResults Cell::setRayleighChannel(std::shared_ptr<RayleighChannel> rayleighChannel)
{
    mRayleighChannel = rayleighChannel;
    return EResults::SUCCESS;
}

EResults Cell::addUser(User user)
{
    std::get<LINK_IDX>(user)->setChannelCoefficients(mRayleighChannel);
    mUsers.push_back(user);

    return EResults::SUCCESS;
}
