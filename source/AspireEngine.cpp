// AspireEngine.cpp : Defines the entry point for the application.
//

#include "stdafx.h"
#include "AspireEngine.h"
#include "GameHandler.h"

INT CALLBACK WinMain(_In_ HINSTANCE	hInstance, _In_ HINSTANCE hPrevInstance, _In_ LPSTR	lpCmdLine, _In_ int nCmdShow)
{
	// Console for output (delete after finished with debug)
	AllocConsole();
	FILE* new_stdout;
	freopen_s(&new_stdout, "CONOUT$", "w", stdout);

	// Game initialization
	// -------------------
	GameHandler gameHandler;

	if (!gameHandler.Initialize()) {
		std::cout << "Failed to initialize game" << std::endl;
		return 1;
	}
	

	// Main game loop
	// --------------
	gameHandler.Run();

	// glfw: terminate, clearing all previously allocated GLFW resources.
	// ------------------------------------------------------------------
	gameHandler.Terminate();

	return 0;
}