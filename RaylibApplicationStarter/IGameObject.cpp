#include "IGameObject.h"

#include "Gizmos.h"
#include "Config.h"
#include "ICollider.h"
#include "PhysicsManager.h"

void IGameObject::PhysicsUpdate(float _dt)
{
	if (m_collider != nullptr)
		m_collider->Update(_dt);
}

void IGameObject::DrawGizmos()
{
	if (Gizmos::drawGizmos)
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

IGameObject::~IGameObject()
{
	if (m_collider != nullptr)
	{
		physics->RemoveCollider(m_collider);
		delete m_collider;
	}
}

void IGameObject::SetCollider(ICollider* _collider)
{
	if (m_collider != nullptr)
		return;

	m_collider = _collider;
	physics->AddCollider(m_collider);
}
