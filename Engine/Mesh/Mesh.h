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
	Mesh(const std::vector<float> vertices, const std::vector<unsigned int> indices, std::shared_ptr<Shader> shader, const glm::vec3& color);
	~Mesh();

	void draw();

	inline std::shared_ptr<Shader> getShader() const { return shader; };

	static const inline std::vector<float> TriangleVert = {
		-0.5f, -0.5f, 0.0f,
		 0.5f, -0.5f, 0.0f,
		 0.0f, 0.5f, 0.0f
	};

	static const inline std::vector<unsigned int> TriangleInd = {
		0, 1, 2
	};

private:
	std::vector<float> vertices;
	std::vector<unsigned int> indices;
	std::shared_ptr<Shader> shader;
	unsigned int VAO, VBO, EBO;
	glm::vec3 color;
};