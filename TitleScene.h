#pragma once

#include "IScene.h"

// タイトルシーン
class TitleScene :public IScene {
public:
	void Init() override;
	void Update(char* keys, char* preKeys) override;
	void Draw() override;
};