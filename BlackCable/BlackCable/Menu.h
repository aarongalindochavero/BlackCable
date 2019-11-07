#pragma once
#include "BCE/GameState.h"
#include "BCE/GameStateManager.h"
#include "BCE/Mesh.h"
#include "BCE/Shader.h"
#include "BCE/Camera.h"
#include "BCE/CubeModel.h"
#include "BCE/PlaneModel.h"
#include "BCE/ShaderManager.h"
#include<vector>
class Menu : public GameState
{
private:
	Platform* platform;
	GameStateManager* manager;
	ShaderManager* shaderManager;
	Camera camera;
	CubeModel *cube;
	PlaneModel* plane;
public:
	Menu();
	~Menu();
	void Init() override;
	void Draw() override;
	bool Input(std::map<int, bool> keys) override;
	bool MouseInput(int x, int y);
	void Update() override;
	void Close() override;

};