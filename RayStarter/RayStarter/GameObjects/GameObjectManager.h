#pragma once

#include <list>
#include "IGameObject.h"

using std::list;

class GameObjectManager
{
public:
	static void SpawnObject(IGameObject* _newObject);
	static void DestroyObject(IGameObject* _toDestroy);
	static void ReconfigureObjects();
	static void Update(float _dt);
	static void UpdatePhysics(float _dt);
	static void Draw();
	static void Clear();
	static void CreateInstance() { m_instance = new GameObjectManager(); }
	static void DestroyInstance() 
	{
		Clear();
		delete m_instance; 
	}

private:
	GameObjectManager() = default;
	GameObjectManager(const GameObjectManager&) = delete;
	list<IGameObject*> m_objects;
	static GameObjectManager* m_instance;

};