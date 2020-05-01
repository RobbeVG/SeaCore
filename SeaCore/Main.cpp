#include "SeaCore_pch.h"

#if _DEBUG
// ReSharper disable once CppUnusedIncludeDirective
#include <vld.h>
#endif

#include "Base/SeaCore.h"
#include "Project/DefaultProject.h"
#include "SDL.h"

int main(int, char*[]) {
	sea_core::SeaCore engine;
	sea_core::DefaultProject* project = new sea_core::DefaultProject();
	engine.SetProject(project);
	engine.Run();
    return 0;
}