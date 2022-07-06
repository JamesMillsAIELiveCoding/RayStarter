#pragma once

#include "ICollider.h"

#include <list>

using std::list;

class PhysicsManager
{
public:
	static void AddCollider(ICollider* _collider);
	static void RemoveCollider(ICollider* _collider);
	static void Update(float _dt);
	static void CreateInstance() { m_instance = new PhysicsManager(); }
	static void DestroyInstance() { delete m_instance; }

private:
	PhysicsManager() {}
	PhysicsManager(const PhysicsManager&) = delete;
	~PhysicsManager() {}

	list<ICollider*> m_colliders;
	static PhysicsManager* m_instance;

};