#pragma once

class Application
{
public:
	Application();

	void Run();

	int windowWidth;
	int windowHeight;

private:
	void Start();
	void Update(float _dt);
	void Draw();
	void OnDestroy();

};