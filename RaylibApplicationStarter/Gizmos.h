#pragma once

#include "Ray2D.h"

class Gizmos
{
public:
	static void DrawRay(Ray2D _ray, Color _color);
	static void DrawWireBox(Vector2 _position, Vector2 _size, Color _color);
	static void DrawWireCircle(Vector2 _position, float _radius, Color _color);
};