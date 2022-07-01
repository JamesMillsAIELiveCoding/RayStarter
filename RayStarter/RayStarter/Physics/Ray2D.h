#pragma once

#include <raymath.h>

struct Ray2D
{
	Vector2 position;
	Vector2 direction;
	float length;

	Ray2D(Vector2 _position, Vector2 _direction, float _length) :
		position(_position), direction(_direction), length(_length) {}
};

