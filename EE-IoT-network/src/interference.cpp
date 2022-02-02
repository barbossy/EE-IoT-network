#include "interference.h"

EResults Interference::addInterference(std::shared_ptr<EndUserIface> interferedUser, std::shared_ptr<LinkIFace> interferedLink)
{
    mInterference.push_back({interferedUser, interferedLink});
    return EResults::SUCCESS;
}

