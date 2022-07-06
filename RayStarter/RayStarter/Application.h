#pragma once

#include <raylib.h>

class Application
{
public:
	Application();

	void Run();

	int windowWidth;
	int windowHeight;
	bool isFullscreen;

private:
	void Start();
	void Update(float _dt);
	void Draw();
	void OnDestroy();

	void Configure();
	void SwapFullscreenMode();

	Color m_clearColor;
	int m_debugKey;
	int m_configReloadKey;
	int m_fullscreenKey;

};