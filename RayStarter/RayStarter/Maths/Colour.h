#pragma once

#include <raylib.h>
#include <functional>

using std::initializer_list;

typedef struct Colour
{	
	union
	{
		struct
		{
			unsigned char r;
			unsigned char g;
			unsigned char b;
			unsigned char a;
		};

		unsigned char asArray[4];
	};

	Colour();
	Colour(unsigned char _r, unsigned char _g, unsigned char _b, unsigned char _a);
	Colour(initializer_list<unsigned char> _values);

	operator Color() const;
	
	static Colour clear;
	static Colour white;
	static Colour black;
	static Colour red;
	static Colour green;
	static Colour blue;

	static Colour FromHex(const char* _hex);

} Colour;

extern bool operator ==(const Colour& _lhs, const Colour& _rhs);
extern bool operator !=(const Colour& _lhs, const Colour& _rhs);
	
extern bool operator >(const Colour& _lhs, const Colour& _rhs);
extern bool operator <(const Colour& _lhs, const Colour& _rhs);
extern bool operator >=(const Colour& _lhs, const Colour& _rhs);
extern bool operator <=(const Colour& _lhs, const Colour& _rhs);