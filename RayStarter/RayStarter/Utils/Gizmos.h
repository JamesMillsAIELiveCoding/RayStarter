#pragma once

#include "../Physics/Ray2D.h"

class Gizmos
{
public:
	static void DrawRay(Ray2D _ray, Color _color);
	static void DrawWireBox(Vector2 _position, Vector2 _size, Color _color);
	static void DrawOrientedWireBox(Vector2 _position, Vector2 _size, Vector2 _forward, Vector2 _right, Color _color);
	static void DrawWireCircle(Vector2 _position, float _radius, Color _color);

	static bool drawGizmos;
};