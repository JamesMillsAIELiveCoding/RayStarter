#include "IGameObject.h"

#include "../Utils/Gizmos.h"
#include "../Utils/Config.h"
#include "../Physics/ICollider.h"
#include "../Physics/PhysicsManager.h"

void IGameObject::PhysicsUpdate(float _dt)
{
	if (m_collider != nullptr)
		m_collider->Update(_dt);
}

void IGameObject::DrawGizmos()
{
	if (Gizmos::drawGizmos)
	{
		Ray2D ray = Ray2D(Position(), GetForward(), 25.0f);
		Gizmos::DrawRay(ray, Colour::blue);
		ray.direction = GetRight();
		Gizmos::DrawRay(ray, Colour::red);

		if (m_collider != nullptr)
			m_collider->DrawGizmos();
	}
}

Vec2 IGameObject::GetForward()
{
	const float radians = Rotation() * PI / 180;
	return Vec2{ cos(radians), sin(radians) };
}

Vec2 IGameObject::GetRight()
{
	const Vec2 forward = GetForward();
	return Vec2::Rotate(forward, 90);
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
		PhysicsManager::RemoveCollider(m_collider);
		delete m_collider;
	}
}

void IGameObject::SetCollider(ICollider* _collider)
{
	if (m_collider != nullptr)
		return;

	m_collider = _collider;
	PhysicsManager::AddCollider(m_collider);
}
