#pragma once

#include <GL\glew.h>
#include <glm.hpp>

class Light
{
public:
	Light();

	void UseLight(GLfloat myMaterialAmbient, GLfloat myLightAmbient);
	
	~Light();

private:
	glm::vec3 materialAmbient;
	glm::vec3 lightAmbient;
	
};

