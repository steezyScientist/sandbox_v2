#pragma once
#include "Colors.h"
#include <glm/glm.hpp>

struct Light {
	Light(){

	}

	Light(glm::vec3 position, glm::vec3 color) {
		this->position = position;
		this->color = color;
	}

	glm::vec3 position = glm::vec3(0.0f);
	glm::vec3 color = glm::vec3(0.0f);
};