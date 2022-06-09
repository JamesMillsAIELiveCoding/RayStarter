#pragma once

#include <list>
#include "IGameObject.h"

using std::list;

class GameObjectManager
{
public:
	static void SpawnObject(IGameObject* _newObject);
	static void DestroyObject(IGameObject* _toDestroy);
	static void Update(float _dt);
	static void Draw();
	static void Clear();

private:
	static list<IGameObject*> m_objects;
};

