#pragma once
#include "Event.hpp"

class HandlerFunctionBase {
 public:
    virtual ~HandlerFunctionBase() {}
    void exec(const Event* event) {call(event);}
 private:
    virtual void call(const Event*) = 0;
};
