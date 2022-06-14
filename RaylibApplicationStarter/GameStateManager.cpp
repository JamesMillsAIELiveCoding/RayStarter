#include "GameStateManager.h"

#include "IGameState.h"

GameStateManager* stateManager = nullptr;

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
	for (auto& cmd : m_commands)
	{
		cmd();
	}
	m_commands.clear();

	for (auto& state : m_stack)
	{
		state->Update(_dt);
	}
}

void GameStateManager::Draw()
{
	for (auto& state : m_stack)
	{
		state->Draw();
	}
}

void GameStateManager::SetState(const char* _name, IGameState* state)
{
	m_commands.push_back([=]()
		{
			m_states[_name] = state;
		});
}

void GameStateManager::PushState(const char* _name)
{
	m_commands.push_back([=]()
		{
			m_states[_name]->Start();
			m_stack.push_back(m_states[_name]);
		});
}

void GameStateManager::PopState()
{
	m_commands.push_back([=]()
		{
			m_stack[m_stack.size() - 1]->OnDestroy();
			m_stack.pop_back();
		});
}