#ifndef INTERFERENCE_H
#define INTERFERENCE_H

#include <iostream>
#include <vector>
#include <memory>

#include "end_user.h"
#include "link.h"

class InterferenceIface
{
public:
    InterferenceIface() = default;
    virtual ~InterferenceIface() = default;

    virtual void addInterference(std::shared_ptr<EndUserIface>, std::shared_ptr<LinkIFace>) = 0;
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

    void addInterference(std::shared_ptr<EndUserIface>, std::shared_ptr<LinkIFace>) override;

private:
    std::vector<std::pair<std::shared_ptr<EndUserIface>, std::shared_ptr<LinkIFace>>> mInterference;
};

#endif // INTERFERENCE_H
