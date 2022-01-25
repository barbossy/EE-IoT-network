#ifndef DEFINES_H
#define DEFINES_H

#include <string>

static const uint8_t END_USER_IDX = 0;
static const uint8_t LINK_IDX = 1;
static const uint8_t INTERFERENCE_IDX = 2;

enum class EResults
{
    SUCCESS,
    INTERFERENCE_INVALID,
    INTERFERENCE_VALID
};

#endif // DEFINES_H
