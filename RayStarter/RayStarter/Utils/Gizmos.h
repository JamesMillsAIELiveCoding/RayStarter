#pragma once

#include "Physics/Ray2D.h"
#include "Maths/Colour.h"
#include "Maths/Vec2.h"

class Gizmos
{
public:
	static void DrawRay(Ray2D _ray, Colour _color);
	static void DrawWireBox(Vec2 _position, Vec2 _size, Colour _color);
	static void DrawOrientedWireBox(Vec2 _position, Vec2 _size, Vec2 _forward, Vec2 _right, Colour _color);
	static void DrawWireCircle(Vec2 _position, float _radius, Colour _color);

	static bool drawGizmos;
};