#include "PhysicsManager.h"
#include "GameObjectManager.h"

list<ICollider*> PhysicsManager::m_colliders;
PhysicsManager* PhysicsManager::m_instance = nullptr;

void PhysicsManager::AddCollider(ICollider* _collider)
{
	m_colliders.push_back(_collider);
}

void PhysicsManager::RemoveCollider(ICollider* _collider)
{
	m_colliders.remove(_collider);
}

void PhysicsManager::Update(float _dt)
{
	GameObjectManager::UpdatePhysics(_dt);

	for (auto iter = m_colliders.begin(); iter != m_colliders.end(); iter++)
	{
		ICollider* collider = *iter;

		for (auto otherIter = m_colliders.begin(); otherIter != m_colliders.end(); otherIter++)
		{
			ICollider* other = *otherIter;
			if (collider == other)
				continue;

			if (collider->IsColliding(other))
				collider->OnCollision(other);
		}
	}
}
