#include "cell.h"

Cell::Cell(std::string cellId) : mCellId(cellId), mIsInterferenceVaild(EResults::INTERFERENCE_INVALID)
{
}

EResults Cell::addUser(std::shared_ptr<EndUserIface> user)
{
    user->setCellId(mCellId);
    mUsers.push_back(user);
    return EResults::SUCCESS;
}
