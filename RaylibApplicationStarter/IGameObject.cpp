#include "IGameObject.h"

Vector2 IGameObject::GetForward()
{
	float radians = rotation * PI / 180;
	return Vector2{ cos(radians), sin(radians) };
}

Vector2 IGameObject::GetRight()
{
	Vector2 forward = GetForward();
	return Vector2Rotate(forward, 90);
}

Texture2D* IGameObject::GetTexture() const 
{ 
	return m_texture; 
}

ICollider* IGameObject::GetCollider() const
{
	return m_collider;
}
