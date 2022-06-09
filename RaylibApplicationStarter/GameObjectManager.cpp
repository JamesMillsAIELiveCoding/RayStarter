#include "GameObjectManager.h"

#include <algorithm>

list<IGameObject*> GameObjectManager::m_objects;

void GameObjectManager::SpawnObject(IGameObject* _newObject)
{
	_newObject->Start();
	m_objects.push_back(_newObject);
}

void GameObjectManager::DestroyObject(IGameObject* _toDestroy)
{
	_toDestroy->OnDestroy();
	m_objects.remove(_toDestroy);
}

void GameObjectManager::Update(float _dt)
{
	for (auto iter = m_objects.begin(); iter != m_objects.end(); iter++)
		(*iter)->Update(_dt);
}

void GameObjectManager::Draw()
{
	for (auto iter = m_objects.begin(); iter != m_objects.end(); iter++)
	{
		(*iter)->Draw();
		(*iter)->DrawGizmos();
	}
}

void GameObjectManager::Clear()
{
	while (!m_objects.empty())
	{
		DestroyObject(*m_objects.begin());
	}
}
