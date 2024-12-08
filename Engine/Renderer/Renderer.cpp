#include "Renderer.h"

void Renderer::addToRenderList(Mesh* mesh)
{
	if (mesh)
	{
		renderList.emplace_back(mesh, mesh->getShader());
		sortRenderList();
	}
}

void Renderer::render()
{
	//std::shared_ptr<Shader> currentShader = nullptr;
	for (const auto& pair : renderList)
	{
		Mesh* mesh = pair.first;
		const auto& shader = pair.second;

		/*if (shader != currentShader)
		{
			currentShader = shader;
			shader->use();
		}*/

		shader->use();
		mesh->draw();
	}
}

void Renderer::sortRenderList()
{
	std::sort(renderList.begin(), renderList.end(), [](const auto& a, const auto& b) 
	{
		return a.second->ID < b.second->ID;
	});
}