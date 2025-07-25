#include "Application/application.h"
#include "Engine/window.h"
#include "Engine/shapes.h"
#include "Engine/gui.h"

Window window;
GUI gui;

static void OnStart()
{
	window.CreateWindow(1200, 720, "Open GL Application Template Starter", false, false);
	window.SetBackgroundColor(0.2f, 0.3f, 0.3f, 1.0f);
	gui.Init(window.GetGLFWwindow());

	LoadTriangle();
}

static void OnUpdate()
{
	gui.Update(window.GetGLFWwindow());
	UpdateTriangle();
}

static void OnShutdown()
{
	gui.Shutdown();
	ShutdownTriangle();
}

void Application::Init()
{
	window.Start(OnStart);
	window.Update(OnUpdate);
	window.Shutdown(OnShutdown);
}