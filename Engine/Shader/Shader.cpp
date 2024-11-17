#include "Shader.h"

#include <fstream>
#include <sstream>
#include <string>

Shader::Shader(const char* vertexPath, const char* geometryPath, const char* fragmentPath)
{
    GLuint vertexShader = compileShader(vertexPath, GL_VERTEX_SHADER);
    GLuint geometryShader = compileShader(geometryPath, GL_GEOMETRY_SHADER);
    GLuint fragmentShader = compileShader(fragmentPath, GL_FRAGMENT_SHADER);

    ID = glCreateProgram();
    glAttachShader(ID, vertexShader);
    glAttachShader(ID, geometryShader);
    glAttachShader(ID, fragmentShader);
    glLinkProgram(ID);

    errorReport(ID, GL_LINK_STATUS);

    glDeleteShader(vertexShader);
    glDeleteShader(geometryShader);
    glDeleteShader(fragmentShader);
}

std::string Shader::loadShader(const char* filePath)
{
	std::ifstream file(filePath);
	std::stringstream buffer;
	buffer << file.rdbuf();
	return buffer.str();
}

GLuint Shader::compileShader(const char* path, GLenum shaderType)
{
    std::string shaderSource = loadShader(path);
    const char* source = shaderSource.c_str();

    GLuint shader = glCreateShader(shaderType);
    glShaderSource(shader, 1, &source, nullptr);
    glCompileShader(shader);

    errorReport(shader, GL_COMPILE_STATUS);

    return shader;
}

void Shader::errorReport(GLuint shader, GLenum type) {
    GLint success;
    std::string errorType;

    if (type == GL_COMPILE_STATUS) {
        glGetShaderiv(shader, GL_COMPILE_STATUS, &success);
    }
    else if (type == GL_LINK_STATUS) {
        glGetProgramiv(shader, GL_LINK_STATUS, &success);
    }

    if (!success) {
        char infoLog[512];
        if (type == GL_COMPILE_STATUS) {
            glGetShaderInfoLog(shader, 512, nullptr, infoLog);
            errorType = "Shader compilation failed: ";
        }
        else if (type == GL_LINK_STATUS) {
            glGetProgramInfoLog(shader, 512, nullptr, infoLog);
            errorType = "Program linking failed: ";
        }
        else {
            errorType = "Unknown failure: ";
        }
        std::cerr << errorType << infoLog << std::endl;
    }
}
