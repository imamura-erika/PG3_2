#pragma once

#include "ICommand.h"

// 入力を取りまとめるクラス
class InputHandler {
public:
	InputHandler(); // コンストラクタ
	~InputHandler(); // デストラクタ
	ICommand* HandleInput(); // 入力処理

	// キーの割り当て（アサイン）
	void AssignMoveLeftCommand2PressKeyA();
	void AssignMoveRightCommand2PressKeyD();

private:
	ICommand* pressKeyA_;
	ICommand* pressKeyD_;
};