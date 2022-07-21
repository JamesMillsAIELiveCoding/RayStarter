#pragma once

#include <raylib.h>
#include <functional>

using std::initializer_list;

typedef struct Vec2
{    
    union
    {
        struct
        {
            float x;
            float y;
        };

        float asArray[2];
    };

    Vec2();
    Vec2(float _x, float _y);
    Vec2(initializer_list<float> _values);

    float Magnitude() const;
    void Normalize();

    operator Vector2() const;

    static Vec2 Normalized(const Vec2& _toNormalize);
    static float Distance(const Vec2& _lhs, const Vec2& _rhs);
    static float Dot(const Vec2& _lhs, const Vec2& _rhs);
    static Vec2 Rotate(const Vec2& _vec, const float& _amount);

    static Vec2 zero;
    static Vec2 one;
    static Vec2 up;
    static Vec2 down;
    static Vec2 right;
    static Vec2 left;
    
} Vec2;

extern Vec2 operator -(const Vec2& _lhs);
    
extern bool operator ==(const Vec2& _lhs, const Vec2& _rhs);
extern bool operator !=(const Vec2& _lhs, const Vec2& _rhs);
    
extern bool operator >(const Vec2& _lhs, const Vec2& _rhs);
extern bool operator <(const Vec2& _lhs, const Vec2& _rhs);
extern bool operator >=(const Vec2& _lhs, const Vec2& _rhs);
extern bool operator <=(const Vec2& _lhs, const Vec2& _rhs);
    
extern Vec2 operator +(const Vec2& _lhs, const Vec2& _rhs);
extern Vec2 operator -(const Vec2& _lhs, const Vec2& _rhs);
extern Vec2 operator *(const Vec2& _lhs, const Vec2& _rhs);
extern Vec2 operator *(const Vec2& _lhs, const float& _rhs);