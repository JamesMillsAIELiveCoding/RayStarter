#pragma once

#include "ICollider.h"

#include <list>

using std::list;

class PhysicsManager
{
public:
	void AddCollider(ICollider* _collider);
	void RemoveCollider(ICollider* _collider);
	void Update(float _dt);

private:
	list<ICollider*> m_colliders;

};

extern PhysicsManager* physics;