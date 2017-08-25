#include "stdafx.h"
#include "GameHandler.h"


GameHandler::GameHandler()
{
	
}


GameHandler::~GameHandler()
{

}

bool GameHandler::Initialize() {
	// Initialize Window and Input managers
	// -------------
	if (!Display.Initialize()) {
		std::cout << "Failed to initialize display" << std::endl;
		return false;
	}

	Display.RegisterObserver(Input);
	Display.MakeWindow();

	if (!Input.Initialize()) {
		std::cout << "Failed to initialize input" << std::endl;
		return false;
	}

	return true;
}

void GameHandler::Run() {
	while (!Display.WindowShouldClose()) {
		Input.Update();
		Display.Render();
	}
}

void GameHandler::Terminate() {
	glfwTerminate();
}