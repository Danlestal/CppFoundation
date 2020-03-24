#pragma once

struct Vector2D {
    float x;
    float y;
    explicit Vector2D(int x = 0, int y = 0) : x(x), y(y) {}

    Vector2D& operator=(const Vector2D& a) {
        x = a.x;
        y = a.y;
        return *this;
    }

    Vector2D operator+(const Vector2D& a) const {
        return Vector2D(x + a.x, y + a.y);
    }

    Vector2D operator-(const Vector2D& a) const {
        return Vector2D(x - a.x, y - a.y);
    }

    Vector2D operator+=(const Vector2D& a) {
        x += a.x;
        y += a.y;
        return *this;
    }

    Vector2D operator-=(const Vector2D& a) {
        x -= a.x;
        y -= a.y;
        return *this;
    }

    Vector2D operator*(const int a) const {
        return Vector2D(x * a, y * a);
    }

    Vector2D operator*=(const int a) {
        x = x * a;
        y = y * a;
        return *this;
    }
};