#pragma once

#include <map>
#include <list>
#include <vector>
#include <functional>

class IGameState;

class GameStateManager
{
public:
	GameStateManager();
	~GameStateManager();

	void Update(float _dt);
	void Draw();

	void SetState(const char* _name, IGameState* state);
	void PushState(const char* _name);
	void PopState();

protected:
	std::map<const char*, IGameState*> m_states;
	std::vector<IGameState*> m_stack;
	std::list<std::function<void()>> m_commands;

private:

};

