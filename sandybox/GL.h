#pragma once
#define GLM_ENABLE_EXPERIMENTAL

#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp> 
#include <glm/gtc/type_ptr.hpp>
#include <glm/gtx/rotate_vector.hpp>
#include <glm/gtc/constants.hpp>
#include <iostream>
#include <sstream>

//ALL GL FUNCTIONS
namespace GL {
	void Init(int width, int height, const char* title);
	void SetViewPortandPreDraw();
	void UpdateScreen();
	void GetOpenGLVersionInfo();
	void ShowFPS();
	void ProcessInput();
	void Cleanup();

	GLFWwindow* GetWindowPtr();

	bool WindowIsOpen();
	
	int GetWindowWidth();
	int GetWindowHeight();

	//void Init(int width, int height);
	//void ProcessInput();
	//void SwapBuffersPollEvents();
	//void Cleanup();
	//bool WindowIsOpen();
	//int GetWindowWidth();
	//int GetWindowHeight();
	//int GetCursorX();
	//int GetCursorY();
	//void DisableCursor();
	//void HideCursor();
	//void ShowCursor();
	//GLFWwindow* GetWindowPtr();
	//int GetCursorScreenX();
	//int GetCursorScreenY();
	//bool WindowHasFocus();
	//bool WindowHasNotBeenForceClosed();
	//void ForceCloseWindow();

	//enum WindowMode { WINDOWED, FULLSCREEN };
	//void CreateWindow(WindowMode windowMode);
	//void SetWindowMode(WindowMode windowMode);
	//void ToggleFullscreen();
	//int GetScrollWheelYOffset();
	//void ResetScrollWheelYOffset();
}