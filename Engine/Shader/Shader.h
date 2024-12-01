#pragma once

#include <glad/glad.h>
#include <glm/glm.hpp>
#include <glm/gtc/type_ptr.hpp>

#include <iostream>
#include <memory>

struct ShaderSourceGroup
{
	std::string vertexShaderName, fragmentShaderName, geometryShaderName;
};

class Shader
{
public:
	Shader(ShaderSourceGroup shaderNameGroup);
	GLuint ID;

	void use();
	void setColor(const glm::vec3 color);

private:
	std::string getShaderPath(const std::string& shaderName);
	std::string readShader(const char* filePath);
	GLuint compileShader(std::string shaderName, GLenum shaderType);
	void errorReport(GLuint shader, GLenum type);

	GLint getLocation(const GLchar* uniform);
	void setUniform3fv(const glm::vec3& value, const GLchar* uniform);
};