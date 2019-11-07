#pragma once
#include <glm.hpp>
#include <gtc\matrix_transform.hpp>
#include <gtc\type_ptr.hpp>

class Transform
{
public:
	void SetTranslation(float x, float y, float z);
	void SetRotationVector(float angle, float x, float y, float z);
	void SetScale(float x, float y, float z);
	glm::mat4 GetTransform();
private:
	glm::vec3 _translation;
	glm::vec3 _rotation;
	glm::vec3 _scale;
	float _angle;
};