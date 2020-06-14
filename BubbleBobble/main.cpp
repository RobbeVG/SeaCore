#include <iostream>

#if _DEBUG
// ReSharper disable once CppUnusedIncludeDirective
#include <vld.h>
#endif

//#include "Base/SeaCore_pch.h"
#include "SeaCore.h"
//#include "BubbleBobble.h"

#include <windows.h>


#include "BubbleBobble.h"

#undef main
//using namespace sea_core;

int main(int, char*[]){
#if defined(DEBUG) | defined(_DEBUG)
	AllocConsole();
	FILE* fp = nullptr;
	freopen_s(&fp, "CONIN$", "r", stdin);
	freopen_s(&fp, "CONOUT$", "w", stdout);
	freopen_s(&fp, "CONOUT$", "w", stderr);
#endif


	// Enable run-time memory leak check for debug builds.
#if defined(DEBUG) | defined(_DEBUG)
	HeapSetInformation(NULL, HeapEnableTerminationOnCorruption, NULL, 0);
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
	//_CrtSetBreakAlloc(21509);
#endif
	
	sea_core::SeaCore engine;
	sea_core::BubbleBobble* project = new sea_core::BubbleBobble();
	engine.SetProject(project);
	engine.Run();


	
// --------------> We can not do this because vld still uses the console :O
//#ifdef  _DEBUG
//	FreeConsole();
//#endif

	return 0;
}
