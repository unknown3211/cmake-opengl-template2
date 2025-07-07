#include "Application/application.h"
#include "Engine/engine.h"

Window window;

static void OnStart()
{
	window.CreateWindow(1200, 720, "Open GL Application Template Starter", false, false);
	window.SetBackgroundColor(0.2f, 0.3f, 0.3f, 1.0f);
}

static void OnUpdate()
{

}

static void OnShutdown()
{

}

void Application::Init()
{
	window.Start(OnStart);
	window.Update(OnUpdate);
	window.Shutdown(OnShutdown);
}