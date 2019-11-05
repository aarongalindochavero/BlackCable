#include "Light.h"

Light::Light()
{
	materialAmbient = glm::vec3(1, 0.5, 0);
	lightAmbient = glm::vec3(0.2, 0.2, 0.2);

}

void Light::UseLight(GLfloat myMaterialAmbient, GLfloat myLightAmbient)
{
	glUniform3f(myMaterialAmbient, materialAmbient.x, materialAmbient.y, materialAmbient.z);
	glUniform3f(myLightAmbient, lightAmbient.x, lightAmbient.y, lightAmbient.z);
}

Light::~Light()
{
}
