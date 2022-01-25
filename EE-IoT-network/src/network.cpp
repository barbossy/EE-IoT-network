#include "network.h"

EResults Network::setNetworkLinks()
{
    for (const auto& cell : mCells)
    {
        for (const auto& user : cell->getUsers())
        {
            std::cout << std::get<0>(user)->getMinRate() << std::endl;
        }
    }

}
