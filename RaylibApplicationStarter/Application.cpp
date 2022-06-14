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
}

void Application::Run()
{
	Start();

	while (!WindowShouldClose())
	{
		Update(GetFrameTime());

		BeginDrawing();
		ClearBackground(BLACK);
		Draw();
		EndDrawing();
	}

	OnDestroy();
}

void Application::Start()
{
	config = new Config("config.cfg");

	windowWidth = config->GetIntValue(PROGRAM_CATEGORY, "width");
	windowHeight = config->GetIntValue(PROGRAM_CATEGORY, "height");
	InitWindow(windowWidth, windowHeight, config->GetTextValue(PROGRAM_CATEGORY, "name"));

	if (config->GetBooleanValue(PROGRAM_CATEGORY, "audioEnabled"))
		InitAudioDevice();

	gameObjectManager = new GameObjectManager();
	stateManager = new GameStateManager();
	physics = new PhysicsManager();
	assets = new Assets();
}

void Application::Update(float _dt)
{
	if (IsKeyPressed(KEY_GRAVE))
		Gizmos::drawGizmos = !Gizmos::drawGizmos;

	gameObjectManager->Update(_dt);
	stateManager->Update(_dt);
	physics->Update(_dt);
}

void Application::Draw()
{
	gameObjectManager->Draw();
	stateManager->Draw();
}

void Application::OnDestroy()
{
	CloseWindow();

	if (config->GetBooleanValue(PROGRAM_CATEGORY, "audioEnabled"))
		CloseAudioDevice();

	delete config;
	delete gameObjectManager;
	delete stateManager;
	delete physics;
	delete assets;
}
