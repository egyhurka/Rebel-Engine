#pragma once

#include <glad/glad.h>
#include <glm/glm.hpp>
#include <glm/gtc/type_ptr.hpp>

#include <iostream>

constexpr const char* SHADER_DEFAULT_VERTEX = "Engine/Shaders/VertexShader.glsl";
constexpr const char* SHADER_DEFAULT_FRAGMENT = "Engine/Shaders/FragmentShader.glsl";
constexpr const char* SHADER_DEFAULT_GEOMETRY = "Engine/Shaders/GeometryShader.glsl";

class Shader
{
public:
	Shader(const char* vertexPath, const char* geometryPath, const char* fragmentPath);
	GLuint ID;

	void use();
	void setColor(const glm::vec3 color);

private:
	std::string loadShader(const char* filePath);
	GLuint compileShader(const char* path, GLenum shaderType);
	void errorReport(GLuint shader, GLenum type);

	GLuint getLocation(const GLchar* uniform);
	void setUniform3fv(const glm::vec3& value, const GLchar* uniform);
};