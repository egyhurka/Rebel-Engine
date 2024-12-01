#include "Shader.h"

#include <filesystem>
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

Shader::Shader(ShaderSourceGroup shaderNameGroup)
{
    GLuint vertexShader = compileShader(shaderNameGroup.vertexShaderName, GL_VERTEX_SHADER);
    GLuint fragmentShader = compileShader(shaderNameGroup.fragmentShaderName, GL_FRAGMENT_SHADER);
    GLuint geometryShader = (shaderNameGroup.geometryShaderName != "") ? compileShader(shaderNameGroup.geometryShaderName, GL_GEOMETRY_SHADER) : NULL;

    ID = glCreateProgram();
    glAttachShader(ID, vertexShader);
    glAttachShader(ID, fragmentShader);
    if (geometryShader)
        glAttachShader(ID, geometryShader);
    glLinkProgram(ID);

    errorReport(ID, GL_LINK_STATUS);

    glDeleteShader(vertexShader);
    glDeleteShader(fragmentShader);
    if (geometryShader)
        glDeleteShader(geometryShader);
}

void Shader::use()
{
    glUseProgram(ID);
}

void Shader::setColor(const glm::vec3 color)
{
    setUniform3fv(color, "uColor");
}

std::string Shader::getShaderPath(const std::string& shaderName)
{
    std::filesystem::path shaderPath = std::filesystem::current_path() / "Shaders" / shaderName;
    return shaderPath.string();
}

std::string Shader::readShader(const char* filePath)
{
    if (!std::filesystem::exists(filePath)) {
        std::cerr << "Shader not exists: " << filePath << std::endl;
    }
    std::ifstream file(filePath);
    std::stringstream buffer;
    buffer << file.rdbuf();
    std::string content = buffer.str();
    return content;
}

GLuint Shader::compileShader(std::string shaderName, GLenum shaderType)
{
    if (shaderType == GL_GEOMETRY_SHADER)
        return 0;
    std::string shaderSource = readShader(getShaderPath(shaderName).c_str());
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

GLint Shader::getLocation(const GLchar* uniform)
{
    GLint location = glGetUniformLocation(ID, uniform);
    if (location == -1) {
        std::cerr << "Uniform not found: " << uniform << std::endl;
        return -1;
    }
    return location;
}

void Shader::setUniform3fv(const glm::vec3& value, const GLchar* uniform)
{
    glUniform3fv(getLocation(uniform), 1, glm::value_ptr(value));
}