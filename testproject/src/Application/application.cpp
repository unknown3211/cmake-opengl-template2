#include "Application/application.h"
#include "Engine/window.h"
#include "Engine/shapes.h"

Window window;

static void OnStart()
{
	window.CreateWindow(1200, 720, "Open GL Application Template Starter", false, false);
	window.SetBackgroundColor(0.2f, 0.3f, 0.3f, 1.0f);

	LoadTriangle();
}

static void OnUpdate()
{
	UpdateTriangle();
}

static void OnShutdown()
{
	ShutdownTriangle();
}

void Application::Init()
{
	window.Start(OnStart);
	window.Update(OnUpdate);
	window.Shutdown(OnShutdown);
}