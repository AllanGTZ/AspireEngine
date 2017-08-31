#include "stdafx.h"
#include "TimeManager.h"

TimeManager* TimeManager::instance;

TimeManager::TimeManager()
{
	startTime = 0.0;
	gameTime = 0.0;
	FPS = 30;
	frameCount = 0;

	timePerFrame = 1.0 / FPS;
	previousFrameTime = 0.0;
	frameTime = 0.0;

	bTerminateThread = false;
}

TimeManager::~TimeManager()
{
	
}

TimeManager* TimeManager::GetInstance() {
	if (instance == nullptr) {
		instance = new TimeManager();
	}

	return instance;
}

void TimeManager::StartGameTime() {
	startTime = glfwGetTime();
}

void TimeManager::Update() {
	gameTime = glfwGetTime() - startTime;
	frameTime = gameTime - previousFrameTime;
}

void TimeManager::RestartGameTime() {

}

void TimeManager::Terminate() {
	bTerminateThread = true;
}

void TimeManager::SetFramerate(int Framerate) {
	FPS = Framerate;
	timePerFrame = 1.0 / FPS;
}

bool TimeManager::FrameHasPassed() {
	if (frameTime >= timePerFrame) {
		previousFrameTime = gameTime;
		frameCount = (int)(round(1.0 / frameTime));
		std::cout << "FPS: " << frameCount << std::endl;
		return true;
	}

	else return false;
}