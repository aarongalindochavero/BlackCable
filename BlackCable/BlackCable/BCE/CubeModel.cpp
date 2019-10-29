#include "CubeModel.h"
#include <glm.hpp>
#include <gtc\matrix_transform.hpp>
#include <gtc\type_ptr.hpp>


void calcAverageNormals(unsigned int* indices, unsigned int indiceCount, GLfloat* vertices, unsigned int verticeCount,
	unsigned int vLength, unsigned int normalOffset)
{
	for (size_t i = 0; i < indiceCount; i += 3)
	{
		unsigned int in0 = indices[i] * vLength;
		unsigned int in1 = indices[i + 1] * vLength;
		unsigned int in2 = indices[i + 2] * vLength;
		glm::vec3 v1(vertices[in1] - vertices[in0], vertices[in1 + 1] - vertices[in0 + 1], vertices[in1 + 2] - vertices[in0 + 2]);
		glm::vec3 v2(vertices[in2] - vertices[in0], vertices[in2 + 1] - vertices[in0 + 1], vertices[in2 + 2] - vertices[in0 + 2]);
		glm::vec3 normal = glm::cross(v1, v2);
		normal = glm::normalize(normal);

		in0 += normalOffset; in1 += normalOffset; in2 += normalOffset;
		vertices[in0] += normal.x; vertices[in0 + 1] += normal.y; vertices[in0 + 2] += normal.z;
		vertices[in1] += normal.x; vertices[in1 + 1] += normal.y; vertices[in1 + 2] += normal.z;
		vertices[in2] += normal.x; vertices[in2 + 1] += normal.y; vertices[in2 + 2] += normal.z;
	}

	for (size_t i = 0; i < verticeCount / vLength; i++)
	{
		unsigned int nOffset = i * vLength + normalOffset;
		glm::vec3 vec(vertices[nOffset], vertices[nOffset + 1], vertices[nOffset + 2]);
		vec = glm::normalize(vec);
		vertices[nOffset] = vec.x; vertices[nOffset + 1] = vec.y; vertices[nOffset + 2] = vec.z;
	}
}

CubeModel::CubeModel()
{
}


CubeModel::~CubeModel()
{
}

void CubeModel::Init()
{
	LoadMesh();
	LoadShaders();
	texture = new Texture("Assets/Textures/brick.png");
	texture->LoadTexture();
}

void CubeModel::Draw(glm::mat4 *projection, Camera *camera)
{
	GLuint uniformProjection = 0, uniformModel = 0, uniformView = 0;
	shaderList[0].UseShader();
	uniformModel = shaderList[0].GetModelLocation();
	uniformProjection = shaderList[0].GetProjectionLocation();
	uniformView = shaderList[0].GetViewLocation();
	glm::mat4 model(1);
	//model = glm::translate(model, glm::vec3(0.0f, 0.0f, -2.5f));
	//model = glm::scale(model, glm::vec3(0.4f, 0.4f, 1.0f));
	model = glm::rotate(model, angle, glm::vec3(1.0f, 1.0f, 0.0f));
	angle += 0.01f;
	glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
	glUniformMatrix4fv(uniformProjection, 1, GL_FALSE, glm::value_ptr(*projection));
	glUniformMatrix4fv(uniformView, 1, GL_FALSE, glm::value_ptr(camera->calculateViewMatrix()));
	texture->UseTexture();
	meshList[0]->RenderMesh();
	glUseProgram(0);
}

void CubeModel::LoadMesh()
{
	unsigned int indices[] = {
		// front
		0,1,2,
		2,3,0,
		0,4,3,
		4,7,3,
		3,7,6,
		6,3,2

	};

	GLfloat vertices[] = {
		// front
		-1.0, -1.0,  1.0, 0.0f, 0.0f,		0.4f, 0.0f, 0.8f,//0
		1.0, -1.0,  1.0,1.0f, 0.0f,		0.0f, 0.0f, 0.0f,//1
		1.0,  1.0,  1.0,0.0f, 1.0f,		0.0f, 0.0f, 0.0f,//2
		-1.0,  1.0,  1.0,1.0f, 0.0f,		0.0f, 0.0f, 0.0f,//3
		// back
		-1.0, -1.0, -1.0,1.0f, 1.0f,		0.0f, 0.0f, 0.0f,//4
		1.0, -1.0, -1.0,1.0f, 0.0f,		0.0f, 0.0f, 0.0f,//5
		1.0,  1.0, -1.0,1.0f, 1.0f,		0.0f, 0.0f, 0.0f,//6
		-1.0,  1.0, -1.0,0.0f, 1.0f,		0.7f, -0.7f, 0.0f,//7
	};
	calcAverageNormals(indices, 18, vertices, 64, 8, 5);

	Mesh *obj1 = new Mesh();
	obj1->CreateMesh(vertices, indices, 64, 18);
	meshList.push_back(obj1);
}

void CubeModel::LoadShaders()
{
	Shader *shader1 = new Shader();
	shader1->CreateFromFiles(vShader, fShader);
	shaderList.push_back(*shader1);
}