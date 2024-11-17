#pragma once

#include <glad/glad.h>

#include <iostream>

class Shader
{
public:
	Shader(const char* vertexPath, const char* geometryPath, const char* fragmentPath);
	GLuint ID;

private:
	std::string loadShader(const char* filePath);
	GLuint compileShader(const char* path, GLenum shaderType);
	void errorReport(GLuint shader, GLenum type);
};