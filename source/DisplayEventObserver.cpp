#include "stdafx.h"
#include "DisplayEventObserver.h"

DisplayEventObserver::DisplayEventObserver() {

}

DisplayEventObserver::~DisplayEventObserver() {

}

void DisplayEventObserver::Notify(GLFWwindow* newActiveWindow) {
	activeWindow = newActiveWindow;
}

void DisplayEventObserver::Clean() {
	activeWindow = nullptr;
}