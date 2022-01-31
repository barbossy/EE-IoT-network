#ifndef INTERFERENCE_H
#define INTERFERENCE_H

#include <iostream>
#include <vector>
#include <memory>

#include "defines.h"
//#include "end_user.h"
#include "link.h"

class CellIface;
class EndUserIface;

class InterferenceIface
{
public:
    InterferenceIface() = default;
    virtual ~InterferenceIface() = default;

    virtual EResults addInterference(std::shared_ptr<EndUserIface>, std::shared_ptr<LinkIFace>) = 0;
};

class Interference : public InterferenceIface
{
public:
    Interference() = default;
    ~Interference() = default;
    Interference(const Interference&) = delete;
    Interference(const Interference&&) = delete;
    Interference& operator =(const Interference&) = delete;
    Interference& operator =(const Interference&&) = delete;

    EResults addInterference(std::shared_ptr<EndUserIface>, std::shared_ptr<LinkIFace>) override;

    EResults addIntercellInterference(std::shared_ptr<CellIface>);
    EResults addIntracellInterference(std::vector<std::shared_ptr<CellIface>>&);

private:
    std::vector<std::pair<std::shared_ptr<EndUserIface>, std::shared_ptr<LinkIFace>>> mInterference;
};

#endif // INTERFERENCE_H
