#pragma once

class Application;

class IGameState
{
public:
	IGameState(Application* _app) { app = _app; }
	virtual ~IGameState() = default;
	
	virtual void Start() = 0;
	virtual void Update(float _dt) = 0;
	virtual void Draw() = 0;
	virtual void OnDestroy() = 0;

	Application* app;

};