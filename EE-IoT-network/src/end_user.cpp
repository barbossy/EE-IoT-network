#include "end_user.h"

EndUser::EndUser(const uint32_t & numOfSCs, const float& minRate = 0)
    : mMinRate(minRate)
{
    mTransmitPower.resize(numOfSCs);
}
