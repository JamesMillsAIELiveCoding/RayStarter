#pragma once

#include <raylib.h>
#include <raymath.h>

#include <cmath>

#include "Maths/Vec2.h"
#include "Maths/Colour.h"
#include "Maths/SceneObject.h"

class ICollider;

class IGameObject : public SceneObject
{
public:
	virtual void OnReconfigure() {}

	virtual void PhysicsUpdate(float _dt);
	virtual void OnCollision(IGameObject* _other) {}

	virtual void DrawGizmos();

	Colour color;

	Vec2 GetForward();
	Vec2 GetRight();

	Texture2D GetTexture() const;
	ICollider* GetCollider() const;

	~IGameObject() override;

protected:
	IGameObject() :
		color(Colour::white),  m_texture(), m_collider(nullptr)
	{
	}
	void SetCollider(ICollider* _collider);

	Texture2D m_texture;

private:
	ICollider* m_collider;

};

