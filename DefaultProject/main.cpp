#include <iostream>

#if defined(DEBUG) | defined(_DEBUG)
// ReSharper disable once CppUnusedIncludeDirective
#include <vld.h>
#endif

//#include "Base/SeaCore_pch.h"
#include "SeaCore.h"
#include "DefaultProject.h"

#include <windows.h>

int main(int, char*[]) {
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
	//_CrtSetBreakAlloc(363);
#endif

	
	sea_core::SeaCore engine;
	engine.SetProject(new sea_core::DefaultProject());
	engine.Run();
	
// --------------> We can not do this because vld still uses the console :O
//#ifdef  _DEBUG
//	FreeConsole();
//#endif

    return 0;
}