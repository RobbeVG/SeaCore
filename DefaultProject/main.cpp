#include "SeaCore_pch.h"

#if _DEBUG
// ReSharper disable once CppUnusedIncludeDirective
#include <vld.h>
#endif

#include "SeaCore.h"
//#include "DefaultProject.h"
#include "SDL.h"

// #undef main;

int main(int, char* []) {
#ifdef  _DEBUG
	AllocConsole();
	FILE* fp = nullptr;
	freopen_s(&fp, "CONIN$", "r", stdin);
	freopen_s(&fp, "CONOUT$", "w", stdout);
	freopen_s(&fp, "CONOUT$", "w", stderr);
#endif

	sea_core::SeaCore engine;
	//sea_core::DefaultProject* project = new sea_core::DefaultProject();
	//engine.SetProject(project);
	engine.Run();

#ifdef  _DEBUG
	FreeConsole();
#endif

	return 0;
}