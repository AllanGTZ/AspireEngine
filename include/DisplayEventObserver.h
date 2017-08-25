#pragma once

class DisplayEventObserver {
private:

protected:
	GLFWwindow* activeWindow;

public:
	DisplayEventObserver();
	~DisplayEventObserver();

	void Notify(GLFWwindow* newActiveWindow);
	void Clean();

};