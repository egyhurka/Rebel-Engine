#include "Mesh.h"

Mesh::Mesh(const std::vector<float> vertices, const std::vector<unsigned int> indices, std::shared_ptr<Shader> shader, const glm::vec3& color)
    : vertices(vertices), indices(indices), shader(shader), color(color)
{
    if (!shader)
        throw std::runtime_error("Shader pointer is null.");

    glGenVertexArrays(1, &VAO);
    if (VAO == 0)
        throw std::runtime_error("VAO generation failed.");

    glGenBuffers(1, &VBO);
    if (VBO == 0)
        throw std::runtime_error("VBO generation failed.");

    glGenBuffers(1, &EBO);
    if (EBO == 0)
        throw std::runtime_error("EBO generation failed.");

    glBindVertexArray(VAO);

    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBufferData(GL_ARRAY_BUFFER, vertices.size() * sizeof(float), vertices.data(), GL_STATIC_DRAW);

    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, indices.size() * sizeof(unsigned int), indices.data(), GL_STATIC_DRAW);

    // Position attribute
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
    glEnableVertexAttribArray(0);

    glBindBuffer(GL_ARRAY_BUFFER, 0);
    glBindVertexArray(0);

    shader->use();

    //shader->setColor(color);
}

Mesh::~Mesh()
{
    glDeleteVertexArrays(1, &VAO);
    glDeleteBuffers(1, &VBO);
    glDeleteBuffers(1, &EBO);
}

void Mesh::draw()
{
    glBindVertexArray(VAO);
    glDrawElements(GL_TRIANGLES, static_cast<GLsizei>(indices.size()), GL_UNSIGNED_INT, 0);
    glBindVertexArray(0);
}