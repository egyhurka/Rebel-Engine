#pragma once

#include "../Shader/Shader.h"
#include "../Mesh/Mesh.h"

#include <vector>
#include <utility>
#include <algorithm>
#include <memory>

class Renderer
{
public:
	Renderer() {};

	void addToRenderList(Mesh* mesh);
	void render();


private:
	std::vector<std::pair<Mesh*, std::shared_ptr<Shader>>> renderList;

	void sortRenderList();
};