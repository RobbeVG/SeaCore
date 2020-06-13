#include <iostream>

#if _DEBUG
// ReSharper disable once CppUnusedIncludeDirective
#include <vld.h>
#endif

//#include "Base/SeaCore_pch.h"
#include "Base/SeaCore.h"
//#include "BubbleBobble.h"

#include <windows.h>


#include "BubbleBobble.h"

#undef main
//using namespace sea_core;

int main(int, char*[]){
	#ifdef  _DEBUG
	AllocConsole();
	FILE* fp = nullptr;
	freopen_s(&fp, "CONIN$", "r", stdin);
	freopen_s(&fp, "CONOUT$", "w", stdout);
	freopen_s(&fp, "CONOUT$", "w", stderr);
#endif

	sea_core::SeaCore engine;
	sea_core::BubbleBobble* project = new sea_core::BubbleBobble();
	engine.SetProject(project);
	engine.Run();

#ifdef  _DEBUG
	FreeConsole();
#endif

	return 0;
}
