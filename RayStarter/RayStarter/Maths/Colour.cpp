#include "Colour.h"

#include <string>

using std::stoi;

Colour Colour::clear = { 0, 0, 0, 0 };
Colour Colour::white = { 255, 255, 255, 255 };
Colour Colour::black = { 0, 0, 0, 255 };
Colour Colour::red = { 255, 0, 0, 255 };
Colour Colour::green = { 0, 255, 0, 255 };
Colour Colour::blue = { 0, 0, 255, 0 };

Colour::Colour()
{
    r = 255;
    g = 255;
    b = 255;
    a = 255;
}

Colour::Colour(const unsigned char _r, const unsigned char _g, const unsigned char _b, const unsigned char _a)
{
    r = _r;
    g = _g;
    b = _b;
    a = _a;
}

Colour::Colour(initializer_list<unsigned char> _values)
{
    int iter = 0;
    for(const auto val : _values)
        asArray[iter++] = val;
}

Colour::operator Color() const
{
    return Color{r, g, b, a};
}

bool Colour::operator==(const Colour& _lhs, const Colour& _rhs) const
{
    return _lhs.r == _rhs.r && _lhs.g == _rhs.g && _lhs.b == _rhs.b && _lhs.a == _rhs.a;
}

bool Colour::operator!=(const Colour& _lhs, const Colour& _rhs) const
{
    return _lhs.r != _rhs.r || _lhs.g != _rhs.g || _lhs.b != _rhs.b || _lhs.a != _rhs.a;
}

bool Colour::operator>(const Colour& _lhs, const Colour& _rhs) const
{
    return _lhs.r + _lhs.g + _lhs.b + _lhs.a > _rhs.r + _rhs.g + _rhs.b + _rhs.a;
}

bool Colour::operator<(const Colour& _lhs, const Colour& _rhs) const
{
    return _lhs.r + _lhs.g + _lhs.b + _lhs.a < _rhs.r + _rhs.g + _rhs.b + _rhs.a;
}

bool Colour::operator>=(const Colour& _lhs, const Colour& _rhs) const
{
    return _lhs.r + _lhs.g + _lhs.b + _lhs.a >= _rhs.r + _rhs.g + _rhs.b + _rhs.a;
}

bool Colour::operator<=(const Colour& _lhs, const Colour& _rhs) const
{
    return _lhs.r + _lhs.g + _lhs.b + _lhs.a <= _rhs.r + _rhs.g + _rhs.b + _rhs.a;
}

Colour Colour::FromHex(const char* _hex)
{
    const int hexVal = stoi(_hex);

    Colour col;
    col.r = (hexVal >> 24) & 0xFF;
    col.b = (hexVal >> 16) & 0xFF;
    col.g = (hexVal >> 8) & 0xFF;
    col.a = (hexVal >> 0) & 0xFF;

    return col;
}
