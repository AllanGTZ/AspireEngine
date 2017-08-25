#pragma once

#include "DisplayEventObserver.h"

#define GLFW_HOLD 3

struct KeyCode {
	int Space = GLFW_KEY_SPACE;
	int Apostrophe = GLFW_KEY_APOSTROPHE;
	int Comma = GLFW_KEY_COMMA;
	int Minus = GLFW_KEY_MINUS;
	int Period = GLFW_KEY_PERIOD;
	int Slash = GLFW_KEY_SLASH;
	int Alpha0 = GLFW_KEY_0;
	int Alpha1 = GLFW_KEY_1;
	int Alpha2 = GLFW_KEY_2;
	int Alpha3 = GLFW_KEY_3;
	int Alpha4 = GLFW_KEY_4;
	int Alpha5 = GLFW_KEY_5;
	int Alpha6 = GLFW_KEY_6;
	int Alpha7 = GLFW_KEY_7;
	int Alpha8 = GLFW_KEY_8;
	int Alpha9 = GLFW_KEY_9;
	int Semicolon = GLFW_KEY_SEMICOLON;
	int Equal = GLFW_KEY_EQUAL;
	int A = GLFW_KEY_A;
	int B = GLFW_KEY_B;
	int C = GLFW_KEY_C;
	int D = GLFW_KEY_D;
	int E = GLFW_KEY_E;
	int F = GLFW_KEY_F;
	int G = GLFW_KEY_G;
	int H = GLFW_KEY_H;
	int I = GLFW_KEY_I;
	int J = GLFW_KEY_J;
	int K = GLFW_KEY_K;
	int L = GLFW_KEY_L;
	int M = GLFW_KEY_M;
	int N = GLFW_KEY_N;
	int O = GLFW_KEY_O;
	int P = GLFW_KEY_P;
	int Q = GLFW_KEY_Q;
	int R = GLFW_KEY_R;
	int S = GLFW_KEY_S;
	int T = GLFW_KEY_T;
	int U = GLFW_KEY_U;
	int V = GLFW_KEY_V;
	int W = GLFW_KEY_W;
	int X = GLFW_KEY_X;
	int Y = GLFW_KEY_Y;
	int Z = GLFW_KEY_Z;
};

static KeyCode Key_code;

class InputManager : public DisplayEventObserver {
private:
	struct Key {
		int key;
		int previousState;
		int currentState;
	};

	static std::map<int, Key> keyStates;
	
	static void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods);
	static void mouse_button_callback();
	bool checkKeyStatus(int key, int status);

public:
	InputManager();
	~InputManager();
	
	bool Initialize();
	void Update();
	bool isKeyPressed(int key);
	bool isKeyHeld(int key);
	bool isKeyReleased(int key);
};

static InputManager Input;