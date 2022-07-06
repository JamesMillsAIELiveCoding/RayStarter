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

	static void Update(float _dt);
	static void Draw();

	static void SetState(const char* _name, IGameState* state);
	static void PushState(const char* _name);
	static void PopState();
	static void CreateInstance() { m_instance = new GameStateManager(); }
	static void DestroyInstance() { delete m_instance; }

protected:
	GameStateManager();
	GameStateManager(const GameStateManager&) = delete;
	~GameStateManager();

	map<const char*, IGameState*> m_states;
	vector<IGameState*> m_stack;
	list<function<void()>> m_commands;
	static GameStateManager* m_instance;

};