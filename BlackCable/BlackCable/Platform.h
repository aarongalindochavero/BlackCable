#pragma once
#include <string>
#include "GameState.h"

class GameState;

class Platform
{
private:
	int width;
	int height;
public:
	Platform(std::string name);
	~Platform();
	void RenderClear();
	void RenderPresent();
	void CheckEvent(GameState* obj, bool (GameState::* f)(int));

};