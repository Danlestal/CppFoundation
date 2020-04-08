#pragma once

struct Vector2D {
    float x;
    float y;
    Vector2D() : x(0), y(0) {}
    Vector2D(float x, float y) : x(x), y(y) {}

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

    Vector2D operator*(const float a) const {
        return Vector2D(x * a, y * a);
    }

    Vector2D operator*=(const float a) {
        x = x * a;
        y = y * a;
        return *this;
    }
};
