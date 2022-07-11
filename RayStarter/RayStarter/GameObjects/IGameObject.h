#pragma once

#include <raylib.h>
#include <raymath.h>

#include <cmath>

class ICollider;

class IGameObject
{
public:
	virtual void Start() {}
	virtual void Update(float _dt) {}
	virtual void Draw() {}
	virtual void OnDestroy() {}
	virtual void OnReconfigure() {}

	virtual void PhysicsUpdate(float _dt);
	virtual void OnCollision(IGameObject* _other) {}

	virtual void DrawGizmos();

	Vector2 position;
	Vector2 size;
	Color color;
	float rotation;

	Vector2 GetForward();
	Vector2 GetRight();

	Texture2D GetTexture() const;
	ICollider* GetCollider() const;

	virtual ~IGameObject();

protected:
	IGameObject() :
		position(Vector2()), size(Vector2()), color(RAYWHITE), 
		m_texture(), m_collider(nullptr), rotation(0)
	{
	}

	void SetCollider(ICollider* _collider);

	Texture2D m_texture;

private:
	ICollider* m_collider;

};

