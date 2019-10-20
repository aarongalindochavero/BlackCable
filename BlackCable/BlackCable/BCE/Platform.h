#pragma once
#include <string>
#include "GameState.h"
#include <GL\glew.h>
#include <GLFW\glfw3.h>
#include<map>
class GameState;

class Platform
{
private:
	int width;
	int height;
	std::string name;

	GLFWwindow* mainWindow;
	GLint bufferWidth, bufferHeight;
	float deltaTime{ 0 };
	float lastTime{ 0 };
private:
	void init();	
	Platform(std::string name);
	~Platform();
	static Platform *ptr;
public:
	static Platform * GetPtr();

	void RenderClear();
	void RenderPresent();
	void CheckEvent(GameState* obj, bool (GameState::* keyboard)(std::map<int, int>), bool (GameState::* mouse)(int, int));
	int GetWidth();
	int GetHeight();
	float GetDeltaTime();
public:
	static GameState * obj;
	static bool (GameState::* keyboard)(std::map<int, int>);
	static std::map<int, int> keys;
private:
	static void HandleKeys(GLFWwindow* window, int key, int code, int action, int mode);
	static void handleMouse(GLFWwindow* window, double xPos, double yPos);
};