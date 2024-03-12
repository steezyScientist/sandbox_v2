#include "Input.h"
#include "GL.h"


static void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods);
static void mouse_callback(GLFWwindow* window, double xpos, double ypos);

bool keyDown[372];
bool keyPressed[372];
bool keyDownLast[372];

double mouseX;
double mouseY;

void Input::Init() {
	GLFWwindow* window = GL::GetWindowPtr();
}

void Input::Update() {

	GLFWwindow* window = GL::GetWindowPtr();
	glfwSetKeyCallback(window, key_callback);
	glfwSetCursorPosCallback(window, mouse_callback);

	for (int i = 32; i < 349; i++) {
		//down
				// down`
		if (glfwGetKey(window, i) == GLFW_PRESS)
			keyDown[i] = true;
		else
			// press
			if (keyDown[i] && !keyDownLast[i])
				keyDown[i] = true;
			else
				keyPressed[i] = false;
		keyDownLast[i] = keyDown[i];
	}
}

bool Input::isKeyDown(unsigned int key) {
	return keyDown[key];
}

bool Input::isKeyPressed(unsigned int key) {
	return keyPressed[key];
}

double Input::GetMouseX() {
	return mouseX;
}

double Input::GetMouseY() {
	return mouseY;
}


static void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods) {

	if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS){
		std::cout << "ESC KEY" << std::endl;
		glfwSetWindowShouldClose(window, GL_TRUE);
	}	
	
	keyDown[key] = glfwGetKey(window, key) == GLFW_PRESS;
	keyPressed[key] = glfwGetKey(window, key) == GLFW_PRESS;
		
}

static void mouse_callback(GLFWwindow* window, double xpos, double ypos) {
	std::cout << "x:" << xpos << " y:" << ypos << std::endl;
	mouseX = xpos;
	mouseY = ypos;
}