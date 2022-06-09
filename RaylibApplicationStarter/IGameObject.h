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

	virtual ~IGameObject()
	{
		delete m_collider;
	}

protected:
	IGameObject(Vector2 _position, Vector2 _size, ICollider* _collider) :
		position(_position), size(_size), color(RAYWHITE),
		m_texture(), m_collider(_collider), rotation(0), m_drawGizmos(false)
	{
	}

	Texture2D m_texture;
	ICollider* m_collider;
	bool m_drawGizmos;

};

