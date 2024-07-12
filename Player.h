#pragma once
#include "Novice.h"

class Player {
private:
	int pos_x;
	int pos_y;
	int speed_;

public:
	Player(); // コンストラクタ

	void Init();
	void Update();
	void Draw();

	// 移動関数
	void MoveLeft(); // 左移動
	void MoveRight(); // 右移動
};