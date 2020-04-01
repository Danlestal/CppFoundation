#pragma once
#include <string>

class Component {
 protected:
    long mActorId;
 public:
    virtual ~Component() {}
    virtual std::string getType() = 0;
};
