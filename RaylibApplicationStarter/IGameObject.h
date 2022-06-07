#pragma once

#include <raylib.h>
#include <raymath.h>

#include <cmath>

class ICollider;

class IGameObject
{
public:
	virtual void Start() {}
	virtual void Update(float _dt) = 0;
	virtual void Draw() = 0;
	virtual void DrawGizmos();
	virtual void OnDestroy() {}

	Vector2 position;
	Vector2 size;
	Color color;
	float rotation;

	Vector2 GetForward();
	Vector2 GetRight();

	Texture2D* GetTexture() const;
	ICollider* GetCollider() const;

protected:
	IGameObject(Vector2 _position, Vector2 _size, ICollider* _collider) :
		position(_position), size(_size), color(RAYWHITE), 
		m_texture(nullptr), m_collider(_collider), rotation(0), m_drawGizmos(false)
	{
	}

	virtual ~IGameObject()
	{
		if (m_texture != nullptr)
			delete m_texture;

		delete m_collider;
	}

	Texture2D* m_texture;
	ICollider* m_collider;
	bool m_drawGizmos;

};

