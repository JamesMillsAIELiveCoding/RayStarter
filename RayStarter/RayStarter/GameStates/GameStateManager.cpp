#include "GameStateManager.h"

#include "IGameState.h"

GameStateManager* GameStateManager::m_instance = nullptr;

GameStateManager::GameStateManager()
{

}

GameStateManager::~GameStateManager()
{
	for (auto& state : m_states)
	{
		delete state.second;
	}

	m_states.clear();
	m_stack.clear();
}

void GameStateManager::Update(float _dt)
{
	for (auto& cmd : m_instance->m_commands)
	{
		cmd();
	}
	m_instance->m_commands.clear();

	for (auto& state : m_instance->m_stack)
	{
		state->Update(_dt);
	}
}

void GameStateManager::Draw()
{
	for (auto& state : m_instance->m_stack)
	{
		state->Draw();
	}
}

void GameStateManager::SetState(const char* _name, IGameState* state)
{
	m_instance->m_commands.push_back([=]()
		{
			m_instance->m_states[_name] = state;
		});
}

void GameStateManager::PushState(const char* _name)
{
	m_instance->m_commands.push_back([=]()
		{
			m_instance->m_states[_name]->Start();
			m_instance->m_stack.push_back(m_instance->m_states[_name]);
		});
}

void GameStateManager::PopState()
{
	m_instance->m_commands.push_back([=]()
		{
			m_instance->m_stack[m_instance->m_stack.size() - 1]->OnDestroy();
			m_instance->m_stack.pop_back();
		});
}