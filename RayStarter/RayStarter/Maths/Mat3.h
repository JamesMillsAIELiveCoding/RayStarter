#pragma once

#include "Vec2.h"

struct Mat3
{
    union
    {
        struct
        {
            float m11;
            float m12;
            float m13;
            float m21;
            float m22;
            float m23;
            float m31;
            float m32;
            float m33;
        };

        float asArray[9];
    };

    Mat3();
    Mat3(float _m11, float _m12, float _m13, float _m21, float _m22, float _m23, float _m31, float _m32, float _m33);

    void SetTranslation(float _transX, float _transY);
    void SetTranslation(Vec2 _trans);
    void Translate(float _transX, float _transY);
    void Translate(Vec2 _trans);
    Vec2 GetTranslation();

    void SetRotationX(float _rot);
    void SetRotationY(float _rot);
    void SetRotationZ(float _rot);
    float GetRotationX() const;
    float GetRotationY() const;
    float GetRotationZ() const;

    void SetScale(float _scaleX, float _scaleY);
    void SetScale(Vec2 _scale);
    Vec2 GetScale() const;
    
    Vec2 TransformPoint(Vec2 _point) const;
    Vec2 TransformVector(Vec2 _vector) const;

    static Mat3 CreateTranslation(float _transX, float _transY);
    static Mat3 CreateTranslation(Vec2 _trans);

    static Mat3 CreateXRotation(float _rot);
    static Mat3 CreateYRotation(float _rot);
    static Mat3 CreateZRotation(float _rot);

    static Mat3 CreateScale(float _scaleX, float _scaleY);
    static Mat3 CreateScale(Vec2 _scale);
    
};

extern Mat3 operator *(Mat3 _lhs, Mat3 _rhs);