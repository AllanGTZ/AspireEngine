#pragma once

#include "TimeManager.h"

class GameHandler
{
private:
	TimeManager* time;
	int FPS;
	int FrameCount;
	double frameTime;
	double gameTimer;
	double frameTimer;
	double previousTime;
	
public:
	GameHandler();
	~GameHandler();

	bool Initialize();
	void Run();
	void Terminate();
};

