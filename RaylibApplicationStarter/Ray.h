#pragma once

#include <raylib.h>

struct Ray
{
	Vector2 position;
	Vector2 direction;
	float length;

	Ray(Vector2 _position, Vector2 _direction, float _length) : 
		position(_position), direction(_direction), length(_length) {}
};

