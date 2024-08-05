#pragma once

#include "IScene.h"

// ステージシーン
class StageScene :public IScene {
public:
	void Init() override;
	void Update(char* keys, char* preKeys) override;
	void Draw() override;
};