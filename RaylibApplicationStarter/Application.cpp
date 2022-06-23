#include "Application.h"

#include <raylib.h>

#include "GameStateManager.h"
#include "GameObjectManager.h"
#include "PhysicsManager.h"

#include "Assets.h"
#include "Config.h"
#include "Gizmos.h"

Application::Application()
{
	windowWidth = 0;
	windowHeight = 0;
	m_debugKey = 0;
}

void Application::Run()
{
	Start();

	Color clearColor = Config::GetColorValue(PROGRAM_CATEGORY, "clearColor");

	while (!WindowShouldClose())
	{
		Update(GetFrameTime());

		BeginDrawing();
		ClearBackground(clearColor);
		Draw();
		EndDrawing();
	}

	OnDestroy();
}

void Application::Start()
{
	Config::CreateInstance("config.cfg");

	windowWidth = Config::GetIntValue(PROGRAM_CATEGORY, "width");
	windowHeight = Config::GetIntValue(PROGRAM_CATEGORY, "height");
	InitWindow(windowWidth, windowHeight, Config::GetTextValue(PROGRAM_CATEGORY, "name"));

	if (Config::GetBooleanValue(PROGRAM_CATEGORY, "audioEnabled"))
		InitAudioDevice();

	SetExitKey(Config::GetIntValue(PROGRAM_CATEGORY, "quitKey"));
	m_debugKey = Config::GetIntValue(DEBUG_CATEGORY, "showGizmosKey");

	GameObjectManager::CreateInstance();
	GameStateManager::CreateInstance();
	PhysicsManager::CreateInstance();
	Assets::CreateInstance();
}

void Application::Update(float _dt)
{
	if (IsKeyPressed(m_debugKey))
		Gizmos::drawGizmos = !Gizmos::drawGizmos;

	GameObjectManager::Update(_dt);
	GameStateManager::Update(_dt);
	PhysicsManager::Update(_dt);
}

void Application::Draw()
{
	GameObjectManager::Draw();
	GameStateManager::Draw();
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
