#pragma once

#include <glad/glad.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

#include "../Shader/Shader.h"

#include <vector>

class Mesh
{
public:
	Mesh(const std::vector<GLfloat> vertices, Shader* shader, const glm::vec3& color);
	~Mesh();

	void draw();

	static const inline std::vector<GLfloat> Triangle = {
		0.0f,  0.5f, 0.0f,
	   -0.5f, -0.5f, 0.0f,
		0.5f, -0.5f, 0.0f
	};

private:
	std::vector<GLfloat> vertices;
	Shader* shader;
	GLuint VAO, VBO, EBO;
	glm::vec3 color;
};