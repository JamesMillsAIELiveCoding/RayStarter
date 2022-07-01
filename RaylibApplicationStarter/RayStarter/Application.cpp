#include "Application.h"

#include <raylib.h>

#include "GameStates/GameStateManager.h"
#include "GameObjects/GameObjectManager.h"
#include "Physics/PhysicsManager.h"

#include "Utils/Assets.h"
#include "Utils/Config.h"
#include "Utils/Gizmos.h"

Application::Application()
{
	windowWidth = 0;
	windowHeight = 0;
	allowResize = false;
	useFullscreen = false;
	m_debugKey = 0;
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

	OnDestroy();
}

void Application::Start()
{
	Config::CreateInstance("config.cfg");
	Configure();

	if (allowResize && !useFullscreen)
		SetConfigFlags(FLAG_WINDOW_RESIZABLE);

	InitWindow(windowWidth, windowHeight, Config::GetTextValue(PROGRAM_CATEGORY, "name"));
	SetExitKey(Config::GetIntValue(PROGRAM_CATEGORY, "quitKey"));

	if (useFullscreen)
	{
		windowWidth = GetMonitorWidth(0);
		windowHeight = GetMonitorHeight(0);
		SetWindowSize(windowWidth, windowHeight);
	}

	if (useFullscreen)
		ToggleFullscreen();

	if (Config::GetBooleanValue(PROGRAM_CATEGORY, "audioEnabled"))
		InitAudioDevice();

	GameStateManager::CreateInstance();
	GameObjectManager::CreateInstance();
	PhysicsManager::CreateInstance();
	Assets::CreateInstance();
}

void Application::Update(float _dt)
{
	if (IsWindowResized())
	{
		windowWidth = GetScreenWidth();
		windowHeight = GetScreenHeight();
	}

	if (IsKeyPressed(m_debugKey))
		Gizmos::drawGizmos = !Gizmos::drawGizmos;

	if (IsKeyPressed(m_configReloadKey))
	{
		Config::Reload();
		m_clearColor = Config::GetColorValue(PROGRAM_CATEGORY, "clearColor");
	}

	GameStateManager::Update(_dt);
	GameObjectManager::Update(_dt);
	PhysicsManager::Update(_dt);
}

void Application::Draw()
{
	GameStateManager::Draw();
	GameObjectManager::Draw();
}

void Application::OnDestroy()
{
	CloseWindow();

	if (Config::GetBooleanValue(PROGRAM_CATEGORY, "audioEnabled"))
		CloseAudioDevice();

	Config::DestroyInstance();
	GameObjectManager::DestroyInstance();
	GameStateManager::DestroyInstance();
	PhysicsManager::DestroyInstance();
	Assets::DestroyInstance();
}

void Application::Configure()
{
	windowWidth = Config::GetIntValue(WINDOW_CATEGORY, "width");
	windowHeight = Config::GetIntValue(WINDOW_CATEGORY, "height");
	allowResize = Config::GetBooleanValue(WINDOW_CATEGORY, "allowResize");
	useFullscreen = Config::GetBooleanValue(WINDOW_CATEGORY, "useFullscreen");
	m_clearColor = Config::GetColorValue(PROGRAM_CATEGORY, "clearColor");
	m_debugKey = Config::GetIntValue(DEBUG_CATEGORY, "showGizmosKey");
	m_configReloadKey = Config::GetIntValue(DEBUG_CATEGORY, "reloadConfigKey");
}
