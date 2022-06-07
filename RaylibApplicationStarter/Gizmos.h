#pragma once

#include "Ray.h"

class Gizmos
{
public:
	static void DrawRay(Ray& _ray, Color _color);
	static void DrawWireBox(Vector2 _position, Vector2 _size, Color _color);
	static void DrawWireCircle(Vector2 _position, float _radius, Color _color);
};