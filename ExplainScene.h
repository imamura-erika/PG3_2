#pragma once

#include "IScene.h"

// タイトルシーン
class ExplainScene :public IScene {
public:
	void Init() override;
	void Update(char* keys, char* preKeys) override;
	void Draw() override;
};