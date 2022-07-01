#pragma once

#include <raymath.h>

class Application
{
public:
	Application();

	void Run();

	int windowWidth;
	int windowHeight;
	bool allowResize;
	bool useFullscreen;

private:
	void Start();
	void Update(float _dt);
	void Draw();
	void OnDestroy();

	void Configure();

	Color m_clearColor;
	int m_debugKey;
	int m_configReloadKey;

};