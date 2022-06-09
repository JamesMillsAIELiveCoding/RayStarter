#pragma once

#include "IGameObject.h"

class ICollider
{
public:
	virtual void OnCollision(ICollider* _other) 
	{
		_other->GetOwner()->OnCollision(m_owner);
	}

	virtual bool IsColliding(ICollider* _other) = 0;
	virtual void DrawGizmos() {}
	virtual void Update(float _dt) = 0;

	IGameObject* GetOwner() const { return m_owner; }

protected:
	ICollider(IGameObject* _owner) : m_owner(_owner) {}
	IGameObject* m_owner;

};

