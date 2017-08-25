#include "stdafx.h"
#include "InputManager.h"

// Static members and functions
// ----------------------------

std::map<int, InputManager::Key> InputManager::keyStates;

void InputManager::key_callback(GLFWwindow* window, int key, int scancode, int action, int mods) {
	std::map<int, Key>::iterator it = keyStates.find(key);

	if (it == keyStates.end()) {
		Key newKey;
		newKey.key = key;
		newKey.previousState = GLFW_RELEASE;
		newKey.currentState = action;
		keyStates.insert(std::make_pair(key, newKey));
	}

	else {
		if (action == GLFW_REPEAT) {
			action = GLFW_PRESS;
		}

		it->second.currentState = action;
	}
}

void InputManager::mouse_button_callback() {

}


// Functions
// ---------

bool InputManager::checkKeyStatus(int key, int status) {
	auto it = keyStates.find(key);

	if (it == keyStates.end()) {
		return false;
	}

	else {
		Key k = it->second;

		if (k.currentState == status) {
			return true;
		}

		else {
			return false;
		}
	}
}

InputManager::InputManager() {

}

InputManager::~InputManager() {

}

bool InputManager::Initialize() {
	glfwSetKeyCallback(activeWindow, key_callback);

	return true;
}

void InputManager::Update() {
	glfwPollEvents();

	auto it = keyStates.begin();

	while (it != keyStates.end()) {
		Key& key = it->second;

		if (key.currentState == GLFW_RELEASE && key.previousState == GLFW_RELEASE) {
			it = keyStates.erase(it);
		}

		else {
			if ((key.currentState == GLFW_PRESS || key.currentState == GLFW_HOLD) && (key.previousState == GLFW_PRESS || key.previousState == GLFW_HOLD)) {
				key.currentState = GLFW_HOLD;
			}

			key.previousState = key.currentState;
			++it;
		}
	}
}

bool InputManager::isKeyPressed(int key) {
	return checkKeyStatus(key, GLFW_PRESS);
}

bool InputManager::isKeyHeld(int key) {
	return checkKeyStatus(key, GLFW_HOLD);
}

bool InputManager::isKeyReleased(int key) {
	return checkKeyStatus(key, GLFW_RELEASE);
}