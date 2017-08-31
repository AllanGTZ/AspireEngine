#pragma once
class TimeManager
{
private:
	static TimeManager* instance;

	// FPS management
	int FPS;
	int frameCount;
	double timePerFrame;
	double startTime;
	double gameTime;
	double previousFrameTime;
	double frameTime;

	// Thread management
	bool bTerminateThread;
	
	TimeManager();
	~TimeManager();

public:
	static TimeManager* GetInstance();
	void StartGameTime();
	void Update();
	void RestartGameTime();
	void Terminate();

	// FPS management
	void SetFramerate(int Framerate);
	bool FrameHasPassed();
};

