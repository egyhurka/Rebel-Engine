#include "Mesh.h"

Mesh::Mesh(const std::vector<GLfloat> vertices, std::shared_ptr<Shader> shader, const glm::vec3& color)
    : vertices(vertices) , shader(shader), color(color)
{
    if (!shader)
        throw std::runtime_error("Shader pointer is null.");

    glGenVertexArrays(1, &VAO);
    if (VAO == 0)
        throw std::runtime_error("VAO generation failed.");

    glGenBuffers(1, &VBO);
    if (VBO == 0)
        throw std::runtime_error("VBO generation failed.");

    glBindVertexArray(VAO);

    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBufferData(GL_ARRAY_BUFFER, vertices.size() * sizeof(GLfloat), vertices.data(), GL_STATIC_DRAW);

    // Position attribute
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(GLfloat), (void*)0);
    glEnableVertexAttribArray(0);

    shader->use();

    shader->setColor(color);
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
    glDrawArrays(GL_TRIANGLES, 0, static_cast<GLsizei>(vertices.size() / 3));
    glBindVertexArray(0);
}