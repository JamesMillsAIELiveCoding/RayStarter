#include "Application.h"

#include "GameStates/GameStateManager.h"
#include "GameObjects/GameObjectManager.h"
#include "Physics/PhysicsManager.h"

#include "Utils/Assets.h"
#include "Utils/Config.h"
#include "Utils/Gizmos.h"

#include <raylib.h>

Application::Application()
{
	windowWidth = 0;
	windowHeight = 0;
	isFullscreen = false;
	m_debugKey = 0;
	m_fullscreenKey = 0;
	m_configReloadKey = 0;
	m_clearColor = {};
}

void Application::Run()
{
	Start();

	while (!WindowShouldClose())
	{
		Update(GetFrameTime());

		BeginDrawing();
		ClearBackground(m_clearColor);
		Draw();
		EndDrawing();
	}

	Destroy();
}

void Application::Start()
{
	Config::CreateInstance("config.cfg");
	Configure();

	InitWindow(windowWidth, windowHeight, Config::GetTextValue(PROGRAM_CATEGORY, "name"));
	SetExitKey(Config::GetIntValue(PROGRAM_CATEGORY, "quitKey"));

	if (isFullscreen)
		SwapFullscreenMode();

	if (Config::GetBooleanValue(PROGRAM_CATEGORY, "audioEnabled"))
		InitAudioDevice();

	GameStateManager::CreateInstance();
	GameObjectManager::CreateInstance();
	PhysicsManager::CreateInstance();
	Assets::CreateInstance();

	OnStart();
}

void Application::Update(float _dt)
{
	if (IsKeyPressed(m_debugKey))
		Gizmos::drawGizmos = !Gizmos::drawGizmos;

	if (IsKeyPressed(m_fullscreenKey))
		SwapFullscreenMode();

	if (IsKeyPressed(m_configReloadKey))
	{
		Config::Reload();
		m_clearColor = Config::GetColorValue(PROGRAM_CATEGORY, "clearColor");
	}

	GameStateManager::Update(_dt);
	GameObjectManager::Update(_dt);
	PhysicsManager::Update(_dt);

	OnUpdate(_dt);
}

void Application::Draw()
{
	GameStateManager::Draw();
	GameObjectManager::Draw();

	OnDraw();
}

void Application::Destroy()
{
	CloseWindow();

	if (Config::GetBooleanValue(PROGRAM_CATEGORY, "audioEnabled"))
		CloseAudioDevice();

	Config::DestroyInstance();
	GameObjectManager::DestroyInstance();
	GameStateManager::DestroyInstance();
	PhysicsManager::DestroyInstance();
	Assets::DestroyInstance();

	OnDestroy();
}

void Application::Configure()
{
	windowWidth = Config::GetIntValue(WINDOW_CATEGORY, "width");
	windowHeight = Config::GetIntValue(WINDOW_CATEGORY, "height");
	isFullscreen = Config::GetBooleanValue(WINDOW_CATEGORY, "useFullscreen");
	m_fullscreenKey = Config::GetIntValue(WINDOW_CATEGORY, "toggleFullscreenKey");
	m_clearColor = Config::GetColorValue(PROGRAM_CATEGORY, "clearColor");
	m_debugKey = Config::GetIntValue(DEBUG_CATEGORY, "showGizmosKey");
	m_configReloadKey = Config::GetIntValue(DEBUG_CATEGORY, "reloadConfigKey");

	OnConfigure();
}

void Application::SwapFullscreenMode()
{
	isFullscreen = !isFullscreen;

	if(!isFullscreen)
		ToggleFullscreen();

	windowWidth = isFullscreen ? GetMonitorWidth(0) : Config::GetIntValue(WINDOW_CATEGORY, "width");
	windowHeight = isFullscreen ? GetMonitorHeight(0) : Config::GetIntValue(WINDOW_CATEGORY, "height");
	SetWindowSize(windowWidth, windowHeight);

	if(isFullscreen)
		ToggleFullscreen();
}
