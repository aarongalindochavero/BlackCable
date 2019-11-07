#include "Material.h"
#include "ShaderManager.h"


Material::Material()
{
	specularIntensity = 0.0f;
	shininess = 0.0f;
}

Material::Material(GLfloat sIntensity, GLfloat shine)
{
	specularIntensity = sIntensity;
	shininess = shine;
}

void Material::UseMaterial()
{
	GLuint specularIntensityLocation = 0;//adidier get from shadermanager
	GLuint shininessLocation = 0;

	glUniform1f(specularIntensityLocation, specularIntensity);
	glUniform1f(shininessLocation, shininess);
}

Material::~Material()
{
}
