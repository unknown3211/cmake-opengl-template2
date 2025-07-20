#include "Application/application.h"
#include "Engine/window.h"

Window window;

static void DrawLegacyTriangle()
{
	glBegin(GL_POLYGON);
	glColor3f(1.0f, 0.0f, 0.0f); glVertex3f(0.0f, 1.0f, 0.0f);
	glColor3f(0.0f, 1.0f, 0.0f); glVertex3f(-1.0f, -1.0f, 0.0f);
	glColor3f(0.0f, 0.0f, 0.0f); glVertex3f(1.0f, -1.0f, 0.0f);
	glEnd();
}

static void OnStart()
{
	window.CreateWindow(1200, 720, "Open GL Application Template Starter", false, true); // currently using Legacy open gl code set true to false if want to use modern
	window.SetBackgroundColor(0.2f, 0.3f, 0.3f, 1.0f);
}

static void OnUpdate()
{
  DrawLegacyTriangle();
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