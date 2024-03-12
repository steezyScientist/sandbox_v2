#include "Camera.h"

Camera::Camera() {
	
	Position = glm::vec3(0.0f, 0.0f, 1.0f);
	ViewDirection = glm::vec3(0.0f, 0.0f, -1.0f);
	Up = glm::vec3(0.0f, 1.0f, 0.0f);
}

void Camera::Update(float deltaTime) {
	MouseLook(Input::GetMouseX(), Input::GetMouseY());

	if (Input::isKeyPressed(GLFW_KEY_W)) {
		MoveForward(deltaTime);
	}if (Input::isKeyPressed(GLFW_KEY_A)) {
		MoveLeft(deltaTime);
	}if (Input::isKeyPressed(GLFW_KEY_S)) {
		MoveBackward(deltaTime);
	}if (Input::isKeyPressed(GLFW_KEY_D)) {
		MoveRight(deltaTime);
	}if (Input::isKeyPressed(GLFW_KEY_Z)) {
		MoveUp(deltaTime);
	}if (Input::isKeyPressed(GLFW_KEY_X)) {
		MoveDown(deltaTime);
	}
}
glm::vec3 Camera::GetPosition() const{
	return Position;
}

glm::mat4 Camera::GetViewMatrix() const{
	return glm::lookAt(Position, Position + ViewDirection, Up);
}

void Camera::MoveForward(float speed) {
	Position += (speed * ViewDirection);
}
void Camera::MoveBackward(float speed) {
	Position -= (speed * ViewDirection);
}
void Camera::MoveRight(float speed) {
	glm::vec3 rightVector = glm::normalize(glm::cross(ViewDirection, Up));
	Position += (rightVector * speed);
}
void Camera::MoveLeft(float speed) {
	glm::vec3 rightVector = glm::normalize(glm::cross(ViewDirection, Up));
	Position -= (rightVector * speed);
}
void Camera::MoveUp(float speed) {
	Position.y += speed * 2.0f;
}
void Camera::MoveDown(float speed) {
	Position.y -= speed * 2.0f;
}

void Camera::MouseLook(double x, double y) {

	glm::vec2 currentMouse = glm::vec2(x, y);

	static bool firstLook = true;
	if (firstLook) {
		OldMousePosition = currentMouse;
		firstLook = false;
	}

	glm::vec2 mouseDelta = OldMousePosition - currentMouse;

	//horizontal rotation (YAW)
	ViewDirection = glm::rotate(ViewDirection, glm::radians(mouseDelta.x), Up);

	// Vertical rotation (PITCH) around the right vector
	glm::vec3 rightVector = glm::cross(Up, ViewDirection);
	ViewDirection = glm::rotate(ViewDirection, glm::radians(mouseDelta.y), -rightVector);

	OldMousePosition = currentMouse;
}