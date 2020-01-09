#pragma once
#include <string>

class Component {
 public:
    virtual std::string getType() = 0;
};
