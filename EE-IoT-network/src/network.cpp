#include "network.h"

//EResults Network::setNetworkLinks()
//{
//    for (const auto& cell : mCells)
//    {
//        for (const auto& user : cell->getUsers())
//        {
//            std::cout << user->getMinRate() << std::endl;
//        }
//    }

//}

EResults Network::addCell(std::shared_ptr<CellIface> cell)
{
    if (mCells.find(cell->getCellId()) == mCells.end())
    {
        return EResults::CELL_ID_EXISTS;
    }
    mCells.insert({cell->getCellId(), cell});
    return EResults::SUCCESS;
}

