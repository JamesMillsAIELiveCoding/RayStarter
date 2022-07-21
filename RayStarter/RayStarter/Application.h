#pragma once
#include "Maths/Colour.h"

class Application
{
public:
	Application();
	virtual ~Application() = default;

	void Run();

	int windowWidth;
	int windowHeight;
	bool isFullscreen;

protected:
	virtual void OnStart() {}
	virtual void OnUpdate(float _dt) {}
	virtual void OnDraw() {}
	virtual void OnDestroy() {}

	virtual void OnConfigure() {}

private:
	void Start();
	void Update(float _dt);
	void Draw();
	void Destroy();

	void Configure(bool _isReconfigure = false);
	void SwapFullscreenMode();

	Colour m_clearColor;
	int m_debugKey;
	int m_configReloadKey;
	int m_fullscreenKey;

};
