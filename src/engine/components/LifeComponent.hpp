#pragma once
namespace engine {

class LifeComponent {
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

    bool isAlive() {
        return (mLife > 0);
    }
};
}  // namespace engine
