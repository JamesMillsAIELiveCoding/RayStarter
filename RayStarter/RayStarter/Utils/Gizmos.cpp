#include "Gizmos.h"

#include <raylib.h>
#include <raymath.h>

bool Gizmos::drawGizmos = false;

void Gizmos::DrawRay(Ray2D _ray, Colour _color)
{
	DrawLineEx(_ray.position, Vector2Add(_ray.position, Vector2Scale(_ray.direction, _ray.length)), 2.0f, _color);
}

void Gizmos::DrawWireBox(Vec2 _position, Vec2 _size, Colour _color)
{
	Vector2 halfSize = _size;
	halfSize.x *= .5f;
	halfSize.y *= .5f;

	DrawLine((int)_position.x - (int)halfSize.x, (int)_position.y - (int)halfSize.y, (int)_position.x - (int)halfSize.x, (int)_position.y + (int)halfSize.y, _color);
	DrawLine((int)_position.x - (int)halfSize.x, (int)_position.y - (int)halfSize.y, (int)_position.x + (int)halfSize.x, (int)_position.y - (int)halfSize.y, _color);
	DrawLine((int)_position.x - (int)halfSize.x, (int)_position.y + (int)halfSize.y, (int)_position.x + (int)halfSize.x, (int)_position.y + (int)halfSize.y, _color);
	DrawLine((int)_position.x + (int)halfSize.x, (int)_position.y - (int)halfSize.y, (int)_position.x + (int)halfSize.x, (int)_position.y + (int)halfSize.y, _color);
}

void Gizmos::DrawOrientedWireBox(Vec2 _position, Vec2 _size, Vec2 _forward, Vec2 _right, Colour _color)
{
	Vector2 left = Vector2Scale(_forward, -(_size.x / 2));
	Vector2 right = Vector2Scale(_forward, _size.x / 2);
	Vector2 top = Vector2Scale(_right, -(_size.y / 2));
	Vector2 bottom = Vector2Scale(_right, _size.y / 2);

	DrawLineEx(Vector2Add(Vector2Add(left, top), _position), Vector2Add(Vector2Add(right, top), _position), 1.0f, _color);
	DrawLineEx(Vector2Add(Vector2Add(left, bottom), _position), Vector2Add(Vector2Add(right, bottom), _position), 1.0f, _color);
	DrawLineEx(Vector2Add(Vector2Add(left, top), _position), Vector2Add(Vector2Add(left, bottom), _position), 1.0f, _color);
	DrawLineEx(Vector2Add(Vector2Add(right, top), _position), Vector2Add(Vector2Add(right, bottom), _position), 1.0f, _color);
}

void Gizmos::DrawWireCircle(Vec2 _position, float _radius, Colour _color)
{
	DrawCircleLines((int)_position.x, (int)_position.y, _radius, _color);
}
