#include "Transform.h"

void Transform::SetTranslation(float x, float y, float z)
{
	_translation.x = x;
	_translation.y = y;
	_translation.z = z;
}

void Transform::SetRotationVector(float angle, float x, float y, float z)
{
	_rotation.x = x;
	_rotation.y = y;
	_rotation.z = z;
	_angle = angle;
}

void Transform::SetScale(float x, float y, float z)
{
	_scale.x = x;
	_scale.y = y;
	_scale.z = z;
}

glm::mat4 Transform::GetTransform()
{
	glm::mat4 _model(1);
	_model = glm::translate(_model, _translation);
	_model = glm::scale(_model, _scale);
	_model = glm::rotate(_model, _angle, _rotation);
	return _model;
}