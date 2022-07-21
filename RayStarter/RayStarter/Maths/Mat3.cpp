#include "Mat3.h"

Mat3::Mat3()
{
    m11 = 1;
    m21 = 0;
    m31 = 0;
    m12 = 0;
    m22 = 1;
    m32 = 0;
    m13 = 0;
    m23 = 0;
    m33 = 1;
}

Mat3::Mat3(
    const float _m11, const float _m12, const float _m13,
    const float _m21, const float _m22, const float _m23,
    const float _m31, const float _m32, const float _m33)
{
    m11 = _m11;
    m21 = _m21;
    m31 = _m31;
    m12 = _m12;
    m22 = _m22;
    m32 = _m32;
    m13 = _m13;
    m23 = _m23;
    m33 = _m33;
}

void Mat3::SetTranslation(const float _transX, const float _transY)
{
    m13 = _transX;
    m23 = _transY;
}

void Mat3::SetTranslation(const Vec2 _trans)
{
    SetTranslation(_trans.x, _trans.y);
}

void Mat3::Translate(const float _transX, const float _transY)
{
    m13 += _transX;
    m23 += _transY;
}

void Mat3::Translate(const Vec2 _trans)
{
    Translate(_trans.x, _trans.y);
}

Vec2 Mat3::GetTranslation()
{
    return {m13, m23};
}

void Mat3::SetRotationX(const float _rot)
{
    const float yLen = sqrtf(m12 * m12 + m22 * m22 + m32 * m32);
    const float zLen = sqrtf(m13 * m13 + m23 * m23 + m33 * m33);

    const float cos = cosf(_rot);
    const float sin = sinf(_rot);

    m22 = cos * yLen; m23 = -sin * zLen;
    m32 = sin * yLen; m33 = cos * zLen;
}

void Mat3::SetRotationY(const float _rot)
{
    const float zLen = sqrtf(m13 * m13 + m23 * m23 + m33 * m33);
    const float xLen = sqrtf(m11 * m11 + m21 * m21 + m31 * m31);

    const float cos = cosf(_rot);
    const float sin = sinf(_rot);

    m11 = cos * zLen; m13 = -sin * xLen;
    m31 = sin * zLen; m33 = cos * xLen;
}

void Mat3::SetRotationZ(const float _rot)
{
    const float xLen = sqrtf(m11 * m11 + m21 * m21 + m31 * m31);
    const float yLen = sqrtf(m12 * m12 + m22 * m22 + m32 * m32);

    const float cos = cosf(_rot);
    const float sin = sinf(_rot);

    m11 = cos * yLen; m12 = -sin * xLen;
    m21 = sin * yLen; m22 = cos * xLen;
}

float Mat3::GetRotationX() const
{
    return atan2f(m21, m11);
}

float Mat3::GetRotationY() const
{
    return atan2f(-m12, m22);
}

float Mat3::GetRotationZ() const
{
    return atan2f(m13, m33);
}

void Mat3::SetScale(const float _scaleX, float _scaleY)
{
    const float xALen = sqrtf(m11 * m11 + m21 * m21 + m31 * m31);
    const float yALen = sqrtf(m12 * m12 + m22 * m22 + m32 * m32);

    if (xALen > 0)
    {
        m11 = (m11 / xALen) * _scaleX;
        m21 = (m21 / xALen) * _scaleX;
        m31 = (m31 / xALen) * _scaleX;
    }

    if (yALen > 0)
    {
        m12 = (m12 / yALen) * _scaleY;
        m22 = (m22 / yALen) * _scaleY;
        m32 = (m32 / yALen) * _scaleY;
    }
}

void Mat3::SetScale(const Vec2 _scale)
{
    SetScale(_scale.x, _scale.y);
}

Vec2 Mat3::GetScale() const
{
    const float xALen = sqrtf(m11 * m11 + m21 * m21 + m31 * m31);
    const float yALen = sqrtf(m12 * m12 + m22 * m22 + m32 * m32);
    return {xALen, yALen};
}

Vec2 Mat3::TransformPoint(const Vec2 _point) const
{
    return {
        _point.x * m11 + _point.y * m12 + m13,
        _point.x * m21 + _point.y * m22 + m23
    };
}

Vec2 Mat3::TransformVector(const Vec2 _vector) const
{
    return {
        _vector.x * m11 + _vector.y * m12,
        _vector.x * m21 + _vector.y * m22
    };
}

Mat3 Mat3::operator*(const Mat3 _lhs, const Mat3 _rhs) const
{
    return {
        _lhs.m11 * _rhs.m11 + _lhs.m21 * _rhs.m12 + _lhs.m31 * _rhs.m13,
        _lhs.m12 * _rhs.m11 + _lhs.m22 * _rhs.m12 + _lhs.m23 * _rhs.m13,
        _lhs.m13 * _rhs.m11 + _lhs.m23 * _rhs.m12 + _lhs.m33 * _rhs.m13,
                                                           
        _lhs.m11 * _rhs.m21 + _lhs.m21 * _rhs.m22 + _lhs.m31 * _rhs.m23,
        _lhs.m12 * _rhs.m21 + _lhs.m22 * _rhs.m22 + _lhs.m23 * _rhs.m23,
        _lhs.m13 * _rhs.m21 + _lhs.m23 * _rhs.m22 + _lhs.m33 * _rhs.m23,
         
        _lhs.m11 * _rhs.m31 + _lhs.m21 * _rhs.m32 + _lhs.m31 * _rhs.m33,
        _lhs.m12 * _rhs.m31 + _lhs.m22 * _rhs.m32 + _lhs.m23 * _rhs.m33,
        _lhs.m13 * _rhs.m31 + _lhs.m23 * _rhs.m32 + _lhs.m33 * _rhs.m33
    };
}

Mat3 Mat3::CreateTranslation(float _transX, float _transY)
{
    return {
        1, 0, _transX,
        0, 1, _transY,
        0, 0, 1
    };
}

Mat3 Mat3::CreateTranslation(const Vec2 _trans)
{
    return CreateTranslation(_trans.x, _trans.y);
}

Mat3 Mat3::CreateXRotation(const float _rot)
{
    float cos = cosf(_rot);
    float sin = sinf(_rot);

    return {
        1, 0,   0,
        0, cos, -sin,
        0, sin, cos
    };
}

Mat3 Mat3::CreateYRotation(const float _rot)
{
    float cos = cosf(_rot);
    float sin = sinf(_rot);

    return {
        cos,  0, sin,
        0,    1,   0,
        -sin, 0, cos
    };
}

Mat3 Mat3::CreateZRotation(const float _rot)
{
    float cos = cosf(_rot);
    float sin = sinf(_rot);

    return {
        cos, -sin, 0,
        sin, cos,  0,
        0,   0,    1
    };
}

Mat3 Mat3::CreateScale(float _scaleX, float _scaleY)
{
    return {
        _scaleX, 0, 0,
        0, _scaleY, 0,
        0, 0,       1,
    };
}

Mat3 Mat3::CreateScale(const Vec2 _scale)
{
    return CreateScale(_scale.x, _scale.y);
}
