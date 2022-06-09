#include "Application.h"

#include <raylib.h>

#include "GameStateManager.h"

#include "Assets.h"
#include "Config.h"
#include "Gizmos.h"

Application::Application()
{
	m_gameStateManager = new GameStateManager();
	windowWidth = config.GetIntValue(PROGRAM_CATEGORY, "width");
	windowHeight = config.GetIntValue(PROGRAM_CATEGORY, "height");
}

void Application::Run()
{
	InitWindow(windowWidth, windowHeight, config.GetTextValue(PROGRAM_CATEGORY, "name"));

	Assets::Load();
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
	Assets::Unload();

	CloseWindow();
}

void Application::Start()
{

}

void Application::Update(float _dt)
{
	if (IsKeyPressed(KEY_GRAVE))
		Gizmos::drawGizmos = !Gizmos::drawGizmos;

	m_gameStateManager->Update(_dt);
}

void Application::Draw()
{
	m_gameStateManager->Draw();
}

void Application::OnDestroy()
{
	// Runs after the update loop has been exited
}
