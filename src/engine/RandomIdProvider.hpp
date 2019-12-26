#pragma once

#include "IdentifierProvider.hpp"

class RandomIdProvider : public IdentifierProvider {
 public:
    long getUID();
};
