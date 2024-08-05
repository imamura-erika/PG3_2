#pragma once

#include "IScene.h"

// クリアシーン
class GameoverScene :public IScene {
public:
	void Init() override;
	void Update(char* keys, char* preKeys) override;
	void Draw() override;
};