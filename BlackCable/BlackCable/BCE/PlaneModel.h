#pragma once
#include "Mesh.h"
#include "Shader.h"
#include "Mesh.h"
#include "Camera.h"
#include<vector>
#include"Model.h"
#include"Texture.h"
#include "Material.h"
#include "Light.h"

class PlaneModel : Model
{
public:
	PlaneModel();
	~PlaneModel();
	void Init() override;
	void Draw() override;
private:
	void LoadMesh() override;
	float angle{ 0 };
	Texture *texture;
	Texture *textureNormal;
	Material* material;
};

