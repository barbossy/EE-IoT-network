#include "network.h"

EResults Network::setNetworkLinks()
{
    for (const auto& cell : mCells)
    {
        for (const auto& user : cell.second->getUsers())
        {
            user->setInterference(mCells);
        }
    }
    return EResults::SUCCESS;
}

EResults Network::addCell(std::shared_ptr<CellIface> cell)
{
    mCells.insert({cell->getCellId(), cell});
    return EResults::SUCCESS;
}

EResults EndUser::setInterference(std::map<std::string, std::shared_ptr<CellIface>>& cells)
{
    for (const auto& user : cells[getCellId()]->getUsers())
    {
        if (user != std::dynamic_pointer_cast<EndUserIface>(get()))
        {
            mInterference.push_back({user, mLink});
        }
    }
    for (const auto& cell : cells)
    {
        if (getCellId() != cell.second->getCellId())
        {
            for (const auto& user : cell.second->getUsers())
            {
                mInterference.push_back({user, std::make_shared<Link>(2)});
            }
        }
    }
    return EResults::INTERFERENCE_VALID;
}


