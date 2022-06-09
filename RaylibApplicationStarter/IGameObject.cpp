#include "IGameObject.h"

#include "Gizmos.h"
#include "Config.h"
#include "ICollider.h"

void IGameObject::DrawGizmos()
{
	if (IsKeyPressed(KEY_GRAVE))
		m_drawGizmos = !m_drawGizmos;

	if (m_drawGizmos)
	{
		Ray2D ray = Ray2D(position, GetForward(), 25.0f);
		Gizmos::DrawRay(ray, BLUE);
		ray.direction = GetRight();
		Gizmos::DrawRay(ray, RED);

		if (m_collider != nullptr)
			m_collider->DrawGizmos();
	}
}

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

Texture2D IGameObject::GetTexture() const
{
	return m_texture;
}

ICollider* IGameObject::GetCollider() const
{
	return m_collider;
}
