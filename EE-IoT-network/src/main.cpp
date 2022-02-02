#include <iostream>
#include <memory>

#include "network.h"

int main()
{
    Network network;
    std::shared_ptr cell = std::make_shared<Cell>("p1");
    cell->addUser(std::make_shared<EndUser>(1,1));
    cell->addUser(std::make_shared<EndUser>(1,2));

    network.addCell(cell);

    std::shared_ptr cell2 = std::make_shared<Cell>("p2");
    cell2->addUser(std::make_shared<EndUser>(1,3));
    network.addCell(cell2);

    network.setNetworkLinks();

    return 0;
}
