#pragma once

#include <map>
#include "Component.hpp"

class Actor {
 private:
    long mId;
   //  std::map<char, Component> first;

 public:
    Actor(long id);
    ~Actor();
};

