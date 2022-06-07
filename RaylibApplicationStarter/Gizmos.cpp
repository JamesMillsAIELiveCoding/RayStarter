#include "Gizmos.h"

#include <raymath.h>

Vector2 MultiplyVectorByFloat(Vector2 _vector, float _value)
{
	Vector2 newVector = _vector;
	newVector.x *= _value;
	newVector.y *= _value;

	return newVector;
}

void Gizmos::DrawRay(Ray& _ray, Color _color)
{
	DrawLineEx(_ray.position, Vector2Add(_ray.position, MultiplyVectorByFloat(_ray.direction, _ray.length)), 2.0f, _color);
}

void Gizmos::DrawWireBox(Vector2 _position, Vector2 _size, Color _color)
{
	Vector2 halfSize = _size;
	halfSize.x *= .5f;
	halfSize.y *= .5f;

	DrawLine(_position.x - halfSize.x, _position.y - halfSize.y, _position.x - halfSize.x, _position.y + halfSize.y, _color);
	DrawLine(_position.x - halfSize.x, _position.y - halfSize.y, _position.x + halfSize.x, _position.y - halfSize.y, _color);
	DrawLine(_position.x - halfSize.x, _position.y + halfSize.y, _position.x + halfSize.x, _position.y + halfSize.y, _color);
	DrawLine(_position.x + halfSize.x, _position.y - halfSize.y, _position.x + halfSize.x, _position.y + halfSize.y, _color);
}

void Gizmos::DrawWireCircle(Vector2 _position, float _radius, Color _color)
{
	DrawCircleLines(_position.x, _position.y, _radius, _color);
}
