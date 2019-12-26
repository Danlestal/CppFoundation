#pragma once

#include <string>
#include "Component.hpp"


class LifeComponent : public Component {
 private:
    int mLife;
 public:
    explicit LifeComponent(int initialLife) {
        mLife = initialLife;
    }

    int updateLife(int lifeDelta) {
        mLife += lifeDelta;
        return mLife;
    }

    int getLife() {
        return mLife;
    }

    bool isAlive() {
        return (mLife > 0);
    }

    std::string getType(){
        return "LifeComponent";
    }
};

