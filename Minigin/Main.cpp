#include "MiniginPCH.h"

#if _DEBUG
// ReSharper disable once CppUnusedIncludeDirective
#include <vld.h>
#endif

#include "SDL.h"
#include "Base/Minigin.h"

int main(int, char*[]) {
	sea_core::Minigin engine;
	engine.Run();
    return 0;
}