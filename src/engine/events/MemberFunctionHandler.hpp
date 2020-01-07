#pragma once

template < class T, class EventT > class MemberFunctionHandler : public HandlerFunctionBase {
 public:
    typedef void (T::*MemberFunc)(EventT*);
    MemberFunctionHandler(T* instance, MemberFunc memFn) : mInstance(instance), mFunction(memFn) {}
    void call(const Event* event) {
        (mInstance->*mFunction)(static_cast< EventT* >(event));
    }
 private:
    T* mInstance;
    MemberFunc mFunction;
};
