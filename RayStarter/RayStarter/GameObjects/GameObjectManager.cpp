#include "GameObjectManager.h"

#include "../Utils/Gizmos.h"

#include <algorithm>

GameObjectManager* GameObjectManager::m_instance = nullptr;

void GameObjectManager::SpawnObject(IGameObject* _newObject)
{
	_newObject->Start();
	m_instance->m_objects.push_back(_newObject);
}

void GameObjectManager::DestroyObject(IGameObject* _toDestroy)
{
	_toDestroy->OnDestroy();
	m_instance->m_objects.remove(_toDestroy);
	delete _toDestroy;
}

void GameObjectManager::ReconfigureObjects()
{
	for (auto iter = m_instance->m_objects.begin(); iter != m_instance->m_objects.end(); ++iter)
		(*iter)->OnReconfigure();
}

void GameObjectManager::Update(float _dt)
{
	for (auto iter = m_instance->m_objects.begin(); iter != m_instance->m_objects.end(); ++iter)
		(*iter)->Update(_dt);
}

void GameObjectManager::UpdatePhysics(float _dt)
{
	for (auto iter = m_instance->m_objects.begin(); iter != m_instance->m_objects.end(); ++iter)
		(*iter)->PhysicsUpdate(_dt);
}

void GameObjectManager::Draw()
{
	for (auto iter = m_instance->m_objects.begin(); iter != m_instance->m_objects.end(); ++iter)
	{
		IGameObject* obj = *iter;
		obj->Draw();
		if(Gizmos::drawGizmos)
			obj->DrawGizmos();
	}
}

void GameObjectManager::Clear()
{
	while (!m_instance->m_objects.empty())
		DestroyObject(*m_instance->m_objects.begin());

	m_instance->m_objects.clear();
}
