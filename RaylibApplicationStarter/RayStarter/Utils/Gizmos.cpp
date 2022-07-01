#include "Gizmos.h"

#include <raylib.h>
#include <raymath.h>

bool Gizmos::drawGizmos = false;

Vector2 MultiplyVectorByFloat(Vector2 _vector, float _value)
{
	Vector2 newVector = _vector;
	newVector.x *= _value;
	newVector.y *= _value;

	return newVector;
}

void Gizmos::DrawRay(Ray2D _ray, Color _color)
{
	DrawLineEx(_ray.position, Vector2Add(_ray.position, MultiplyVectorByFloat(_ray.direction, _ray.length)), 2.0f, _color);
}

void Gizmos::DrawWireBox(Vector2 _position, Vector2 _size, Color _color)
{
	Vector2 halfSize = _size;
	halfSize.x *= .5f;
	halfSize.y *= .5f;

	DrawLine((int)_position.x - (int)halfSize.x, (int)_position.y - (int)halfSize.y, (int)_position.x - (int)halfSize.x, (int)_position.y + (int)halfSize.y, _color);
	DrawLine((int)_position.x - (int)halfSize.x, (int)_position.y - (int)halfSize.y, (int)_position.x + (int)halfSize.x, (int)_position.y - (int)halfSize.y, _color);
	DrawLine((int)_position.x - (int)halfSize.x, (int)_position.y + (int)halfSize.y, (int)_position.x + (int)halfSize.x, (int)_position.y + (int)halfSize.y, _color);
	DrawLine((int)_position.x + (int)halfSize.x, (int)_position.y - (int)halfSize.y, (int)_position.x + (int)halfSize.x, (int)_position.y + (int)halfSize.y, _color);
}

void Gizmos::DrawOrientedWireBox(Vector2 _position, Vector2 _size, Vector2 _forward, Vector2 _right, Color _color)
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

void Gizmos::DrawWireCircle(Vector2 _position, float _radius, Color _color)
{
	DrawCircleLines((int)_position.x, (int)_position.y, _radius, _color);
}
