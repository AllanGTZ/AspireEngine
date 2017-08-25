#pragma once

#include "DisplayEventObserver.h"

class DisplayManager {
private:
	// Memebers
	// --------
	static std::vector<DisplayEventObserver*> p_observerVector;
	
	struct ClearColor {
		float r;
		float g;
		float b;
		float a;
	};

	static ClearColor clearColor;

	// GLFW callback functions
	// --------------
	static void framebuffer_size_callback(GLFWwindow* window, int width, int height);

public:
	// Members
	// -------
	static GLFWwindow* activeWindow;

	// Functions
	// ---------
	DisplayManager();
	~DisplayManager();

	bool Initialize();
	void Clean();
	bool MakeWindow();
	bool WindowShouldClose();
	void Render();
	void ChangeClearColor(float r, float g, float b);
	void ChangeClearColor(float r, float g, float b, float a);
	void ChangeClearAlpha(float a);
	GLFWwindow* GetCurrentWindow();

	// Observer pattern
	void RegisterObserver(DisplayEventObserver& o);
	void UnregisterObserver(DisplayEventObserver& o);
	void NotifyObservers();
};

static DisplayManager Display;