#pragma once

#include <GL/glew.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp> 
#include <glm/gtc/type_ptr.hpp>
#include <string>
#include <fstream>
#include <sstream>
#include <iostream>

class Shader {
public:
	GLuint Program;

	Shader();
	Shader(const GLchar* vertexPath, const GLchar* fragmentPath);

	void SetShader(const GLchar* vertexPath, const GLchar* fragmentPath);
	void Use();

	void setInt(const std::string& name, float value) const;
	void setFloat(const std::string& name, float value) const;
	void setVec3(const std::string& name, float x, float y, float z) const;
	void setVec3(const std::string& name, const glm::vec3& value) const;
	void setVec4(const std::string& name, float x, float y, float z, float w) const;
	void setMat4(const std::string& name, const glm::mat4& mat) const;

};