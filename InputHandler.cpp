#include "InputHandler.h"
#include <Novice.h>

// コンストラクタ
InputHandler::InputHandler() :pressKeyA_(nullptr), pressKeyD_(nullptr) {}

// デストラクタ
InputHandler::~InputHandler()
{
}

// 割り当て Aキー左移動
void InputHandler::AssignMoveLeftCommand2PressKeyA()
{
	ICommand* command = new MoveLeftCommand();
	this->pressKeyA_ = command;
}

// 割り当て Dキー右移動
void InputHandler::AssignMoveRightCommand2PressKeyD()
{
	ICommand* command = new MoveRightCommand();
	this->pressKeyD_ = command;
}

// 入力処理
ICommand* InputHandler::HandleInput()
{
	if (Novice::CheckHitKey(DIK_A)) { // Aキー左移動
		return pressKeyA_;
	}
	if (Novice::CheckHitKey(DIK_D)) { // Dキー右移動
		return pressKeyD_;
	}

	return nullptr; // 何のコマンドも実行しない場合
}