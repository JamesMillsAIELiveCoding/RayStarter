#pragma once

#include <list>
#include "IGameObject.h"

using std::list;

class GameObjectManager
{
public:
	void SpawnObject(IGameObject* _newObject);
	void DestroyObject(IGameObject* _toDestroy);
	void Update(float _dt);
	void UpdatePhysics(float _dt);
	void Draw();
	void Clear();

private:
	list<IGameObject*> m_objects;

};

extern GameObjectManager* gameObjectManager;