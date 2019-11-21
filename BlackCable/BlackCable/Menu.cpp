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
	enemy = new Model();
	enemy->LoadModel("Assets/Models/pina_pose.obj");
	enemy->AddTexture("pina.png");
	enemy->AddTexture("pina_normal.png");

	std::vector<std::string> skyboxFaces;
	skyboxFaces.push_back("Assets/Textures/Skybox/cupertin-lake_rt.tga");
	skyboxFaces.push_back("Assets/Textures/Skybox/cupertin-lake_lf.tga");
	skyboxFaces.push_back("Assets/Textures/Skybox/cupertin-lake_up.tga");
	skyboxFaces.push_back("Assets/Textures/Skybox/cupertin-lake_dn.tga");
	skyboxFaces.push_back("Assets/Textures/Skybox/cupertin-lake_bk.tga");
	skyboxFaces.push_back("Assets/Textures/Skybox/cupertin-lake_ft.tga");

	skybox = Skybox(skyboxFaces);
}

void Menu::Draw()
{
	platform->RenderClear();
	
	skybox.Draw(shaderManager->GetViewMatrix(), shaderManager->GetProjectionMatrix());
	shaderManager->draw();
	cube->Draw();
	plane->Draw();
	enemy->RenderModel();
	
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
	return false;
}

void Menu::Update()
{

}

void Menu::Close()
{
	std::cout << " Close Init" << std::endl;
}