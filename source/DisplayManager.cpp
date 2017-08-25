#include "stdafx.h"
#include "DisplayManager.h"

// Static data
// -----------
GLFWwindow* DisplayManager::activeWindow = nullptr;
std::vector<DisplayEventObserver*> DisplayManager::p_observerVector;
DisplayManager::ClearColor DisplayManager::clearColor;

DisplayManager::DisplayManager() {

}

DisplayManager::~DisplayManager() {

}

void DisplayManager::framebuffer_size_callback(GLFWwindow* window, int width, int height) {
	glViewport(0, 0, width, height);
}

bool DisplayManager::Initialize() {
	// glew: load all OpenGL function pointers
	// ---------------------------------------

	if (!glewInit()) {
		std::cout << "Failed to initialize GLEW" << std::endl;
		return false;
	}

	if (!glfwInit()) {
		std::cout << "Failed to initialize GLFW" << std::endl;
		return false;
	}

	// Configure GLFW
	// --------------
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
	//glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);

	// Configure clear color
	clearColor.r = 0.5f;
	clearColor.g = 0.5f;
	clearColor.b = 0.5f;
	clearColor.a = 1.0f;

	return true;
}

void DisplayManager::Clean() {

}

bool DisplayManager::MakeWindow() {
	// glfw window creation
	// --------------------
	activeWindow = glfwCreateWindow(800, 600, "Engine", NULL, NULL);

	if (activeWindow == nullptr) {
		std::cout << "Failed to create GLFW window" << std::endl;
		glfwTerminate();
		return false;
	}

	glfwMakeContextCurrent(activeWindow);
	glfwSetFramebufferSizeCallback(activeWindow, framebuffer_size_callback);
	
	for (auto it = p_observerVector.begin(); it != p_observerVector.end(); ++it) {
		(*it)->Notify(activeWindow);
	}

	return true;
}

bool DisplayManager::WindowShouldClose() {
	return glfwWindowShouldClose(activeWindow);
}

void DisplayManager::Render() {
	// render
	// ------
	glClearColor(clearColor.r, clearColor.g, clearColor.b, clearColor.a);
	glClear(GL_COLOR_BUFFER_BIT);

	// glfw: swap buffers and poll IO events (keys pressed/released, mouse moved etc.)
	// -------------------------------------------------------------------------------
	glfwSwapBuffers(activeWindow);
}

void DisplayManager::ChangeClearColor(float r, float g, float b) {
	clearColor.r = r;
	clearColor.g = g;
	clearColor.b = b;
	clearColor.a = 1.0f;
}

void DisplayManager::ChangeClearColor(float r, float g, float b, float a) {
	clearColor.r = r;
	clearColor.g = g;
	clearColor.b = b;
	clearColor.a = a;
}

void DisplayManager::ChangeClearAlpha(float a) {
	clearColor.a = a;
}

GLFWwindow* DisplayManager::GetCurrentWindow() {
	return activeWindow;
}

void DisplayManager::RegisterObserver(DisplayEventObserver& newObserver) {
	newObserver.Notify(activeWindow);
	p_observerVector.push_back(&newObserver);
}

void DisplayManager::UnregisterObserver(DisplayEventObserver& deletedObserver) {
	for (auto it = p_observerVector.begin(); it != p_observerVector.end(); ++it) {
		if ((*it) == &deletedObserver) {
			(*it)->Clean();
			p_observerVector.erase(it);
			return;
		}
	}
}

void DisplayManager::NotifyObservers() {
	for (auto it = p_observerVector.begin(); it != p_observerVector.end(); ++it) {
		(*it)->Notify(activeWindow);
	}
}