#include "ShaderManager.h"
#include "Platform.h"
#include <glm.hpp>
#include <gtc\matrix_transform.hpp>
#include <gtc\type_ptr.hpp>

namespace BCE
{
	namespace Base
	{
		ShaderManager* ShaderManager::ptr;

		ShaderManager::ShaderManager()
		{

		}

		void ShaderManager::LoadShaders()
		{
			Shader* shader1 = new Shader();
			shader1->CreateFromFiles(vShader, fShader);
			shaderList.push_back(*shader1);
		}

		ShaderManager* ShaderManager::getPtr()
		{
			if (ptr == nullptr)
			{
				ptr = new ShaderManager();
			}
			return ptr;
		}

		GLint ShaderManager::GetModelLocation()
		{
			return uniformModel;
		}

		GLint ShaderManager::GetSpecularIntensityLocation()
		{
			return uniformSpecularIntensity;
		}

		GLint ShaderManager::GetShininessLocation()
		{
			return uniformShininess;
		}
		void ShaderManager::draw()
		{
			glUniformMatrix4fv(uniformProjection, 1, GL_FALSE, glm::value_ptr(projection));
			glUniformMatrix4fv(uniformView, 1, GL_FALSE, glm::value_ptr(camera->calculateViewMatrix()));
			glUniform3f(uniformEyePosition, camera->getCameraPosition().x, camera->getCameraPosition().y, camera->getCameraPosition().z);



			mainLight = DirectionalLight(0.5f, 0.5f, 0.5f,
				0.01f, 0.01f,
				0.0f, 0.0f, -1.0f);

			unsigned int pointLightCount = 0;
			pointLights[0] = PointLight(1.0f, 1.0f, 1.0f,
				.2f, .2f,
				13.0f, 0.0f, 0.0f,
				0.3f, 0.2f, 0.1f);
			pointLightCount++;
			pointLights[1] = PointLight(1.0f, 1.0f, 1.0f,
				.7f, .7f,
				-1.0f, 0.0f, 0.0f,
				0.3f, 0.2f, 0.1f);
			pointLightCount++;

			shaderList[0].SetDirectionalLight(&mainLight);
			shaderList[0].SetPointLights(pointLights, pointLightCount);
		}
		void ShaderManager::initShader(Camera* camera)
		{
			this->camera = camera;
			projection = glm::perspective(45.0f, (float)Platform::GetPtr()->GetWidth() / Platform::GetPtr()->GetHeight(), 0.1f, 100.0f);
			LoadShaders();
			shaderList[0].UseShader();
			uniformModel = shaderList[0].GetModelLocation();
			uniformProjection = shaderList[0].GetProjectionLocation();
			uniformView = shaderList[0].GetViewLocation();

			uniformAmbientColour = shaderList[0].GetAmbientColourLocation();
			uniformAmbientIntensity = shaderList[0].GetAmbientIntensityLocation();
			uniformDirection = shaderList[0].GetDirectionLocation();
			uniformDiffuseIntensity = shaderList[0].GetDiffuseIntensityLocation();
			uniformEyePosition = shaderList[0].GetEyePositionLocation();
			uniformSpecularIntensity = shaderList[0].GetSpecularIntensityLocation();
			uniformShininess = shaderList[0].GetShininessLocation();

		}
	}
}