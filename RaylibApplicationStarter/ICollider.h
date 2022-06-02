#pragma once

class IGameObject;

class ICollider
{
public:
	virtual void OnCollision(ICollider* _other) {}
	virtual bool IsColliding(ICollider* _other) = 0;

	IGameObject* GetOwner() const { return m_owner; }

protected:
	ICollider(IGameObject* _owner) : m_owner(_owner) {}
	IGameObject* m_owner;

};

