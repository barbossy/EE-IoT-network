#include <iostream>
#include <memory>

#include "network.h"

int main()
{
    Network network;
    network.addCell(std::make_shared<Cell>("p1"));
    network.addCell(std::make_shared<Cell>("p2"));


    return 0;
}
