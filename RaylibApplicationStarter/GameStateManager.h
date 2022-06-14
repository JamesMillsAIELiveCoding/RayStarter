#pragma once

#include <map>
#include <list>
#include <vector>
#include <functional>

class IGameState;

using std::map;
using std::vector;
using std::list;
using std::function;

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
	map<const char*, IGameState*> m_states;
	vector<IGameState*> m_stack;
	list<function<void()>> m_commands;

};

extern GameStateManager* stateManager;