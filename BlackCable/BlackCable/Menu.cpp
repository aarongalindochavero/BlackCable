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
	camera = Camera(glm::vec3(-12.0f, 0.0f, 0.0f), glm::vec3(0.0f, 1.0f, 0.0f), 0.0f, 0.0f, 55.0f, 0.5f);
	cube = new CubeModel();
	cube->Init();
}

void Menu::Draw()
{
	platform->RenderClear();
	glm::mat4 projection = glm::perspective(45.0f, (float)platform->GetWidth() / platform->GetHeight(), 0.1f, 100.0f);
	glm::mat4 model(1);
	cube->Draw(projection, camera);


	platform->RenderPresent();
}

bool Menu::MouseInput(int x, int y)
{
	return false;
}

bool Menu::Input(std::map<int, bool> keys)
{


	camera.keyControl(keys, platform->GetDeltaTime());
	///camera.mouseControl(0, 0);


}

void Menu::Update()
{

}

void Menu::Close()
{
	std::cout << " Close Init" << std::endl;
