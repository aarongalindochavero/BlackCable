#pragma once
#include "Platform.h"
#include <map>

class Platform;
class GameStateManager;

class GameState
{
public:
	virtual void Init(Platform* platform, GameStateManager* manager) = 0;
	virtual void Draw() = 0;
	virtual bool Input(std::map<int, int> keys) = 0;
	virtual bool MouseInput(int x,int y) = 0;
	virtual void Update() = 0;
	virtual void Close() = 0;
};