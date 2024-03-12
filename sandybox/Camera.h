#pragma once
#define GLM_ENABLE_EXPERIMENTAL

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtx/rotate_vector.hpp>
#include <glm/gtc/constants.hpp>
#include "GL.h"
#include "Input.h"

using namespace Input;

class Camera {
public:
	Camera();
	void Update(float deltaTime);

	glm::vec3 GetPosition() const;
	glm::mat4 GetViewMatrix() const;

	void MoveForward(float speed);
	void MoveBackward(float speed);
	void MoveLeft(float speed);
	void MoveRight(float speed);
	void MoveUp(float speed);
	void MoveDown(float speed);

	void MouseLook(double x, double y);

private:
	glm::vec3 Position;
	glm::vec3 ViewDirection;
	glm::vec3 Up;

	glm::vec2 OldMousePosition;
};