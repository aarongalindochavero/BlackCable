#pragma once
#include "BCE/GameState.h"
#include "BCE/GameStateManager.h"

class Menu : public GameState
{
private:
	Platform* platform;
	GameStateManager* manager;
public:
	Menu();
	~Menu();
	void Init(Platform* platform, GameStateManager* manager) override;
	void Draw() override;
	bool Input(int keyInput) override;
	void Update() override;
	void Close() override;
};