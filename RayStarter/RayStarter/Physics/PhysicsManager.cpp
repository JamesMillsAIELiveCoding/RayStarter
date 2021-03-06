#include "PhysicsManager.h"
#include "../GameObjects/GameObjectManager.h"

PhysicsManager* PhysicsManager::m_instance = nullptr;

void PhysicsManager::AddCollider(ICollider* _collider)
{
	m_instance->m_colliders.push_back(_collider);
}

void PhysicsManager::RemoveCollider(ICollider* _collider)
{
	m_instance->m_colliders.remove(_collider);
}

void PhysicsManager::Update(float _dt)
{
	GameObjectManager::UpdatePhysics(_dt);

	for (auto iter = m_instance->m_colliders.begin(); iter != m_instance->m_colliders.end(); iter++)
	{
		ICollider* collider = *iter;

		for (auto otherIter = m_instance->m_colliders.begin(); otherIter != m_instance->m_colliders.end(); otherIter++)
		{
			ICollider* other = *otherIter;
			if (collider == other)
				continue;

			if (collider->IsColliding(other))
				collider->OnCollision(other);
		}
	}
}
