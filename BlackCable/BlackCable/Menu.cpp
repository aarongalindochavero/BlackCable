#include "Menu.h"
#include<iostream>
#include <glm.hpp>
#include <gtc\matrix_transform.hpp>
#include <gtc\type_ptr.hpp>



Menu::Menu()
{

}

Menu::~Menu()
{
}

void Menu::Init()
{
	std::cout << " Menu Init" << std::endl;
	this->platform = Platform::GetPtr();
	this->manager = GameStateManager::getPtr();
	shaderManager = ShaderManager::getPtr();
	camera = Camera(glm::vec3(-1.4f, 0.0f, -1.6f), glm::vec3(0.0f, 1.0f, 0.0f), 0.0f, 0.0f, 55.0f, 0.1f);
	shaderManager->initShader(&camera);
	cube = new CubeModel();
	cube->Init();
	plane = new PlaneModel();
	plane->Init();
}

void Menu::Draw()
{
	platform->RenderClear();
	shaderManager->draw();
	cube->Draw();
	plane->Draw();
	platform->RenderPresent();
}

bool Menu::MouseInput(int x, int y, bool leftbutton)
{
	if(x != -1 || y != -1)
		camera.mouseControl(x, y);

	return false;
}

bool Menu::Input(std::map<int, bool> keys)
{
	camera.keyControl(keys, platform->GetDeltaTime());
	//std::cout<<camera.getCameraPosition().x<<"**" << camera.getCameraPosition().y << "**" << camera.getCameraPosition().z<<std::endl;
	return false;
}

void Menu::Update()
{

}

void Menu::Close()
{
	std::cout << " Close Init" << std::endl;
}