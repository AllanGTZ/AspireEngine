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

	time = TimeManager::GetInstance();

	FPS = 60;
	frameTime = 1.0 / 60.0;
	previousTime = 0.0;

	return true;
}

void GameHandler::Run() {
	time->StartGameTime();

 	while (!Display.WindowShouldClose()) {
		time->Update();

		if (time->FrameHasPassed()) {
			Input.Update();

			Display.Render();
		}
	}
	 
	time->Terminate();
}

void GameHandler::Terminate() {
	glfwTerminate();
}