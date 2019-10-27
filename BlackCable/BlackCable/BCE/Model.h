#pragma once
#include "Mesh.h"
#include "Shader.h"
#include "Mesh.h"
#include "Camera.h"
#include<vector>

class Model
{
public:
	virtual void Init() = 0;
	virtual void Draw(glm::mat4 *projection, Camera *camera) = 0;
protected:
	virtual void LoadShaders() = 0;
	virtual void LoadMesh() = 0;
	std::vector<Mesh*> meshList;
	std::vector<Shader> shaderList;
};

