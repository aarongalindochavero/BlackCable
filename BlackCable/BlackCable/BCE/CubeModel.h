#pragma once
#include "Mesh.h"
#include "Shader.h"
#include "Mesh.h"
#include "Camera.h"
#include<vector>
#include"Model.h"
#include"Texture.h"
class CubeModel : Model
{
public:
	CubeModel();
	~CubeModel();
	void Init() override;
	void Draw(glm::mat4 *projection, Camera *camera) override;
private:
	void LoadShaders() override;
	void LoadMesh() override;
	const char* vShader = "Assets/Shaders/Menu/shader.vert";
	const char* fShader = "Assets/Shaders/Menu/shader.frag";
	float angle{ 0 };
	Texture *texture;
};

